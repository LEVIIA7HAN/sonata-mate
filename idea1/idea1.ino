#include <Wire.h>
#include "pitches.h"
#include "rgb_lcd.h"

const int pitchKnob = A0; //assigns potentiometer to pin A0; changes pitch/note 1023 divided by x to get 7, float value degrees per note, display note on screen
const int volumeKnob = A1; //assigns potentiometer to pin A1; changes volume, divide 1023 by x to get 3 to get an int, not float between 0-100 for volume values.
const int octaveKnob = A2; //assigns potentiometer to pin A2; changes octave, 1023 degrees divided by 10.23 to get 100 to get 0-3 degrees per octave, 0-1 for lower, 1.1 - 2 for mid, 2.1 - 3 for max oct
const int button = 8; //assigns button to pin 8
const int buzzer = 4; //assigns buzzer to pin 4
const int led = 3; //assigns led to pin 3

const int firstNote = 0;
const int lastNote = 7;

int pitchVal = 0; //variable to store value of pitch
int pitchPoten = 0; //variable to store value of potentiometer

int volumeVal = 0; //variable to store value of volume
int volumePoten = 0; //variable to store value of potentiometer

int octaveVal = 0; //variable to store value of octave
int octavePoten = 0; //variable to store value of potentiometer

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

int notes[] = {
  NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3,
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5
};

//assigns input/output values to components
void setup() {
  Serial.begin(9600); // initiates serial connection @ 9600 bits baud rate
  //ins
  pinMode(pitchKnob, INPUT);
  pinMode(volumeKnob, INPUT);
  pinMode(octaveKnob, INPUT);
  pinMode(button, INPUT);

  //outs
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  //initiates lcd screen
  lcd.begin(16, 2); //initialize 16x2 screen

#if 1
  lcd.createChar(0, musicNote);
#endif
  lcd.setCursor(7, 0);
  lcd.write((unsigned char)0);
}

void ignitionButt() {
  int btn = digitalRead(button); //reads button input and puts it into variable btn
  digitalWrite(buzzer, btn); //when the button is pressed, buzzer goes off
  digitalWrite(led, btn); //when button is pressed, led turns on
  delay(1);
}

/*void firstDisplay() {
  lcd.setCursor(0, 1); //changes the place to print
  lcd.print(millis() / 1000); //changeable lcd value
  }*/

void porygon(unsigned char color) {
  for (int i = 0; i < 255; i++) {
    lcd.setPWM(color, i);
  }
}

void changePitch() {
  pitchPoten = analogRead(pitchKnob); //reads the analogIn value
  pitchVal = map(pitchPoten, 0, 1023, firstNote, lastNote); //maps the ranges
  
  //test write
  Serial.print("sensor");
  Serial.println(pitchVal);
  /*
  if (pitchVal == 0 || pitchVal <= 1) {
    Serial.print("sensor = ");
    Serial.print(pitchVal);
    Serial.println("Note: C");

    lcd.setCursor(0, 0); //changes the place to print
    lcd.print("Note: C"); //prints on first line
  } else if (pitchVal > 1 && pitchVal <= 2) {
    Serial.print("sensor = ");
    Serial.print(pitchVal);
    Serial.println("Note: D");

    lcd.setCursor(0, 0); //changes the place to print
    lcd.print("Note: D"); //prints on first line
  } else if (pitchVal > 2 && pitchVal <= 3) {
    Serial.print("sensor = ");
    Serial.print(pitchVal);
    Serial.println("Note: E");

    lcd.setCursor(0, 0); //changes the place to print
    lcd.print("Note: E"); //prints on first line
  } else if (pitchVal > 3 && pitchVal <= 4) {
    Serial.print("sensor = ");
    Serial.print(pitchVal);
    Serial.println("Note: F");

    lcd.setCursor(0, 0); //changes the place to print
    lcd.print("Note: F"); //prints on first line
  } else if (pitchVal > 4 && pitchVal <= 5) {
    Serial.print("sensor = ");
    Serial.print(pitchVal);
    Serial.println("Note: G");

    lcd.setCursor(0, 0); //changes the place to print
    lcd.print("Note: G"); //prints on first line
  } else if (pitchVal > 5 && pitchVal <= 6) {
    Serial.print("sensor = ");
    Serial.print(pitchVal);
    Serial.println("Note: A");

    lcd.setCursor(0, 0); //changes the place to print
    lcd.print("Note: A"); //prints on first line
  } else if (pitchVal > 6 && pitchVal <= 7) {
    Serial.print("sensor = ");
    Serial.print(pitchVal);
    Serial.println("Note: B");

    lcd.setCursor(0, 0); //changes the place to print
    lcd.print("Note: B"); //prints on first line
  };
  */
}

void changeVolume() {
  volumePoten = analogRead(volumeKnob); //reads the analogIn value
  volumeVal = map(volumePoten, 0, 1023, 0, 100); //maps the ranges
  analogWrite(volumeKnob, volumeVal / 10.23); //results in 0-100 for volume

  Serial.print("Volume: ");
  Serial.println(volumeVal);
}

void changeOctave() {
  octavePoten = analogRead(octaveKnob); //reads the analogIn value
  octaveVal = map(octavePoten, 0, 1023, 0, 3); //maps the ranges
  analogWrite(octaveKnob, octaveVal / 100); //results in a 0-3 for octave change

  Serial.print("Octave: ");
  Serial.println(octaveVal);
}

void loop() {
  ignitionButt(); //button for moosic
  //firstDisplay(); //displays static nonmoving text
  changePitch();
  changeVolume();
  changeOctave();
  porygon(REG_RED); //EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY
  porygon(REG_GREEN); //EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY
  porygon(REG_BLUE); //EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY EPILEPSPY

}
