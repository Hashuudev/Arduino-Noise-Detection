/*
   File Name: spy-recorder.ino
   Created on: 7-Jan-2021
   Author: Noyel Seth (noyelseth@gmail.com)
*/
/*
   Hardware Pinout Connection
   Arduino Nano        SD Pin
        5v ------------ VCC
        GND ----------- GND
        D10 ----------- CS
        D11 ----------- MOSI
        D12 ----------- MISO
        D13 ----------- SCK
  ________________________________________
   Arduino Nano         MAX9814
        3.3v ----------- VDD
        GND ------------ GND
        A0 -------------  Out
  ________________________________________
   Arduino Nano D2 pin user for Led to notify that record is in process.
*/
/*
   use Link: https://www.arduino.cc/reference/en/libraries/tmrpcm/ TMRpcm library for recording audio using MAX9814
   Recording a WAV file to an SD card is an advanced feature of the TMRpcm library so you must edit the library configuration file in order to use it.
   It simply searches the file "pcmConfig.h" using File Explorer and disables a few lines of code (then saves it).
    1. On Uno or non-mega boards uncomment the line #define buffSize 128
    2. Also uncomment #define ENABLE_RECORDING and #define BLOCK_COUNT 10000UL
*/
//NOTE:------------------ clk port must be connected to the port A5, 
//NOTE: -------------------  SDA to port A4

// LiquidCrystal_I2C library by Frank de Brabander 



#include "Wire.h"
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27,16,2);
// 0x27 is the address
// 16*2 is the size of screen
const int ledPin = 2; //pin 13 built-in led
const int soundPin = A0; //sound sensor attach to A0
int threshold = 20; //Set minimum threshold for LED lit



void setup(){
  pinMode(ledPin,OUTPUT);//set pin13 as OUTPUT
  Serial.begin(9600); //initialize serial
  lcd.init();   // initialize
  lcd.backlight();
}
void loop(){
  int value = analogRead(soundPin);//read the value of A0
  Serial.println(value);//print the value
  lcd.clear();
  lcd.setCursor(1,0);   //(C,R)
  lcd.print("Sound Sensor:");
  lcd.setCursor(4,1);   //(C,R)
  lcd.print(value);
  lcd.print(" (db)");

  if(value > threshold) //if the value is greater than 600
  {
    digitalWrite(ledPin,HIGH);//turn on the led
    delay(2000);//delay 200ms
  }
  else
  {
    digitalWrite(ledPin,LOW);//turn off the led
  }
  delay(1000);

}