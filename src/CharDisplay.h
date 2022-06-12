#ifndef _CharDisplay_h
#define _CharDisplay_h
#include "utils.h"
#include "CharMatrix.h"

#define CHAR_X1 1
#define CHAR_X2 2
#define CHAR_X4 4
#define CHAR_X8 8

template <uint8_t type> String CharBar(uint8_t len, uint8_t perc);

String CharPlot(float* buf, uint8_t W, uint8_t H, uint8_t block = 0, uint8_t border = 0);

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
				for (uint16_t i = 0; i < W(); i++) s += xy(i, j) ? "⬛" : "⬜";
				s += '\n';
			}
			} else if (TYPE == CHAR_X2) {
			s.reserve(W() * H() * 3 / 2 + H());
			for (uint16_t j = 0; j < H(); j += 2) {
				for (uint16_t i = 0; i < W(); i++) {
					uint8_t v = xy(i, j) | (xy(i, j + 1) << 1);
					switch (v) {
						case 0: s += "⠀"; break;
						case 1: s += "▀"; break;
						case 2: s += "▄"; break;
						case 3: s += "█"; break;
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
            case 0: s += "⠀"; break;
            case 1: s += "▘"; break;
            case 2: s += "▝"; break;
            case 3: s += "▀"; break;
            case 4: s += "▖"; break;
            case 5: s += "▌"; break;
            case 6: s += "▞	"; break;
            case 7: s += "▛"; break;
            case 8: s += "▗"; break;
            case 9: s += "▚"; break;
            case 10: s += "▐"; break;
						case 11: s += "▜"; break;
						case 12: s += "▄"; break;
						case 13: s += "▙"; break;
						case 14: s += "▟"; break;
						case 15: s += "█"; break;
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
						v >>= 1;
						v |= xy(x, y) << 7;
					}
					_addUnix(s, 0x2800 + v);
				}
				s += '\n';
			}
		}
		return s;
	}
	
	using GyverGFX::fill;
	using GyverGFX::size;
	using GyverGFX::W;
	using GyverGFX::H;
	
private:
bool xy(int x, int y) {
return buf[x + y * W()].b;
}
_CD_bit* buf;
};
#endif