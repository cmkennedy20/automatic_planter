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

----------------Parts List----------------
1. ARCELI Water Level Sensor Liquid Water Droplet Depth Detection Sensor
    
    Link:https://www.amazon.com/ARCELI-Sensor-Droplet-Detection-Arduino/dp/B07BP7B9TR/ref=sr_1_3?crid=PCDUCVP4U5Z0&dchild=1&keywords=water+level+sensor+arduino&qid=1606340069&sprefix=water+level+sensor+%2Caps%2C166&sr=8-3

2. SharkBite 24632LF 45° Hose Bibb, 1/2" x 3/4", Multi Turn: 
    
    Link:https://www.amazon.com/Sharkbite-24632LF-Hose-Bibb-Multi/dp/B076FX66HG/ref=sr_1_5?dchild=1&keywords=hose+faucet&qid=1606340131&sr=8-5
    
3. 2 Kroger one gallon water bottles
    
    Link: https://www.instacart.com/landing?product_id=16380509&retailer_id=58&region_id=8209190703&mrid=34481003&utm_source=instacart_bing&utm_medium=sem_shopping&utm_campaign=ad_demand_shopping_food_ga_atlanta_bing&utm_content=accountid-146005746_campaignid-367693857_adgroupid-1212761769040901_device-c&utm_term=matchtype-e_keyword-_targetid-pla-4579397213727258_locationid-&msclkid=446529cac6db140ec48d76740845de14
    
4. Raspberry Pi 3 Model B+
    
    Link: https://www.bestbuy.com/site/raspberry-pi-3-model-b-/6339655.p?skuId=6339655&ref=212&loc=1&ref=212&loc=1&msclkid=543b2cf711a615c0ef167349deadc72f&gclid=CMT6jZnUnu0CFeKOxQIdoRQPGg&gclsrc=ds

5. MBED LPC 1768 Microcontroller
    
    Link:https://www.ebay.com/i/184461383600?chn=ps&norover=1&mkevt=1&mkrid=711-213727-13078-0&mkcid=2&itemid=184461383600&targetid=4580840328168110&device=c&mktype=&googleloc=&poi=&campaignid=403206327&mkgroupid=1235851284533770&rlsatarget=pla-4580840328168110&abcId=9300372&merchantid=51291&msclkid=5c6837ce44bd1da1f2fd68708b35bd7e
    
6. HS-422 Servo
    
    Link: https://us.redbrain.shop/search?q=Hitec+HS-422+Standard+Deluxe&utm_source=bing&utm_medium=pla&utm_campaign=395446806&msclkid=4898d3011c8f1138fa028cbfce0ba020

7. MAXSISUN 600W LED Grow Light, Full Spectrum LED Grow Lights for Indoor Plants Veg and Bloom
    
    Link:https://www.amazon.com/gp/product/B07QH4KFBQ/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&psc=1
   
8. Iot Relay - Enclosed High-power Power Relay for Arduino, Raspberry Pi, PIC or Wifi, Relay Shield
    
    Link:https://www.amazon.com/gp/product/B00WV7GMA2/ref=ppx_yo_dt_b_asin_title_o05_s00?ie=UTF8&psc=1

9. Water hose
    
    Link:https://www.grainger.com/product/423H99?cm_mmc=PPC:+MSN+PLA&gucid=N:N:PS:Paid:MS:CSM-2295:TVRYAD:20501231&s_kwcid=AL!2966!10!79508567641876!4583108078616139&ef_id=c53df92d735c13e250ada693a269d81d:G:s

10. Flex Glue: Strong Rubberized Waterproof Adhesive
    
    Link:https://www.flexsealproducts.com/product/flex-glue/?attribute_pa_size=6%20oz&utm_source=bing&utm_medium=paid&utm_term=shopping_glue_6&msclkid=11385f22fb071f32afe8009c2a95d5c7

11. Rapid Fuse: All Purpose Adhesive
    
    Link:https://www.wwhardware.com/dap-rapid-fuse-all-purpose-glue-85oz?zCountry=US&_vsrefdom=adwords&msclkid=eb7799363bf21e0f6bdac688ea481c6d&utm_source=bing&utm_medium=cpc&utm_campaign=**LP%20Shop%20-%20Adhesives,%20Sealants%20%26%20Fillers&utm_term=4575961238354552&utm_content=22084%20%7C%20DAP%20Rapid%20Fuse%20All%20Purpose%20Glue%20%7C%20%245

12. U-Bolt, Round Bend, Low Carbon Steel, Hot Dipped Galvanized, 1/2"-13, 3 in Thread Length
    
    Link: https://www.grainger.com/product/20W511?cm_mmc=PPC:+MSN+PLA&gucid=N:N:PS:Paid:MS:CSM-2295:TVRYAD:20501231&s_kwcid=AL!2966!10!79577289348264!4583176799612619&ef_id=28993bac7b911ddb81e86412a99c67e7:G:s

13. NEW 4 AA batteries 6V Plastic black Battery case AAA Power battery box
    
    Link: https://www.ebay.com/i/322567174838?chn=ps&norover=1&mkevt=1&mkrid=711-213727-13078-0&mkcid=2&itemid=322567174838&targetid=4580977766998737&device=c&mktype=&googleloc=&poi=&campaignid=403206332&mkgroupid=1238050308110012&rlsatarget=pla-4580977766998737&abcId=9300372&merchantid=51291&msclkid=9d402288c96e1c3928317d361aae81bf
    
-----Optional Unit for testing only-----
14.Adafruit Bluefruit LE UART Friend - Bluetooth Low Energy (BLE)
    Link: https://www.ebay.com/i/263049861315?chn=ps&norover=1&mkevt=1&mkrid=711-213727-13078-0&mkcid=2&itemid=263049861315&targetid=4580153133025503&device=c&mktype=&googleloc=&poi=&campaignid=403206328&mkgroupid=1224856168411808&rlsatarget=pla-4580153133025503&abcId=9300372&merchantid=51291&msclkid=66d96b0e840c180ceb0434b0549e76cf
    
-----Cost Chart-----
Number	Unit	Cost
1	Water Lvl Sensor	$4.99 
2	Water Valve	$13.61 
3	2 Water bottles	$1.78 
4	Raspberry Pi	$34.99 
5	MBED LC1768	$54.95 
6	Servo	$13.79 
7	Grow Lamp	$69.99 
8	Relay Switch	$26.95 
9	Water Hose	$12.24 
10	Flex Glue	$12.99 
11	Super Glue	$5.17 
12	U-Bolt	$12.00 
13	Battery Pack	$1.80 
14	Bluetooth Module	$22.99 
	Total	$288.24 
