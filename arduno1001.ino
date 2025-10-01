// 定義腳位
const int buttonPin = 2;   // 按鈕接在 Pin 2
const int RLedPin   = 3;   // 紅色 LED
const int GLedPin   = 4;  // 綠色 LED
const int BLedPin   = 5;  // 藍色 LED

// 狀態變數
int buttonState = 0;       
int ledColor = 0;          

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

  if (buttonState == HIGH) {
    // 每按一次按鈕，切換顏色
    ledColor = ledColor + 1;
    delay(100); // 簡單防抖
  }

  // 根據 ledColor 來決定顏色
  if (ledColor == 0) { // 白色
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, HIGH);
  }
  else if (ledColor == 1) { // 紅色
    digitalWrite(RLedPin, LOW);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, HIGH);
  }
  else if (ledColor == 2) { // 綠色
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, LOW);
    digitalWrite(BLedPin, HIGH);
  }
  else if (ledColor == 3) { // 藍色
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, LOW);
  }
  else if (ledColor == 4) { // 紫色 (紅+藍)
    digitalWrite(RLedPin, LOW);
    digitalWrite(GLedPin, LOW);
    digitalWrite(BLedPin, HIGH);
  }
  else if (ledColor == 5) { // 青色 (綠+藍)
    digitalWrite(RLedPin, LOW);
    digitalWrite(GLedPin, HIGH);
    digitalWrite(BLedPin, LOW);
  }
  else if (ledColor == 6) { // 黃色 (紅+綠)
    digitalWrite(RLedPin, HIGH);
    digitalWrite(GLedPin, LOW);
    digitalWrite(BLedPin, LOW);
  }
  else if (ledColor == 7) { // 全滅
    digitalWrite(RLedPin, LOW);
    digitalWrite(GLedPin, LOW);
    digitalWrite(BLedPin, LOW);
  }
  else if (ledColor == 8) {
    ledColor = 0; // 循環回白色
  }
}
