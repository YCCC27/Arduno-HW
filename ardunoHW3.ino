const int buttonPin = 2;
const int RLedPin = 10;
const int GLedPin = 11;
const int BLedPin = 9;

int currentMode = 0;  // 模式變數
const int maxMode = 3;

int RcurrentColor = 0;
int GcurrentColor = 0;
int BcurrentColor = 0;

bool buttonPressed = false;
unsigned long pressingTime = 0;
const int longPressInterval = 2000;

bool blinkState = false;
unsigned long lastBlinkTime = 0;
const int blinkInterval = 500;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(RLedPin, OUTPUT);
  pinMode(GLedPin, OUTPUT);
  pinMode(BLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  checkButton();
  updateLEDColor();

  // 閃爍模式（假設 mode 3 是閃爍）
  if (currentMode == 3) {
    unsigned long currentTime = millis();
    if (currentTime - lastBlinkTime >= blinkInterval) {
      blinkState = !blinkState;
      lastBlinkTime = currentTime;
    }

    if (blinkState) {
      setRGBLEDColor(RcurrentColor, GcurrentColor, BcurrentColor);
    } else {
      setRGBLEDColor(0, 0, 0);  // 關燈
    }
  } else {
    setRGBLEDColor(RcurrentColor, GcurrentColor, BcurrentColor);
  }
}

void checkButton() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && !buttonPressed) {
    pressingTime = millis();
    buttonPressed = true;
  }

  if (buttonState == HIGH && buttonPressed) {
    unsigned long currentTime = millis();
    if (currentTime - pressingTime < longPressInterval) {
      Serial.println("short click");
    } else {
      Serial.println("long press");
      changeMode();
      // 可加入其他長按功能
    }
    buttonPressed = false;
  }
}

void changeMode() {
  currentMode = (currentMode + 1) % (maxMode + 1);  // 循環模式 0~3
  Serial.print("Mode changed to: ");
  Serial.println(currentMode);
}

void updateLEDColor() {
  switch (currentMode) {
    case 0:  // 紅色
      RcurrentColor = 0;
      GcurrentColor = 255;
      BcurrentColor = 255;
      break;
    case 1:  // 綠色
      RcurrentColor = 255;
      GcurrentColor = 0;
      BcurrentColor = 255;
      break;
    case 2:  // 藍色
      RcurrentColor = 255;
      GcurrentColor = 255;
      BcurrentColor = 0;
      break;
    case 3:  // 閃爍白光
      RcurrentColor = 255;
      GcurrentColor = 255;
      BcurrentColor = 255;
      break;
  }
}

void setRGBLEDColor(int r, int g, int b) {
  analogWrite(RLedPin, r);
  analogWrite(GLedPin, g);
  analogWrite(BLedPin, b);
}
