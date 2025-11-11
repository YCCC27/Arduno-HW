const int buttonPin = 4;
const int ledPin = 3;
bool buttonState = 0;
int ledmode = 0;
bool ButtonPressed = false ;

void setup(){
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  ledmode = 3 ;
}

void loop(){
  Serial.println(ledmode);
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH && !ButtonPressed){
    ledmode++;
    if(ledmode >3){
      ledmode = 0;
    }
    ButtonPressed = true;
  }
  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }
  if(ledmode == 0){
    digitalWrite(ledPin,HIGH);
  }
  if(ledmode == 1){
    digitalWrite(ledPin,HIGH);
    delay(1000);
    digitalWrite(ledPin,LOW);
    delay(1000);
  }
  if(ledmode == 2){
    digitalWrite(ledPin,HIGH);
    delay(500);
    digitalWrite(ledPin,LOW);
    delay(500);
  }
  if(ledmode == 3){
    digitalWrite(ledPin,HIGH);
    delay(100);
    digitalWrite(ledPin,LOW);
    delay(100);
  }
}