#include <SoftwareSerial.h>

int bulbPin1 = 8;
int bulbPin2 = 9;
int bulbPin3 = 10;
int bulbPin4 = 11;

SoftwareSerial bt(0, 1); /* (Rx, Tx) */

String receivedMessage;

void setup() {
  bt.begin(9600);
  Serial.begin(9600);

  pinMode(bulbPin1, OP);
  pinMode(bulbPin2, OP);
  pinMode(bulbPin3, OP);
  pinMode(bulbPin4, OP);
}

void loop() {
  if (bt.available()) {
    receivedMessage = bt.readString();
    Serial.println(receivedMessage);
    if (receivedMessage == "bulb1 on") {
      digitalWrite(bulbPin1, HIGH);
      Serial.println("Bulb 1 is ON");
    } else if (receivedMessage == "bulb1 off") {
      digitalWrite(bulbPin1, LOW);
      Serial.println("Bulb 1 is OFF");
    } else {
      digitalWrite(bulbPin1, LOW);
    }
    if (receivedMessage == "bulb2 on") {
      digitalWrite(bulbPin2, HIGH);
      Serial.println("Bulb 2 is ON");
    } else if (receivedMessage == "bulb2 off") {
      digitalWrite(bulbPin2, LOW);
      Serial.println("Bulb 2 is OFF");
    } else {
      digitalWrite(bulbPin2, LOW);
    }
    if (receivedMessage == "bulb3 on") {
      digitalWrite(bulbPin3, HIGH);
      Serial.println("Bulb 3 is ON");
    } else if (receivedMessage == "bulb3 off") {
      digitalWrite(bulbPin3, LOW);
      Serial.println("Bulb 3 is OFF");
    } else {
      digitalWrite(bulbPin3, LOW);
    }
	if (receivedMessage == "bulb4 on") {
      digitalWrite(bulbPin4, HIGH);
      Serial.println("Bulb 4 is ON");
    } else if (receivedMessage == "bulb4 off") {
      digitalWrite(bulbPin4, LOW);
      Serial.println("Bulb 4 is OFF");
    } else {
      digitalWrite(bulbPin4, LOW);
    }
  }
}

