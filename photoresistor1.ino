int lightPin = A0; // pin connected to the photoresistor
int ledPin=13; // pin connected tot he LED

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Begin serial communication
  pinMode( ledPin, OUTPUT ); // Setting the LED pin as output

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(lightPin)); // Read value of photoresistor
  analogWrite(ledPin, analogRead(lightPin)/4); // send value

  delay(10); // short delay before relooping

}
