const int pushButton=2;
const int rLEDPin=3;
const int bLEDPin=4;
const int gLEDPin=5;

int buttonState=0;
int ledcolor=0;

void setup() {
  pinMode(rLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(pushButton, INPUT);
}

void loop() {
  buttonState=digitalRead(pushButton);

  if(buttonState==LOW){
    // 加入切換閃爍特效 
    digitalWrite(rLEDPin, LOW);
    digitalWrite(bLEDPin, LOW);
    digitalWrite(gLEDPin, LOW);
    delay(100);
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);
    delay(100);
    // 顏色遞增
    ledcolor=ledcolor+1;
    delay(150);
  }

  // 顏色控制區
  if(ledcolor==0){
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);

  }else if(ledcolor==1){
    digitalWrite(rLEDPin, LOW);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, HIGH);

  }else if(ledcolor==2){
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, LOW);
    digitalWrite(gLEDPin, HIGH);

  }else if(ledcolor==3){
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, LOW);

  }else if(ledcolor==4){
    digitalWrite(rLEDPin, LOW);
    digitalWrite(bLEDPin, LOW);
    digitalWrite(gLEDPin, HIGH);

  }else if(ledcolor==5){
    digitalWrite(rLEDPin, LOW);
    digitalWrite(bLEDPin, HIGH);
    digitalWrite(gLEDPin, LOW);

  }else if(ledcolor==6){
    digitalWrite(rLEDPin, HIGH);
    digitalWrite(bLEDPin, LOW);
    digitalWrite(gLEDPin, LOW);

  }else if(ledcolor==7){
    digitalWrite(rLEDPin, LOW);
    digitalWrite(bLEDPin, LOW);
    digitalWrite(gLEDPin, LOW);

  }else if(ledcolor==8){
    ledcolor=0;
  }
}
