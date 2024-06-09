int motorPin1 = 9;
int motorPin2 = 6;
int motorPin3 = 5;
int motorPin4 = 3;

int leftSensorPin = 13;
int rightSensorPin = 12;

int leftSensorVal = 0;
int rightSensorVal = 0;

void moveLeft();
void moveRight();
void stopMotors();

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  digitalWrite(leftSensorPin, HIGH);
  digitalWrite(rightSensorPin, HIGH);
}

void loop() {
  analogWrite(motorPin1, 255);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 255);
  analogWrite(motorPin4, 0);

  while (1) {
    leftSensorVal = digitalRead(leftSensorPin);
    rightSensorVal = digitalRead(rightSensorPin);

    if ((leftSensorVal == 0 && rightSensorVal == 1) == 1)
      moveLeft();
    else if ((rightSensorVal == 0 && leftSensorVal == 1) == 1)
      moveRight();
  }
}

void moveLeft() {
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 30);

  while (leftSensorVal == 0) {
    leftSensorVal = digitalRead(leftSensorPin);
    rightSensorVal = digitalRead(rightSensorPin);
    if (rightSensorVal == 0) {
      int leftPrev = leftSensorVal;
      int rightPrev = rightSensorVal;
      stopMotors();
      while (((leftPrev == leftSensorVal) && (rightPrev == rightSensorVal)) == 1) {
        leftSensorVal = digitalRead(leftSensorPin);
        rightSensorVal = digitalRead(rightSensorPin);
      }
    }
    analogWrite(motorPin1, 255);
    analogWrite(motorPin2, 0);
  }
  analogWrite(motorPin3, 255);
  analogWrite(motorPin4, 0);
}

void moveRight() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 30);

  while (rightSensorVal == 0) {
    leftSensorVal = digitalRead(leftSensorPin);
    rightSensorVal = digitalRead(rightSensorPin);
    if (leftSensorVal == 0) {
      int leftPrev = leftSensorVal;
      int rightPrev = rightSensorVal;
      stopMotors();
      while (((leftPrev == leftSensorVal) && (rightPrev == rightSensorVal)) == 1) {
        leftSensorVal = digitalRead(leftSensorPin);
        rightSensorVal = digitalRead(rightSensorPin);
      }
    }
    analogWrite(motorPin3, 255);
    analogWrite(motorPin4, 0);
  }
  analogWrite(motorPin1, 255);
  analogWrite(motorPin2, 0);
}

void stopMotors() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
}

