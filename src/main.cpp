#include <Arduino.h>

const char* firmware = "v1.0.0";

void setup() {
  Serial.begin(115200);
  Serial.println(firmware);
}

void loop() {
}
