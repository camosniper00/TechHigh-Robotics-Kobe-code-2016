

#include <PS3USB.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif
#include <Servo.h> // Servo Values
Servo myservo;//0: Full Forward 90: Full Stop 180: Full Reverse.
// ***!!!MOTORS WILL NOT FUNCTION IF OUT OF THE RANGE!!!***
USB Usb;
PS3USB PS3(&Usb);
//Initialize varibles to be used for PWM output pins
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
  //take button input and print to serial monitor
  myservo.attach(14);
  //Using PWM pin 14 to control Sabertooth via PS3 Control
  // take JoyStick input and out put them to the serial monitor

}
  
void Joysticks()
{
//only update values if outside the dead zone
  if (PS3.getAnalogHat(LeftHatX) > 137 || PS3.getAnalogHat(LeftHatX) < 117 || PS3.getAnalogHat(LeftHatY) > 137 || PS3.getAnalogHat(LeftHatY) < 117) {
    Serial.print(F("\nLeftHatX:"));
    Serial.print(PS3.getAnalogHat(LeftHatX));
    Serial.print(F("\nLeftHatY:"));
    Serial.print(PS3.getAnalogHat(LeftHatY));
    analogWrite(6, PS3.getAnalogHat(LeftHatY));
    
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
//Only update if the button is pressed
  if (PS3.getButtonClick(PS))
  {
    Serial.print(F("\r\nPS"));
  }
  if (PS3.getButtonClick(TRIANGLE))
  {
    Serial.print(F("\r\nTraingle: "));
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
//Read the angle of the controller
void tilt()
{
//set up a dead zone to stop contstant updates
  if (PS3.getAngle(Pitch) > 185 || PS3.getAngle(Pitch) < 175)
  {
    Serial.print(F("\r\nPitch: "));
    Serial.print(PS3.getAngle(Pitch));
  }
  if (PS3.getAngle(Roll) > 185 || PS3.getAngle(Roll) < 175)
  {
    Serial.print(F("\r\nPitch: "));
    Serial.print(PS3.getAngle(Roll));
  }
}
void controlForward()
{
  while (PS3.getAnalogHat(LeftHatX) < 117 && PS3.getAnalogHat(LeftHatX) >= 59){ //One half full forward.
    myservo.write(60);
    
    }
  while (PS3.getAnalogHat(LeftHatX) <= 58 && PS3.getAnalogHat(LeftHatX) >=0){ //full forward.
    myservo.write(30);
  
    }
  while (PS3.getAnalogHat(LeftHatX) <= 196&& PS3.getAnalogHat(LeftHatX) > 137){ //One half reverse.
    myservo.write(76);
    
    }
  while (PS3.getAnalogHat(LeftHatX) <= 255 && PS3.getAnalogHat(LeftHatX) >= 197){ //full reverse.
    myservo.write(160);
 
    }
  }
//call alll of the functions in a never ending loop
void loop()
{
  Usb.Task();
  controlForward();
  Joysticks();
  Buttons();
  tilt();
}


