void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3, LOW);// turn the RED LED on
  digitalWrite(4, LOW);// turn the Green LED on
  digitalWrite(5, LOW);// turn the GREEN LED on
  delay(100);

  digitalWrite(3, LOW);// turn the RED LED off
  digitalWrite(4, HIGH);// turn the RED LED on
  digitalWrite(5, HIGH);// turn the GREEN LED on
  delay(100);

  digitalWrite(3, HIGH);// turn the RED LED off
  digitalWrite(4, LOW);// turn the RED LED on
  digitalWrite(5, HIGH);// turn the GREEN LED on
  delay(100);

  digitalWrite(3, HIGH);// turn the RED LED off
  digitalWrite(4, HIGH);// turn the RED LED on
  digitalWrite(5, LOW);// turn the GREEN LED on
  delay(100);

  digitalWrite(3, LOW);// turn the RED LED off
  digitalWrite(4, HIGH);// turn the RED LED on
  digitalWrite(5, LOW);// turn the GREEN LED on
  delay(100);

  digitalWrite(3, LOW);// turn the RED LED off
  digitalWrite(4, LOW);// turn the RED LED on
  digitalWrite(5, HIGH);// turn the GREEN LED on
  delay(100);

  digitalWrite(3, HIGH);// turn the RED LED off
  digitalWrite(4, LOW);// turn the RED LED on
  digitalWrite(5, LOW);// turn the GREEN LED on
  delay(100);

}