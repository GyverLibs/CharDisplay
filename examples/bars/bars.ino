#include <CharBar.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println(CharBar<BAR_SQUARE>(10, 10));
  Serial.println(CharBar<BAR_SQUARE2>(10, 20));
  Serial.println(CharBar<BAR_SQUARE3>(10, 30));
  Serial.println(CharBar<BAR_DIAMOND>(10, 40));
  Serial.println(CharBar<BAR_RECT>(10, 50));
  Serial.println(CharBar<BAR_RECT2>(10, 60));
  Serial.println(CharBar<BAR_BLOCK>(10, 70));
  Serial.println(CharBar<BAR_BLOCK2>(10, 80));
  Serial.println(CharBar<BAR_CIRCLE>(10, 90));
  Serial.println(CharBar<BAR_CIRCLE2>(10, 90));
}

void loop() {
}
