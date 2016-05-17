#include <NewPing.h>

const int rgb[] = {9,10,11};
const int time = 250;
const int switchPin = 2;

#define TRIGGER_PIN  7  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


void setup() {
for (int i=0; i<3; i++) pinMode(rgb[i], OUTPUT);
pinMode(switchPin, INPUT);
Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
int newPin = 0;
int oldPin = 0;
int bounce1 = digitalRead(switchPin);
delay(25);
int bounce2 = digitalRead(switchPin);
while ((bounce1 == bounce2) && (bounce1 == LOW)) {
/*oldPin = newPin;
newPin++;
if (newPin == 3) newPin = 0;
digitalWrite(rgb[oldPin], HIGH);
delay(time);
digitalWrite(rgb[newPin], HIGH);
delay(time);
digitalWrite(rgb[oldPin], LOW);
if (newPin == 0) {
for (int i=0; i<3; i++) digitalWrite(rgb[i], HIGH);
delay(time);
for (int i=0; i<3; i++) digitalWrite(rgb[i], LOW);
}*/


unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  int distance  = uS / US_ROUNDTRIP_CM;
  Serial.print(distance); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  delay(500);
  if (distance <= 20){
    //digitalWrite(rgb[0], HIGH);
    digitalWrite(rgb[1], HIGH);
    digitalWrite(rgb[2], HIGH);
  }
  else {
    //digitalWrite(rgb[0], LOW);
    digitalWrite(rgb[1], LOW);
    digitalWrite(rgb[2], LOW);
  }
  
bounce1 = digitalRead(switchPin);
delay(25);
bounce2 = digitalRead(switchPin); 
}
for (int i=0; i<3; i++) digitalWrite(rgb[i], LOW);
delay(25);
}
