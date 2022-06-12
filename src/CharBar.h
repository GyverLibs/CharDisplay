#ifndef _CharBar_h
#define _CharBar_h
#include <Arduino.h>

#define BAR_SQUARE 0
#define BAR_SQUARE2 1
#define BAR_SQUARE3 2
#define BAR_DIAMOND 3
#define BAR_RECT 4
#define BAR_RECT2 5
#define BAR_BLOCK 6
#define BAR_BLOCK2 7
#define BAR_CIRCLE 8
#define BAR_CIRCLE2 9

template <int type>
String CharBar(int len, int perc) {
    perc = constrain(perc, 0, 100);
    String s;
    s.reserve(len * 3);
    int fill = (len * perc + 100 - 1) / 100;
    if (type == BAR_RECT) s += '[';
    for (int i = 0; i < len; i++) {
        if (type == BAR_SQUARE) s += (i < fill) ? F("■") : F("□");
        else if (type == BAR_SQUARE2) s += (i < fill) ? F("◼") : F("◻");
        else if (type == BAR_SQUARE3) s += (i < fill) ? F("⬛") : F("⬜");
        else if (type == BAR_DIAMOND) s += (i < fill) ? F("▰") : F("▱");
        else if (type == BAR_RECT) s += (i < fill) ? F("⧯") : F("⧮");
        else if (type == BAR_RECT2) s += (i < fill) ? F("▮") : F("▯");
        else if (type == BAR_BLOCK) s += (i < fill) ? F("█") : F("⠀");
        else if (type == BAR_BLOCK2) s += (i < fill) ? F("█") : F("░");
        else if (type == BAR_CIRCLE) s += (i < fill) ? F("⬤") : F("◯");
        else if (type == BAR_CIRCLE2) s += (i < fill) ? F("⚫") : F("⚪");
    }
    if (type == BAR_RECT) s += ']';
    return s;
}

#endif