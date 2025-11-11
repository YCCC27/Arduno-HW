const int buttonPin = 2;
const int RLedPin = 10;
const int GLedPin = 11;
const int BLedPin = 9;

int currentMode = 0;  
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

bool startColorCycle = false;
unsigned long colorCycleStartTime = 0;
const int colorCycleDuration = 3000; 
int colorCycleStep = 0;
unsigned long lastColorChangeTime = 0;
const int colorChangeInterval = 300; 

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(RLedPin, OUTPUT);
  pinMode(GLedPin, OUTPUT);
  pinMode(BLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  checkButton();

  if (startColorCycle) {
    unsigned long currentTime = millis();
    if (currentTime - colorCycleStartTime >= colorCycleDuration) {
      startColorCycle = false;  
    } else if (currentTime - lastColorChangeTime >= colorChangeInterval) {
      lastColorChangeTime = currentTime;
      colorCycleStep = (colorCycleStep + 1) % 3;

      switch (colorCycleStep) {
        case 0: setRGBLEDColor(255, 0, 0); break; 
        case 1: setRGBLEDColor(0, 255, 0); break; 
        case 2: setRGBLEDColor(0, 0, 255); break; 
      }
    }
    return; 
  }

  updateLEDColor();

  if (currentMode == 3) {
    unsigned long currentTime = millis();
    if (currentTime - lastBlinkTime >= blinkInterval) {
      blinkState = !blinkState;
      lastBlinkTime = currentTime;
    }

    if (blinkState) {
      setRGBLEDColor(RcurrentColor, GcurrentColor, BcurrentColor);
    } else {
      setRGBLEDColor(0, 0, 0);  
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
      startColorCycle = true;
      colorCycleStartTime = millis();
      colorCycleStep = 0;
      lastColorChangeTime = millis();
    } else {
      Serial.println("long press");
      changeMode();  
    }
    buttonPressed = false;
  }
}

void changeMode() {
  currentMode = (currentMode + 1) % (maxMode + 1);  
  Serial.print("Mode changed to: ");
  Serial.println(currentMode);
}

void updateLEDColor() {
  switch (currentMode) {
    case 0:  
      RcurrentColor = 0;
      GcurrentColor = 255;
      BcurrentColor = 255;
      break;
    case 1:  
      RcurrentColor = 255;
      GcurrentColor = 0;
      BcurrentColor = 255;
      break;
    case 2:  
      RcurrentColor = 255;
      GcurrentColor = 255;
      BcurrentColor = 0;
      break;
    case 3:  
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
