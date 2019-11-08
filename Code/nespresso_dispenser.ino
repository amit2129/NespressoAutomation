

/*
 * Author: Amit Matityahu
 * Nespresso Coffee Machine Automator
 * This relatively short piece of code 
 * is made to run once (the arduino is powered on
 * performs the task and is powered off once it is done)
 * additionally there's a counter which is writen to eeprom
 * counting the number of times the machine has been activated
 * (made coffee)
*/
#include <AFMotor.h>
#include <EEPROM.h>

struct Statistics{
  int coffeeMade;
};



int eeAddress = 0;   //Location we want the data to be put.


int CAPSULE_REV = 4076/2;
int DOOR_REV = 20;
double door_calibration = 460;


AF_Stepper doorStepper(20, 2);
AF_Stepper capsuleStepper(48, 1);
byte curr_low;
byte curr_high;
int res;
const int addr = 0;
const byte BITS_PER_BYTE = 8;
const int make_coffee = 2;
volatile bool doAction = false;



void makeCoffee();

int data;

Statistics stats = {
  0  
};
void setup() {

  pinMode(make_coffee, INPUT);
  //attachInterrupt(digitalPinToInterrupt(make_coffee), make_coffee_handler, FALLING);
  Serial.begin(9600);
  //setting speed for both motors
  capsuleStepper.setSpeed(400);
  doorStepper.setSpeed(1300);
  capsuleStepper.release();
  doorStepper.release();
  makeCoffee();


 
  EEPROM.put(eeAddress, stats);
  
}

void loop() {
//  doAction = !digitalRead(make_coffee);
//  Serial.println(doAction);
//  Serial.print(" ");
//  if (doAction){
//    makeCoffee();
//    doAction = false;
//  }
}

void makeCoffee(){
  //Serial.println("making coffee");
  doorStepper.step(door_calibration,
  FORWARD, INTERLEAVE);
  capsuleStepper.step(CAPSULE_REV/6, FORWARD, DOUBLE);
  doorStepper.step(door_calibration, BACKWARD, INTERLEAVE);
  capsuleStepper.step(CAPSULE_REV/7 + 20, BACKWARD, DOUBLE);
  capsuleStepper.release();
  doorStepper.release();
  delay(5000);
  stats.coffeeMade++;
  EEPROM.put(eeAddress,stats);
  
}

void make_coffee_handler(){
  doAction = true;
}
