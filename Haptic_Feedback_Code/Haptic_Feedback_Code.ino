#include <Wire.h>
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;


 int motor1 = 5;
 int motor2 = 3;
 //this isa comment

void setup() {
  Serial.begin(9600);
  Serial.println("DRV test");
  drv.begin();

  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
 
  drv.selectLibrary(1);
  
  // I2C trigger by sending 'go' command 
  // default, internal trigger when sending GO command
  drv.setMode(DRV2605_MODE_INTTRIG); 
}

uint8_t effect = 1;

void loop() {
  Serial.print("Effect #"); Serial.println(effect);

  digitalWrite(motor1, HIGH);

  // set the effect to play
  drv.setWaveform(0, 47);  // play effect 
  drv.setWaveform(1, 0);       // end waveform

  // play the effect!
  drv.go();

  // wait a bit
  delay(300);

  digitalWrite(motor1, LOW);

 
  
  digitalWrite(motor2, HIGH);
  
  // set the effect to play
  drv.setWaveform(0, 47);  // play effect 
  drv.setWaveform(1, 0);       // end waveform

  // play the effect!
  drv.go();

  // wait a bit
  delay(500);

  digitalWrite(motor2, LOW);

  
  
}
