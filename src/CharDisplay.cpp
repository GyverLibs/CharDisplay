#include "CharDisplay.h"

template <uint8_t type>
String CharBar(uint8_t len, uint8_t perc) {
    perc = constrain(perc, 0, 100);
    String s;
    s.reserve(len * 3);
    int fill = (len * perc + 100 - 1) / 100;
    if (type == 0 || type == 4) s += '[';
    for (int i = 0; i < len; i++) {
        if (type == 0) s += (i < fill) ? "#" : "-";
        else if (type == 1) s += (i < fill) ? "■" : "□";
        else if (type == 2) s += (i < fill) ? "◼" : "◻";
        else if (type == 3) s += (i < fill) ? "▰" : "▱";
        else if (type == 4) s += (i < fill) ? "⧯" : "⧮";
        else if (type == 5) s += (i < fill) ? "▮" : "▯";
        else if (type == 6) s += (i < fill) ? "█" : "⠀";
        else if (type == 7) s += (i < fill) ? "█" : "░";
        else if (type == 8) s += (i < fill) ? "⬛" : "⬜";
        else if (type == 9) s += (i < fill) ? "⬤" : "◯";
        else if (type == 10) s += (i < fill) ? "⚫" : "⚪";
    }
    if (type == 0 || type == 4) s += ']';
    return s;
}

String CharPlot(float* buf, uint8_t W, uint8_t H, uint8_t block = 0, uint8_t border = 0) {
    String s;
    s.reserve((W + 2) * (H + 2) * 3 + H * 5);
    s += border ? "┏" : "╔";
    for (int i = 0; i < W; i++) s += border ? "━" : "═";
    s += border ? "┓\n" : "╗\n";
    
    float mn = buf[0];
    float mx = buf[0];
    for (int i = 0; i < W; i++) {
        if (buf[i] < mn) mn = buf[i];
        if (buf[i] > mx) mx = buf[i];
    }
    uint8_t shift = block <= 1;
    float delta = mx - mn;
    uint8_t blocks[W], fracts[W];
    for (int i = 0; i < W; i++) {
        float v = (buf[i] - mn) * (H - shift) / delta;
        fracts[i] = (v - int(v)) * 10;
        blocks[i] = v + 1 - shift;
    }
    delta /= (H - shift);
    
    for (int h = 0; h < H; h++) {
        s += border ? "┃" : "║";
        
        if (block <= 1) {
            for (int w = 0; w < W; w++) {
                if (blocks[w] == H - h - shift) s += (fracts[w] >= 5) ? "▀" : "▄";
                else s += block ? "⠀" : "░";
            }
            } else {
            for (int w = 0; w < W; w++) {
                if (blocks[w] > H - h) s += "█";
                else if (blocks[w] == H - h) _addUnix(s, fracts[w] * 8 / 10 + 0x2581);
                else s += (block == 3) ? "⠀" : "░";
            }
        }
        s += border ? "┣ " : "╠ ";
        s += String(mx - delta * h, 1);
        s += '\n';
    }
    s += border ? "┗" : "╚";
    for (int i = 0; i < W; i++) s += border ? "━" : "═";
    s += border ? "┛\n" : "╝\n";
    return s;
}