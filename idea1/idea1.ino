#define ROTARY_ANGLE_SENSOR A0
#define ADC_REF 5
#define GROVE_VCC 5
#define FULL_ANGLE 300
const int button = 7;
const int buzzer = 3;

void setup() {
  Serial.begin(9600);
  pinMode(ROTARY_ANGLE_SENSOR, INPUT);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  //Dial
  float voltage;
  int sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
  voltage = (float)sensor_value * ADC_REF/1023;
  float degrees = (voltage * FULL_ANGLE)/GROVE_VCC;
  Serial.println("Sensor Angle:");
  Serial.println(degrees);

  int tone;
  tone = map(degrees, 0, FULL_ANGLE, 0, 255);
  analogWrite(buzzer, tone);
  delay(500);

  //Button and Buzzer
  int btn = digitalRead(button);
  digitalWrite(buzzer, btn);
  delay(1000);
  
}
