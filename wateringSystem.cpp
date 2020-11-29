#include "mbed.h"
#include "rtos.h"
#include "Servo.h"

Servo myServo(p21);
DigitalOut myLight(p18);
Serial blue(p9, p10);
AnalogIn waterLvl(p20);
Serial pc(USBTX, USBRX);
Timer water, light;

volatile bool running = true;   //Bool for whether the water level has dropped
volatile bool watering= true;   //Bool for whether the device is watering or not
volatile bool lighting = true;  //Bool for whether the lighting is on or not

//This function is used to release the water for 30 seconds every day
void releaseWater(const void * arg)
{
    water.start(); //Start the water timer
    while(1) {
        int counter=0; //Set the base counter to 0
        myServo = 1 //Open the servo
        while(watering) { //Run until the timer has reached 30
            if(water.read()>30.0) { //Once the timer reaches 30 flip the bool
                watering=!watering;
            }
        }
        water.clear(); //Reset the timer
        myServo = 0; //Close the servo
        while(!watering) { //While the device has not reached the time limit
            if(water.read()>1800.0) { //If the timer has not reached 30 minutes continue 
                counter++;  //Increment the counter
                water.clear(); //Clear the timer
            }
            if(counter == 48) { //If there have been 48 30 minute intervals(1 day) 
                watering = !watering; //Flip the watering bool
            }
        }
        water.clear(); //Clear the timer
    }
}

//This function is responsible for flipping the light on and off every 12 hrs
void flipLight(const void * arg)
{
    light.start(); //Start the light timer
    while(1) { //Loop runs forever
        int counter = 0; //Define a time counter
        myLight = 1 //Turn the light on
        while(lighting) { //Run this loop for 12 hrs
            if(light.read()>1800.0) { //If the timer reaches 30 minutes reset and increment counter
                counter++;
                light.clear();
            }
            if(counter == 24) { //If the counter becomes 24 flip the bool and exit the loop
                lighting = false;
            }
        }
        light.clear(); //Clear the timer
        myLight = 0; //Turn off the light
        while(!lighting) { //Run this loop for 12 hrs
            if(light.read()>1800.0) { //If the timer reaches 30 minutes increment the counter and reset the timer
                counter++; 
                light.clear();
            }
            if(counter == 24) { //If the counter reaches 24 reset the loop
                lighting = true;
            }
        }
        light.clear();  //Clear the timer
    }
}

//This function is for determining the water level and sending the email
void waterLevel(const void * arg)
{
    while(1) { //Run this loop forever
        float water = waterLvl.read(); //Read the water level
        if(waterLvl<0.3) {  //If the water level is less than 0.3
            running = false;    //Flip the bool for whether the water level is high enough
            pc.printf("The planter is out of water!!\n\r"); //Send the info to the pi to print out
        }
        while(!running) { //If the water level went below the threshold wait in this loop until it is filled
            if(waterLvl > 0.3) {    //If water level rose return back to the main loop
                running = true;
            }
        }
        Thread::wait(2000); //Check the water level every 2 seconds
    }
}


int main()
{
    myServo=0;  //Default the servo to closed
    myLight = 0;//Default the light to off
    Thread water(waterLevel);   //Spawn a thread with the waterlevel function
    Thread light(flipLight);    //Spawn a thread for the flipping of the light
    Thread addWater(waterLevel);//Spawn a thread that adds water every day
    while(1) {
        while(running) {  
            Thread::wait(200);
        }
        myServo = 0; //Make sure the servo closes if the water level drops below the threshold
    }
}
