void setup(){
pinMode(13,OUTPUT);//Loght LED
pinMode(12,INPUT);//Read from Ultrasonic sensor
pinMode(11,OUTPUT);//Display Text On LED
}
void loop(){
digitalWrite(13, HIGH);
delay(1000);
digitalWrite(13, LOW);
delay(1000);
}
