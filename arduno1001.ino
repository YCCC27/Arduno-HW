// 定義腳位
const int buttonPin = 2;   // 按鈕接在 Pin 2
const int RLedPin   = 3;   // 紅色 LED
const int GLedPin   = 4;  // 綠色 LED
const int BLedPin   = 5;  // 藍色 LED

// 狀態變數
int buttonState = 0;  
int ledState = LOW;     
int ledcolor = 0;  
String currentcolor = "LED off";  // 初始值可自訂
bool ButtonPressed = false;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  // LED 腳位設為輸出
  pinMode(RLedPin, OUTPUT);
  pinMode(GLedPin, OUTPUT);
  pinMode(BLedPin, OUTPUT);

  // 按鈕腳位設為輸入
  pinMode(buttonPin, INPUT);
}

void loop() {
  // 讀取按鈕狀態
  buttonState = digitalRead(buttonPin);
  Serial.print("Current Color:");
  Serial.println(currentcolor);
  if (buttonState == HIGH && !ButtonPressed) {
    // 每按一次按鈕，切換顏色
    ledcolor = ledcolor + 1;
    ButtonPressed = true;
  }
  if (buttonState == LOW && ButtonPressed) {
    // 每按一次按鈕，切換顏色
    ButtonPressed = false;
  }
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
  if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
  }
  // 根據 ledColor 來決定顏色
  if (ledcolor == 0) { // 白色
    currentcolor="LED off";
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, HIGH);
  }
  else if (ledcolor == 1) { // 紅色
    currentcolor="Red";
       if (ledState == LOW) {
    digitalWrite(RLedPin, LOW);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, HIGH);
    } else {
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, HIGH);
    }
  }
  else if (ledcolor == 2) { // 綠色
    currentcolor="Green";
       if (ledState == LOW) {
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, LOW);
    digitalWrite(BLedPin, HIGH);
    } else {
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, HIGH);
    }
  }
  else if (ledcolor == 3) { // 藍色
    currentcolor="Blue";
       if (ledState == LOW) {
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, LOW);
    } else {
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, HIGH);
    }
  }
  else if (ledcolor == 4) { // 紫色 (紅+藍)
    currentcolor="Yellow";
       if (ledState == LOW) {
    digitalWrite(RLedPin, LOW);
    digitalWrite(GLedPin, LOW);
    digitalWrite(BLedPin, HIGH);
    } else {
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, HIGH);
    }
  }
  else if (ledcolor == 5) { // 青色 (綠+藍)
    currentcolor="Purple";
       if (ledState == LOW) {
    digitalWrite(RLedPin, LOW);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, LOW);
    } else {
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, HIGH);
    }
  }
  else if (ledcolor == 6) { // 黃色 (紅+綠)
    currentcolor="Cyan";
       if (ledState == LOW) {
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, LOW);
    digitalWrite(BLedPin, LOW);
    } else {
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, HIGH);
    }
  }
  else if (ledcolor == 7) { // 全滅
    currentcolor="White";
       if (ledState == LOW) {
    digitalWrite(RLedPin, LOW);
    digitalWrite(GLedPin, LOW);
    digitalWrite(BLedPin, LOW);
    } else {
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, HIGH);
    }
  }
  else if(ledcolor == 8){
    ledcolor = 0;
  }
}
