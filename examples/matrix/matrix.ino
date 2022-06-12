#include <CharMatrix.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();

  Serial.println("CHAR_X1");
  CharMatrix<CHAR_X1> disp1(10, 10);
  disp1.circle(5, 5, 3);
  Serial.println(disp1.render());

  Serial.println("CHAR_X2");
  CharMatrix<CHAR_X2> disp2(25, 10);
  disp2.print("Keks!");
  disp2.line(0, 9, 25, 9);
  Serial.println(disp2.render());

  Serial.println("CHAR_X4");
  CharMatrix<CHAR_X4> disp3(35, 15);
  disp3.setCursor(2, 2);
  disp3.print("Hello");
  disp3.rect(0, 0, 33, 10, GFX_STROKE);
  Serial.println(disp3.render());

  Serial.println("CHAR_X8");
  CharMatrix<CHAR_X8> disp4(40, 20);
  disp4.rect(0, 0, 39, 19, GFX_STROKE);
  disp4.rect(6, 6, 33, 13, GFX_STROKE);
  disp4.line(0, 0, 39, 19);
  disp4.line(39, 0, 0, 19);
  Serial.println(disp4.render());
}

void loop() {
}
