# automatic_planter
Project for ECE4180 which involves creating an automated watering system 

The goal for this project is to remove the need to water indoor plants and move them to provide them with lighting. 

The project can be broken down into 5 different sub-systems.
  1. Watering System
  2. Lighting System
  3. Timer System
  4. Email System
  5. Bluetooth System --Optional
In the sections below I will elaborate on the functionality of the different systems.

----Watering System----
The water system is controlled by an mBed and a servo motor that is attached to a valve that anyone can purchase from a home goods store. The valve is attached to a hose and a large container of water. The watering system has an ardunio water level sensor that it uses to determine how much water is remaining inside of the container.

----Lighting System----
The lighting system is controlled by an mBed and a high power relay. The mBed is used to turn the light on and off after approximately 12 hrs of on time(the value of how long the light should be on varies depending on what plant you have). I went out and purchased a high-end indoor growing lamp on amazon but I suppose any average light could be used.

----Timer System----
The timer system is intergal in automating the watering and lighting processes. This system runs on the mbed and is used to activate the watering and lighting periodically. The watering system goes off once every 2-3 days while the lighting timer resets roughly once every day.

----Email System----
The email system will tie in with the watering system. The email system is set up on a Raspberry Pi and it uses some basic functions that are a part of node red. I configured the mBed to constantly read the water level sensor. If the sensor alerts the mBed that the water has passed the threshold, then the mBed sends a signal out on one of it's pins. The mBed output is tied in to the input into the Pi. The Pi's node red program will be set up to send an email to an email address whenever one of its input pins goes high.

----Bluetooth System----
The bluetooth system is not necessary to actually implement and design the automatic plant watering system, but it has been added as an easy means of controlling the above systems so that I can properly demo each of the different components. In reality the device will be running using the timer system instead of the bluetooth system but for the extent of this project I will attach the code for both different versions of the project.
