#include <CharPlot.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  uint8_t sz = 40;
  float arr[sz];

  for (int i = 0; i < sz; i++) {
    arr[i] = sin(radians(i * 360.0 / sz)) * 50;
  }
  Serial.println(CharPlot<LINE_X1>(arr, sz / 2, 10));
  Serial.println(CharPlot<LINE_X2>(arr, sz, 10));
  Serial.println(CharPlot<COLON_X1>(arr, sz / 2, 10));
  Serial.println(CharPlot<COLON_X2>(arr, sz, 10));
}

void loop() {
}
