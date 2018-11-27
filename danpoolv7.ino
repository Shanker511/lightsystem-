//Created by Dan Pautsch and Gareth Erwin of Managed Services 
//Rainbow swirl when light sensor detects dark or no light
//Red fade for light sensor detects bright light

#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 9
 
#define FADESPEED 20    // make this higher to slow down
#define ALERTSPEED 5    // make this higher to slow down

int sensorPin = A0;
int threshold = 300;
int sensorValue = 0;
int r, g, b, c;
 
void setup() {
  Serial.begin(9600);
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}
 
 
void loop() {
  Serial.println("DarkSensor");
  Serial.println(analogRead(sensorPin));
    // fade from green to teal
  for (b = 0; b < 256; b++) { 
    analogWrite(BLUEPIN, b);
    if (analogRead(sensorPin) >= threshold) red();
    delay(FADESPEED);
    }
    // fade from teal to blue
  Serial.println("DarkSensor");
  Serial.println(analogRead(sensorPin));
  for (g = 255; g > 0; g--) { 
    analogWrite(GREENPIN, g);
    if (analogRead(sensorPin) >= threshold) red();
    delay(FADESPEED);
    }
  // fade from blue to violet
  Serial.println("DarkSensor");
  Serial.println(analogRead(sensorPin));
  for (r = 0; r < 256; r++) { 
    analogWrite(REDPIN, r);
    if (analogRead(sensorPin) >= threshold) red();
    delay(FADESPEED);
  }
    // fade from violet to red
  Serial.println("DarkSensor");
  Serial.println(analogRead(sensorPin));
  for (b = 255; b > 0; b--) { 
    analogWrite(BLUEPIN, b);
    if (analogRead(sensorPin) >= threshold) red();
    delay(FADESPEED);
  } 
  // fade from red to yellow
  Serial.println("DarkSensor");
  Serial.println(analogRead(sensorPin));
  for (g = 0; g < 256; g++) { 
    analogWrite(GREENPIN, g);
    if (analogRead(sensorPin) >= threshold) red();
    delay(FADESPEED);
  }
  // fade from yellow to green
  Serial.println("DarkSensor");
  Serial.println(analogRead(sensorPin));
  for (r = 255; r > 0; r--) { 
    analogWrite(REDPIN, r);
    if (analogRead(sensorPin) >= threshold) red();
    delay(FADESPEED);
  }
}
void red(){
  Serial.println("BrightSensor");
  Serial.println(analogRead(sensorPin));
  for (c = 0; c < 256; c++) { 
    analogWrite(BLUEPIN, 0);
    analogWrite(REDPIN, c);
    analogWrite(GREENPIN, 0);
    if (analogRead(sensorPin) < threshold) loop();
    delay(ALERTSPEED);
  }
  red();
}
