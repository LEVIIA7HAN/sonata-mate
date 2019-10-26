#include "pitches.h"
#include <Wire.h>
#include "rgb_lcd.h"

const int potentiometer = A0; //assigns potentiometer to pin A0
const int FULL_ANGLE = 300; //signifies the angle that the potentiometer can reach max
const int ADC_REF = 5; //voltage
const int GROVE_VCC = 5; //ground
const int button = 7; //assigns button to pin 7
const int buzzer = 3; //assigns buzzer to pin 3

//screen rgb
rgb_lcd lcd;
const int red = 255;
const int green = 0;
const int blue = 255;

//notes array
int notes[] = {
  NOTE_B0,NOTE_C1,NOTE_D1,NOTE_E1,NOTE_F1,NOTE_G1,NOTE_A1,
  NOTE_B1,NOTE_C2,NOTE_D2,NOTE_E2,NOTE_F2,NOTE_G2,NOTE_A2,
  NOTE_B2,NOTE_C3,NOTE_D3,NOTE_E3,NOTE_F3,NOTE_G3,NOTE_A3
  };

//sets initial tone to 0? idk what the fuck this does lol
int Tone = 0;
int speakerPine = 2;

//assigns input/output values to components
void setup() {
  pinMode(potentiometer, INPUT);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.setRGB(red, green, blue);
  
  lcd.print("test pogU");
  delay(1000);
}

void loop() {
  lcd.setCursor(0,1);
  lcd.print(millis()/1000);
  
  int sensorValue = analogRead(A0);
  int pitch = sensorValue/49;
  delay(100);
  
  int btn = digitalRead(button);
  digitalWrite(buzzer, btn);
  delay(10);
}
