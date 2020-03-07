#include <UTFT.h>
#include <button.h>
#include <joystick.h>

UTFT myGLCD(ITDB32S,38,39,40,41);

joystick joystick(56,54,55);

button MENU(57);
button A(58);
button B(59);

const int BUZZER = 8;

void setup(){
  Serial.begin(9600);
  pinMode(BUZZER,OUTPUT);
  myGLCD.InitLCD();
  myGLCD.clrScr();
}

void loop(){
}
