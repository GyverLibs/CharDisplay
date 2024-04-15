#ifndef _CharMatrix_h
#define _CharMatrix_h
#include <Arduino.h>
#include <BitPack.h>
#include <GyverGFX.h>

#define CHAR_X1 1
#define CHAR_X2 2
#define CHAR_X4 4
#define CHAR_X8 8

template <uint8_t TYPE>
class CharMatrix : public GyverGFX {
    class printstring : public String, public Print {
       public:
        size_t write(uint8_t data) {
            concat((char)data);
            return 1;
        }
    };

   public:
    CharMatrix(uint16_t w, uint16_t h) {
        if (TYPE == CHAR_X4 || TYPE == CHAR_X8)
            if (w & 1) w++;
        if (TYPE == CHAR_X2 || TYPE == CHAR_X4)
            if (h & 1) h++;
        if (TYPE == CHAR_X8)
            if (h & 3) h += 4 - (h & 3);
        size(w, h);
        buf.init(w * h);
    }

    void dot(int x, int y, uint8_t fill = 1) {
        buf.write(x + y * width(), fill);
    }

    void clear() {
        buf.clearAll();
    }

    void fill() {
        buf.setAll();
    }

    // напечатать в Print
    void render(Print& p) {
        switch (TYPE) {
            case CHAR_X1:
                for (uint16_t j = 0; j < height(); j++) {
                    for (uint16_t i = 0; i < width(); i++) p.print(xy(i, j) ? F("⬛") : F("⬜"));
                    p.println();
                }
                break;

            case CHAR_X2:
                for (uint16_t j = 0; j < height(); j += 2) {
                    for (uint16_t i = 0; i < width(); i++) {
                        uint8_t v = xy(i, j) | (xy(i, j + 1) << 1);
                        switch (v) {
                            case 0: p.print(F("⠀")); break;
                            case 1: p.print(F("▀")); break;
                            case 2: p.print(F("▄")); break;
                            case 3: p.print(F("█")); break;
                        }
                    }
                    p.println();
                }
                break;

            case CHAR_X4:
                for (uint16_t j = 0; j < height(); j += 2) {
                    for (uint16_t i = 0; i < width(); i += 2) {
                        uint8_t v = xy(i, j) | (xy(i + 1, j) << 1) | (xy(i, j + 1) << 2) | (xy(i + 1, j + 1) << 3);
                        switch (v) {
                            case 0: p.print(F("⠀")); break;
                            case 1: p.print(F("▘")); break;
                            case 2: p.print(F("▝")); break;
                            case 3: p.print(F("▀")); break;
                            case 4: p.print(F("▖")); break;
                            case 5: p.print(F("▌")); break;
                            case 6: p.print(F("▞")); break;
                            case 7: p.print(F("▛")); break;
                            case 8: p.print(F("▗")); break;
                            case 9: p.print(F("▚")); break;
                            case 10: p.print(F("▐")); break;
                            case 11: p.print(F("▜")); break;
                            case 12: p.print(F("▄")); break;
                            case 13: p.print(F("▙")); break;
                            case 14: p.print(F("▟")); break;
                            case 15: p.print(F("█")); break;
                        }
                    }
                    p.println();
                }
                break;

            case CHAR_X8:
                for (uint16_t j = 0; j < height(); j += 4) {
                    for (uint16_t i = 0; i < width(); i += 2) {
                        uint8_t v = 0;
                        for (uint16_t k = 0; k < 8; k++) {
                            int x = i, y = j;
                            if (k <= 2) y += k;
                            else if (k <= 5) {
                                x++;
                                y += k - 3;
                            } else if (k == 6) y += 3;
                            else {
                                y += 3;
                                x++;
                            }
                            v = (v >> 1) | (xy(x, y) << 7);
                        }
                        uint32_t u = 0x2800 + v;
                        p.print(char((u >> 12 & 0x0F) | 0xE0));
                        p.print(char((u >> 6 & 0x3F) | 0x80));
                        p.print(char((u & 0x3F) | 0x80));
                    }
                    p.println();
                }
                break;
        }
    }

    // вывести как String
    String render() {
        printstring s;

        switch (TYPE) {
            case CHAR_X1:
                s.reserve(width() * height() * 3 + height());
                break;
            case CHAR_X2:
                s.reserve(width() * height() * 3 / 2 + height());
                break;
            case CHAR_X4:
                s.reserve(width() * height() * 3 / 4 + height());
                break;
            case CHAR_X8:
                s.reserve(width() * height() * 3 / 8 + height());
                break;
        }

        printTo(s);
        return s;
    }

   private:
    bool xy(const int& x, const int& y) {
        return buf.read(x + y * width());
    }
    BitPackDyn buf;
};
#endif