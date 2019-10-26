#include "pitches.h"
#include <Wire.h>
#include "rgb_lcd.h"

const int potentiometer = A0; //assigns potentiometer to pin A0
const int angle = 300; //signifies the angle that the potentiometer can reach max
const int button = 8; //assigns button to pin 8
const int buzzer = 4; //assigns buzzer to pin 4
const int led = 3; //assigns led to pin 3

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
  pinMode(led, OUTPUT);

  //initiates lcd screen
  lcd.begin(16, 2); //initialize 16x2 screen
  lcd.setRGB(red, green, blue); //initialize rgb
  lcd.print("test pogU"); //prints on first line
  delay(1000); //1 second delay until ON
}

void cFade (unsigned char color){
  for (int i = 0; i < 255; i++){
    lcd.setPWM(color, i);
    delay(10);
    }
    delay(100);
  }

void loop() {
  
  lcd.setCursor(0,1);//changes the place to print
  lcd.print(millis()/1000); //changeable lcd value

  int sensorValue = analogRead(A0); //puts the value of potent onto varaible sensorValue 
  int pitch = sensorValue/49; //pitch is sensorValue divided by 49 to get 6 pitches?
  
  int btn = digitalRead(button); //reads button input and puts it into variable btn
  digitalWrite(buzzer, btn); //when the button is pressed, buzzer goes off
  digitalWrite(led, btn); //when button is pressed, led turns on
  delay(10);

  cFade(REG_RED);
  cFade(REG_GREEN);
  cFade(REG_BLUE);
  
}
