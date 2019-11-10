# NespressoAutomation
Automating Nespresso U-Series

The goal with this project is to automate the Nespresso U coffee machine
to work completely hands free, making espresso by voice command.






There are several different "components" in this project:

1. 3D design, meant for 3D printing, the main items are:  
    * A stack which contains the capsules - the current "best" design can hold 6 capusles and works great with 3rd party capsules.
    * A capsule "selector" arm which drops capsules one at a time
    * A capsule door opener which moves the capsule door back and forth 
    
2. Electronics:
    * An arduino uno - [link](http://www.aliexpress.com/item/32697443734.html?spm=a2g0o.productlist.0.0.55373bd1GMjJR0&algo_pvid=3ab682ee-7a86-48f4-b2ac-6689dd6e30dd "Arduino Uno With USB") ~ 3$
    * A stepper driver board - [link](https://www.aliexpress.com/item/32909152477.html?spm=a2g0o.productlist.0.0.59a67d0cHCASpA "L293D Motor Shield") ~ 1.25$
    * A CD ROM Stepper - can be removed from any old CD ROM Drive, one can be bought on aliexpress or ebay but IIRC it needs a travel of 50mm ~ 2$
    * A 28byj-48 "Modified to be bipolar" - [link](http://www.aliexpress.com/item/32896006818.html?spm=a2g0o.productlist.0.0.786b6e4eyxfZal "28byj-48") ~ 1.5$
    * A Sonoff Smart switch - [link](http://www.aliexpress.com/item/32877725098.html?spm=a2g0o.productlist.0.0.44432afdtdHAVP "Sonoff Smart Switch") ~ 4.5$
    
3. Software:
    * A short arduino 'script' making coffee and then doing nothing forever.
    I have plans to record the number of times coffee has been made and writing
    it to EEPROM but writing to the same location in EEPROM wears it out quickly
    so I'm trying to find a different elegant solution for easy read and write.
    
    
    
    
# Improvements - Suggestions are welcome
* I tried using a NodeMCU (wifi enabled) to trigger the arduino to make coffee so I could have MQTT (IFTTT Integration) but had trouble with the logic level shifting, it would work when it received the activation command but also when I just touched the USB port and sometimes randomly without any noted change in IFTTT so it was a connection issue with the arduino and the NodeMCU.
