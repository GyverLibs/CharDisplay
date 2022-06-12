#include "utils.h"
void _addUnix(String& s, uint16_t u) {
    s += char(u >> 12 & 0x0F | 0xE0);
    s += char(u >> 6  & 0x3F | 0x80);
    s += char(u & 0x3F | 0x80);
}