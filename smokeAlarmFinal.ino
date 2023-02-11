int redLed = 12;
int greenLed = 11;
int relay = 10;
int smokeA0 = A0;
// enter threshold value
int sensorThres = 400;
int sensorFailure = 150;
void setup() {
  // put your setup code here, to run once:
pinMode(redLed, OUTPUT);
pinMode(greenLed, OUTPUT);
pinMode(relay, OUTPUT);
pinMode(smokeA0, INPUT);
Serial.begin(9600);


}

void loop() {
int analogSensor = analogRead(smokeA0);

Serial.print("Pin A0: ");
Serial.println(analogSensor);

if (analogSensor > sensorThres)
{
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  digitalWrite(relay, LOW);
}
  else if (analogSensor < sensorFailure)
{
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  digitalWrite(relay, LOW);
}
else
{
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  digitalWrite(relay, HIGH);
}



delay(100);
}
  
