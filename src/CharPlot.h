#pragma once
#include <Arduino.h>

#define LINE_X1 0
#define LINE_X2 1
#define COLON_X2 2
#define COLON_X1 3

template <int type>
String CharPlot(float* buf, int W, int H, bool fill = 1, bool border = 0) {
    String s;
    int frame = W;
    if (type == LINE_X2 || type == COLON_X2) {
        if (W & 1) W--;
        frame = W / 2;
    }
    s.reserve((frame + 2) * (H + 2) * 3 + H * 5);
    s += border ? F("┏") : F("╔");
    for (int i = 0; i < frame; i++) s += border ? F("━") : F("═");
    s += border ? F("┓\n") : F("╗\n");

    float mn = buf[0];
    float mx = buf[0];
    for (int i = 0; i < W; i++) {
        if (buf[i] < mn) mn = buf[i];
        if (buf[i] > mx) mx = buf[i];
    }
    uint8_t shift = (type <= 2);
    float delta = mx - mn;
    uint8_t blocks[W], fracts[W];
    for (int i = 0; i < W; i++) {
        float v = (buf[i] - mn) * (H - shift) / delta;
        fracts[i] = (v - int(v)) * 10;
        blocks[i] = v + 1 - shift;
    }
    delta /= (H - shift);

    for (int h = 0; h < H; h++) {
        s += border ? F("┃") : F("║");
        // LINE_X1
        if (type == 0) {
            for (int w = 0; w < W; w++) {
                if (blocks[w] == H - h - shift) s += (fracts[w] >= 5) ? F("▀") : F("▄");
                else s += fill ? F("░") : F("⠀");
            }
            // LINE_X2
        } else if (type == 1) {
            for (int w = 0; w < W; w += 2) {
                uint8_t sub[] = {0, 0};
                for (int i = 0; i < 2; i++) {
                    if (blocks[w + i] == H - h - shift) sub[i] = (fracts[w + i] >= 5) ? 0b10 : 0b01;
                }
                switch ((sub[0] << 2) | sub[1]) {
                    case 0b0000:
                        s += fill ? F("░") : F("⠀");
                        break;
                    case 0b1000:
                        s += F("▘");
                        break;
                    case 0b0010:
                        s += F("▝");
                        break;
                    case 0b0100:
                        s += F("▖");
                        break;
                    case 0b0001:
                        s += F("▗");
                        break;
                    case 0b1010:
                        s += F("▀");
                        break;
                    case 0b0101:
                        s += F("▄");
                        break;
                    case 0b1001:
                        s += F("▚");
                        break;
                    case 0b0110:
                        s += F("▞");
                        break;
                }
            }
            // COLON_X2
        } else if (type == 2) {
            for (int w = 0; w < W; w += 2) {
                uint8_t sub[] = {0, 0};
                for (int i = 0; i < 2; i++) {
                    if (blocks[w + i] > H - h - shift) sub[i] = 0b11;
                    else if (blocks[w + i] == H - h - shift) sub[i] = (fracts[w + i] >= 5) ? 0b11 : 0b01;
                }
                switch ((sub[0] << 2) | sub[1]) {
                    case 0b0000:
                        s += fill ? F("░") : F("⠀");
                        break;
                    case 0b1100:
                        s += F("▌");
                        break;
                    case 0b0011:
                        s += F("▐");
                        break;
                    case 0b1101:
                        s += F("▙");
                        break;
                    case 0b0111:
                        s += F("▟");
                        break;
                    case 0b0101:
                        s += F("▄");
                        break;
                    case 0b0100:
                        s += F("▖");
                        break;
                    case 0b0001:
                        s += F("▗");
                        break;
                    case 0b1111:
                        s += F("█");
                        break;
                }
            }
            // COLON_X1
        } else {
            for (int w = 0; w < W; w++) {
                if (blocks[w] > H - h) s += F("█");
                else if (blocks[w] == H - h) {
                    uint32_t u = fracts[w] * 8 / 10 + 0x2581;
                    s += char((u >> 12 & 0x0F) | 0xE0);
                    s += char((u >> 6 & 0x3F) | 0x80);
                    s += char((u & 0x3F) | 0x80);
                } else s += fill ? F("░") : F("⠀");
            }
        }
        s += border ? F("┣ ") : F("╠ ");
        s += String(mx - delta * h, 1);
        s += '\n';
    }
    s += border ? F("┗") : F("╚");
    for (int i = 0; i < frame; i++) s += border ? F("━") : F("═");
    s += border ? F("┛\n") : F("╝\n");
    return s;
}