
//Set up names and which I/O pins they go to
int relay = 12;
int smokeA0 = A0;
// enter threshold value for scaling the smoke sensor, use the on screen serial monitor to see what value the smoke sensor stabilizes to and set it about 50-100 units higher
int sensorThres = 190;
//enter value for scaling the smoke sensor for a failure. Should be 0 units when unplugged or failed
int sensorFailure = 120;
void setup() {
  // put your setup code here, to run once:

//Sets up I/O 
pinMode(relay, OUTPUT);
pinMode(smokeA0, INPUT);
//sets up serial printing to arduino ide
Serial.begin(9600);


}

void loop() {
int analogSensor = analogRead(smokeA0);
//Sets up 
Serial.print("Pin A0: ");
Serial.println(analogSensor);

if (sensorThres < analogSensor || analogSensor < sensorFailure) 
{
  digitalWrite(relay, LOW);
  Serial.print("LOW");
}
else
{
  digitalWrite(relay, HIGH);
  Serial.print("HIGH");
}

// Alternate way to write this code, less effective
/*
if (analogSensor > sensorThres)
{
 
  digitalWrite(relay, LOW);
}
  else if (analogSensor < sensorFailure)
{
  
  digitalWrite(relay, LOW);
}
else
{

  digitalWrite(relay, HIGH);
}

*/

delay(100);
}
  
