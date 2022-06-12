This is an automatic translation, may be incorrect in some places. See sources and examples!

# CharDisplay
Library for creating symbolic graphics:
- **CharMatrix** - Matrix for full drawing (4 styles)
- **CharBar** - Loading bars (10 styles)
- **CharPlot** - Chart (4 styles + 2 fill styles + 2 frame styles)

Great for visualizing data in reports when sent by mail or via [Telegram bot](https://github.com/GyverLibs/FastBot)
**Attention!** Not displayed normally everywhere, you need a monospaced font.

### Compatibility
Compatible with all Arduino platforms (using Arduino functions)

### Dependencies
CharMatrix requires the [GyverGFX] library (https://github.com/GyverLibs/GyverGFX)

## Content
- [Install](#install)
- [CharMatrix](#matrix)
-[Charplot](#plot)
-[CharBar](#bar)
- [Versions](#versions)
- [Bugs and feedback](#feedback)

<a id="install"></a>
## Installation
- The library can be found by the name **CharDisplay** and installed through the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download library](https://github.com/GyverLibs/CharDisplay/archive/refs/heads/main.zip) .zip archive for manual installation:
    - Unzip and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Unzip and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/*
    - (Arduino IDE) automatic installation from .zip: *Sketch/Include library/Add .ZIP library…* and specify the downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE% D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="matrix"></a>
## CharMatrix
![matrix](/docs/matrix.png)
### Initialization
```cpp
CharMatrix<style> disp(width, height);

// styles:
CHAR_X1
CHAR_X2
CHAR_X4
CHAR_X8
```

### Drawing
Inherited from GyverGFX
```cpp
//fill:
// GFX_CLEAR - clear
// GFX_FILL - fill the shape
// GFX_STROKE - stroke the shape

void size(int x, int y); // set size
void dot(int x, int y, uint8_t fill = 1); // dot
void fill(uint8_t fill = 1); // fill
void clear(); // clear
void fastLineH(int y, int x0, int x1, uint8_t fill = 1); // vertical line
void fastLineV(int x, int y0, int y1, uint8_t fill = 1); // horizontal line
void line(int x0, int y0, int x1, int y1, uint8_t fill = 1); // line
void rect(int x0, int y0, int x1, int y1, uint8_t fill = 1); // rectangle
void roundRect(int x0, int y0, int x1, int y1, uint8_t fill = 1); // rounded rectangle
void circle(int x, int y, int radius, uint8_t fill = 1); // circle
void bezier(uint8_t* arr, uint8_t size, uint8_t dense, uint8_t fill = 1); // bezier curve
void bezier16(int* arr, uint8_t size, uint8_t dense, uint8_t fill = 1); // bezier curve 16 bit. fill - GFX_CLEAR/GFX_FILL/GFX_STROKE
void drawBitmap(int x, int y, const uint8_t *frame, int width, int height, uint8_t invert = 0, byte mode = 0); // bitmap

void setCursor(int x, int y); // set cursor
void setScale(uint8_tscale); // text scale
void invertText(bool inv); // invert text
void autoPrintln(bool mode); // automatic line break
void textDisplayMode(bool mode); // text output mode GFX_ADD/GFX_REPLACE
```

### Conclusion
```cpp
String render();
```

<a id="plot"></a>
##charplot
![plots](/docs/plots.png)
```cpp
String CharPlot<style>(float*, width (array size), height);
String CharPlot<style>(float*, width (array size), height, fill);
String CharPlot<style>(float*, width(array size), height, fill, border);

// fill (0, 1) - fill voids with spaces or dots (default 1)
// border (0, 1) - solid or double border style (default 0)

// styles:
LINE_X1
LINE_X2
COLON_X2
COLON_X1
```

<a id="bar"></a>
##charbar
![bars](/docs/bars.png)
```cpp
String CharBar<style>(size, padding 0-100);

// styles:
BAR_SQUARE
BAR_SQUARE2
BAR_SQUARE3
BAR_DIAMOND
BAR_RECT
BAR_RECT2
BAR_BLOCK
BAR_BLOCK2
BAR_CIRCLE
BAR_CIRCLE2
```

<a id="versions"></a>
## Versions
- v1.0

<a id="feedback"></a>
## Bugs and feedback
When you find bugs, create an **Issue**, or better, immediately write to the mail [alex@alexgyver.ru](mailto:alex@alexgyver.ru)
The library is open for revision and your **Pull Request**'s!