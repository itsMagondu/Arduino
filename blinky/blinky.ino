/* Project 1: RGB Blinky
Uses a single RGB LED to cycle through three colors.
*/
const int red = 9;
const int green = 10;
const int blue = 11;

int time = 1000;
int multiple = 2;

void setup() {
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
}
void loop() {
digitalWrite(red, HIGH);
delay(time);
digitalWrite(green, HIGH);
delay(time);
digitalWrite(blue, HIGH);
delay(time);
digitalWrite(red, LOW);
digitalWrite(blue, LOW);
delay(time);
digitalWrite(blue, HIGH);
delay(time);
digitalWrite(green, LOW);
delay(time*=multiple);
digitalWrite(blue, LOW);
digitalWrite(green, LOW);
time/=multiple;
}
