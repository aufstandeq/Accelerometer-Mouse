/**************************************************************************/
/*
 * @file    accelerometer.ino
 * @author  Daniel Horton
 * @website http://danielhorton.com
 * @license GNU General Public License v3.0
 * 
 * This file is focused on initalizing the MMA8451 chip to obtain current
 * movement information. Using this information we will move the mouse
 * around the computer screen and manage key actions based on particular 
 * movements
 * 
 * V1.0 - First Release 27 Dec 2018
 */
/**************************************************************************/
#include <Wire.h>               // I2C Library
#include <Adafruit_MMA8451.h>   // Accelerometer library
#include <Adafruit_Sensor.h>    // Adafruit sensor library
#include <ProTrinketMouse.h>    // Pro Trinket V-USB mouse emulator
#define  DEBUG  1               // Set to 1 for serial console debugging, 0 otherwise

// Constants
Adafruit_MMA8451 accelerometer = Adafruit_MMA8451();  // Create an accelerometer object

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
