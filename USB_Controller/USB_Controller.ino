#include <PS3USB.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif
  
  USB Usb;
PS3USB PS3(&Usb); 
bool printAngle;
uint8_t state = 0;
int XMO = 13;
int YMO = 11;
int RMO = 12;
int ZMO = 10;

 
void setup() 
{

  pinMode(YMO, OUTPUT);
  
  Serial.begin(115200);
  #if !defined(__MIPSEL__)
    while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  #endif
  if (Usb.Init() == -1) {
    Serial.print(F("\nlibrary Failed to start "));
  while (1); //halt
    }
    Serial.print(" \nPS3 USB Library Started. ");

}


void Joysticks() 
{
     
   if (PS3.getAnalogHat(LeftHatX) > 137 || PS3.getAnalogHat(LeftHatX) < 117 || PS3.getAnalogHat(LeftHatY) > 137 || PS3.getAnalogHat(LeftHatY) < 117) {
       Serial.print(F("\nLeftHatX:"));
      Serial.print(PS3.getAnalogHat(LeftHatX));
      Serial.print(F("\nLeftHatY:"));
      Serial.print(PS3.getAnalogHat(LeftHatY));
   }
     if (PS3.getAnalogHat(RightHatX) > 137 || PS3.getAnalogHat(RightHatX) < 117 || PS3.getAnalogHat(RightHatY) > 137 || PS3.getAnalogHat(RightHatY) < 117) {
        Serial.print(F("\nRightHatX: "));
        Serial.print(PS3.getAnalogHat(RightHatX));
        Serial.print(F("\nRightHatY: "));
        Serial.print(PS3.getAnalogHat(RightHatY));
  }

}



void Buttons()
{

      if (PS3.getButtonClick(PS))
    {
     Serial.print(F("\r\nPS"));
    }
    if (PS3.getButtonClick(TRIANGLE))
    {
     Serial.print(F("\r\nTraingle: "));
     digitalWrite(YMO, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(10);              // wait for a second
     digitalWrite(YMO, LOW);    // turn the LED off by making the voltage LOW 
    }   
    if (PS3.getButtonClick(CIRCLE))
    {
     Serial.print(F("\r\nCircle"));
    }
    if (PS3.getButtonClick(CROSS))
    {
      Serial.print(F("\r\nCross"));
    }
    if (PS3.getButtonClick(SQUARE))
    {
      Serial.print(F("\r\nSquare"));
    }
    if (PS3.getButtonClick(UP)) 
    {
      Serial.print(F("\r\nUp"));
    }
    if (PS3.getButtonClick(RIGHT)) 
    {
      Serial.print(F("\r\nRight"));
    }
    if (PS3.getButtonClick(DOWN)) 
    {
      Serial.print(F("\r\nDown"));
    }
    if (PS3.getButtonClick(LEFT)) 
    {
      Serial.print(F("\r\nLeft"));
    }

    if (PS3.getButtonClick(L1))
    {
      Serial.print(F("\r\nL1"));
    }
    if (PS3.getButtonClick(L3))
    {
      Serial.print(F("\r\nL3"));
    }
    if (PS3.getButtonClick(R1))
    {
      Serial.print(F("\r\nR1"));
    }
    if (PS3.getButtonClick(R3))
    {
     Serial.print(F("\r\nR3"));
    }
    if (PS3.getButtonClick(L2))
    {
     Serial.print(F("\r\nL2")); 
    }
    if (PS3.getButtonClick(R2))
    {
     Serial.print(F("\r\nR2")); 
    }
}

void LED(int O)
{
  
}
void loop()
{
  Usb.Task();
   Joysticks();
   Buttons();
}

