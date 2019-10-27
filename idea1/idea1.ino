#include <Wire.h>
#include "rgb_lcd.h"

const int pitchKnob = A0; //assigns potentiometer to pin A0; changes pitch/note 300 divided by 7, float value degrees per note, display note on screen
const int volKnob = A1; //assigns potentiometer to pin A1; changes volume, divide by 3 to get an int, not float between 0-100 for volume values.
const int octaveKnob = A2; //assigns potentiometer to pin A2; changes octave, 300 degrees divided by 100 to get 0-3 degrees per octave, 0-1 for lower, 1.1 - 2 for mid, 2.1 - 3 for max oct
const int button = 8; //assigns button to pin 8
const int buzzer = 4; //assigns buzzer to pin 4
const int led = 3; //assigns led to pin 3

const int angle = 300; //signifies the angle that the potentiometer can reach max

int pitchVal = 0;
int volumeVal = 0;
int octaveVal = 0; //variable to store value of Octave,

//screen rgb
rgb_lcd lcd;

//music note pixel art
byte musicNote[8] = {
    0b00001,
    0b00001,
    0b00001,
    0b00001,
    0b00001,
    0b01111,
    0b11111,
    0b01110
};

//assigns input/output values to components
void setup() {
  //ins
  pinMode(pitchKnob, INPUT);
  pinMode(volKnob, INPUT);
  pinMode(octaveKnob, INPUT);
  pinMode(button, INPUT);

  //outs
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  //initiates lcd screen
  lcd.begin(16, 2); //initialize 16x2 screen
  lcd.print("<3"); //prints on first line

  #if 1
  lcd.createChar(0, musicNote);
  #endif
  lcd.setCursor(7,0);
  lcd.write((unsigned char)0);
}

void ignitionButt(){
  int btn = digitalRead(button); //reads button input and puts it into variable btn
  digitalWrite(buzzer, btn); //when the button is pressed, buzzer goes off
  digitalWrite(led, btn); //when button is pressed, led turns on
  delay(1);
  }

void firstDisplay(){
  lcd.setCursor(0,1);//changes the place to print
  lcd.print(millis()/1000); //changeable lcd value
  }

void porygon(unsigned char color){
  for (int i = 0; i < 255; i++){
    lcd.setPWM(color, i);
    }
  }

void loop() {
  ignitionButt(); //button for moosic
  firstDisplay(); //displays static nonmoving text
  porygon(REG_RED); //EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY 
  porygon(REG_GREEN); //EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY 
  porygon(REG_BLUE); //EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY 
  
}
