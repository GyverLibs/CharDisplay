#ifndef _CharMatrix_h
#define _CharMatrix_h
#include <Arduino.h>
#include <GyverGFX.h>

#define CHAR_X1 1
#define CHAR_X2 2
#define CHAR_X4 4
#define CHAR_X8 8

struct _CD_bit {
    bool b : 1;
};

template <uint8_t TYPE>
class CharMatrix : public GyverGFX {
public:
    CharMatrix(uint16_t w, uint16_t h) {
        if (TYPE == CHAR_X4 || TYPE == CHAR_X8) if (w & 1) w++;
        if (TYPE == CHAR_X2 || TYPE == CHAR_X4) if (h & 1) h++;
        if (TYPE == CHAR_X8) if (h & 3) h += 4 - (h & 3);
        size(w, h);
        buf = new _CD_bit[w * h];
        clear();
    }
    
    ~CharMatrix() {
        if (buf) delete [] buf;
    }
    
    void dot(int x, int y, uint8_t fill = 1) {
        if (!buf) return;
        buf[x + y * W()].b = fill;
    }
    
    String render() {
        String s;
        if (TYPE == CHAR_X1) {
            s.reserve(W() * H() * 3 + H());
            for (uint16_t j = 0; j < H(); j++) {
                for (uint16_t i = 0; i < W(); i++) s += xy(i, j) ? F("⬛") : F("⬜");
                s += '\n';
            }
        } else if (TYPE == CHAR_X2) {
            s.reserve(W() * H() * 3 / 2 + H());
            for (uint16_t j = 0; j < H(); j += 2) {
                for (uint16_t i = 0; i < W(); i++) {
                    uint8_t v = xy(i, j) | (xy(i, j + 1) << 1);
                    switch (v) {
                    case 0: s += F("⠀"); break;
                    case 1: s += F("▀"); break;
                    case 2: s += F("▄"); break;
                    case 3: s += F("█"); break;
                    }
                }
                s += '\n';
            }
        } else if (TYPE == CHAR_X4) {
            s.reserve(W() * H() * 3 / 4 + H());
            for (uint16_t j = 0; j < H(); j += 2) {
                for (uint16_t i = 0; i < W(); i += 2) {
                    uint8_t v = xy(i, j) | (xy(i + 1, j) << 1) | (xy(i, j + 1) << 2) | (xy(i + 1, j + 1) << 3);
                    switch (v) {
                    case 0: s += F("⠀"); break;
                    case 1: s += F("▘"); break;
                    case 2: s += F("▝"); break;
                    case 3: s += F("▀"); break;
                    case 4: s += F("▖"); break;
                    case 5: s += F("▌"); break;
                    case 6: s += F("▞"); break;
                    case 7: s += F("▛"); break;
                    case 8: s += F("▗"); break;
                    case 9: s += F("▚"); break;
                    case 10: s += F("▐"); break;
                    case 11: s += F("▜"); break;
                    case 12: s += F("▄"); break;
                    case 13: s += F("▙"); break;
                    case 14: s += F("▟"); break;
                    case 15: s += F("█"); break;
                    }
                }
                s += '\n';
            }
        } else {
            s.reserve(W() * H() * 3 / 8 + H());
            for (uint16_t j = 0; j < H(); j += 4) {
                for (uint16_t i = 0; i < W(); i += 2) {
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
                    s += char((u >> 12 & 0x0F) | 0xE0);
                    s += char((u >> 6  & 0x3F) | 0x80);
                    s += char((u & 0x3F) | 0x80);
                }
                s += '\n';
            }
        }
        return s;
    }
    
private:
    bool xy(int x, int y) {
        return buf[x + y * W()].b;
    }
    _CD_bit* buf;
};
#endif