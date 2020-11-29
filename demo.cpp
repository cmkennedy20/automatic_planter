/*
Written by Chris Kennedy

This code is to be used for demoing the functionality of the various components. This program allows a user to control the
lights and the servo using bluetooth commands. This allows for the various parts to be highlighted as working.

*/

#include "mbed.h"
#include "rtos.h"
#include "Servo.h"

Servo myServo(p21); //Create a servo object
DigitalOut myLight(p18);  //Create the light control signal
Serial blue(p9, p10);   //Add the bluetooth device for testing
AnalogIn waterLvl(p20);   //Add the analog in signal for the water level sensor
Serial pc(USBTX, USBRX);  //Serial pc to communicate with the pi.

volatile bool button_ready = 0;
volatile int bnum = 0;
volatile bool running = true;

//This function is attached and reads the value on the water level sensor every 2 seconds.
//If the value passes the threshold it 
void waterLevel(const void * arg)
{
    while(1) {
        float water = waterLvl.read();
        if(waterLvl<0.3) {
            running = false;
            pc.printf("The planter is out of water!!\n\r"); //Send this message through to the 
        } 
         while(!running) { //This loop runs while the container is empty
            if(waterLvl > 0.3) {
                running = true;
            }
        }
        Thread::wait(2000); 
    }
}

//Main for the test program
int main()
{
    myServo = 0; //Default the servo to closed
    myLight = 0; //Default the light to off
    Thread water(waterLevel);   //Spawn a thread with the waterlevel function
    while(1) { //This loop runs forever
        
        while(running) { //This loop runs while there is water in the container
            if (blue.getc()=='!') {
                if (blue.getc()=='B') { //button data
                    bnum = blue.getc(); //button number
                    if ((bnum=='1')) { //is a number button 1 open the servo
                        myServo = 1; //Open the servo
                    }
                    if ((bnum=='2')) { //is a number button 2 close the servo
                        myServo = 0; //Close the servo
                    }
                    if ((bnum=='3')) { //is a number button 3 turn on the light
                        myLight = 1;  //Turn off the light
                    }
                    if ((bnum=='4')) { //is a number button 4 turn off the light
                        myLight = 0;  //Turn on the light
                    }
                }
                Thread::wait(100);
            }
            Thread::wait(200);
        }
    }
}
