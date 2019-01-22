/**************************************************************************/
/*
   @file    accelerometer.ino
   @author  Daniel Horton
   @website http://danielhorton.com
   @license GNU General Public License v3.0

   This file is focused on initalizing the MMA8451 chip to obtain current
   movement information. Using this information we will move the mouse
   around the computer screen and manage key actions based on particular
   movements

   V1.0 - First Release 27 Dec 2018
*/
#include <Wire.h>               // I2C Library
#include <Adafruit_MMA8451.h>   // Accelerometer library
#include <Adafruit_Sensor.h>    // Adafruit sensor library

#define  DEBUG  1               // Set to 1 for serial console debugging, 0 otherwise
#define  ARRAY_SIZE 150         // Sample Size - 150 seems to smooth well         

Adafruit_MMA8451 accelerometer = Adafruit_MMA8451();  // Create an accelerometer object

/**************************************************************************/
int currentLocationInArray = 0;
int endLocationInArray = (ARRAY_SIZE - 1);

int xSampleDataSet[ARRAY_SIZE];
int ySampleDataSet[ARRAY_SIZE];
int zSampleDataSet[ARRAY_SIZE];

void setup() {
  Serial.begin(9600);                         // Turn on Serial Comm for Debug

  accelerometer.begin();                      // Initiate the Chip
  accelerometer.setRange(MMA8451_RANGE_2_G);  // Set the range for the chip
}

void loop() {
  if (currentLocationInArray == endLocationInArray ? currentLocationInArray = 0 : currentLocationInArray = currentLocationInArray + 1)

  accelerometer.read();                                       // gather the current values from chip

  xSampleDataSet[currentLocationInArray] = accelerometer.x;   // Add the new value to the array
  ySampleDataSet[currentLocationInArray] = accelerometer.y;
  zSampleDataSet[currentLocationInArray] = accelerometer.z;
  
  Serial.print("x: "); Serial.print(calculateRunningAverage(xSampleDataSet));
  Serial.print("  y: "); Serial.print(calculateRunningAverage(ySampleDataSet));
  Serial.print("  z: "); Serial.print(calculateRunningAverage(zSampleDataSet));
  Serial.println();

}// END LOOP



/**************************************************************************/
/*
   Calculate the total value on the array and
   divide by the size of the array to get an
   average.
*/
/**************************************************************************/
int calculateRunningAverage(int m_passedArray[]) {
  int sum = 0;
  for (int i = 0; i < ARRAY_SIZE; i = i + 1) {
    sum += m_passedArray[i];
  }
  return sum / ARRAY_SIZE;
}
