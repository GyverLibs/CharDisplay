This is an automatic translation and may be incorrect in some places. See the source README and examples for authoritative information.

[![latest](https://img.shields.io/github/v/release/GyverLibs/CharDisplay.svg?color=brightgreen)](https://github.com/GyverLibs/CharDisplay/releases/latest/download/CharDisplay.zip)
[![PIO](https://badges.registry.platformio.org/packages/gyverlibs/library/CharDisplay.svg)](https://registry.platformio.org/libraries/gyverlibs/CharDisplay)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg?style=flat-square)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD%24%E2%82%AC%20%D0%9F%D0%BE%D0%B4%D0%B4%D0%B5%D1%80%D0%B6%D0%B0%D1%82%D1%8C-%D0%B0%D0%B2%D1%82%D0%BE%D1%80%D0%B0-orange.svg?style=flat-square)](https://alexgyver.ru/support_alex/)
[![Foo](https://img.shields.io/badge/README-ENGLISH-blueviolet.svg?style=flat-square)](https://github-com.translate.goog/GyverLibs/CharDisplay?_x_tr_sl=ru&_x_tr_tl=en)  

[![Foo](https://img.shields.io/badge/ПОДПИСАТЬСЯ-НА%20ОБНОВЛЕНИЯ-brightgreen.svg?style=social&logo=telegram&color=blue)](https://t.me/GyverLibs)

# CharDisplay
Library for creating symbolic graphics:
- **CharMatrix** - Matrix for full-fledged drawing (4 styles)
- **CharBar** - Download lanes (10 styles)
- **CharPlot** - Graphics (4 styles + 2 styles of filling + 2 styles of frame)

Excellent for visualizing data in reports when sent by mail or through[Telegram bot](https://github.com/GyverLibs/FastBot)**Attention! ** It's not normally displayed everywhere, you need a monowidth font.

### Compatibility
Compatible with all Arduino platforms (Arduino features are used)

### Dependencies
- [GyverGFX](https://github.com/GyverLibs/GyverGFX)
- [BitPack](https://github.com/GyverLibs/BitPack)

## Contents
- [CharMatrix](#matrix)
- [CharPlot](#plot)
- [CharBar](#bar)
- [Versions](#versions)
- [Installation](#install)
- [Bugs and feedback](#feedback)

<a id="matrix"></a>

## CharMatrix
![matrix](/docs/matrix.png)
### Initialization
```cpp
CharMatrix<стиль> disp(ширина, высота);

// styles:
CHAR_X1
CHAR_X2
CHAR_X4
CHAR_X8
```

Before connecting the library, you can specify the symbols that display the style.`CHAR_X1`. For example:
```cpp
#define CM_X1_CLEAR ' '
#define CM_X1_FILL '#'

// #define CM_X1_CLEAR "[]"
// #define CM_X1_FILL "██"

#include <CharMatrix.h>
CharMatrix<CHAR_X1> disp(32, 12);
```

### Drawing
Inherited from[GyverGFX](https://github.com/GyverLibs/GyverGFX)

### Conclusion
```cpp
// print
size_t printTo(Print& p);

// pull out
String render();
```

<a id="plot"></a>

## CharPlot
![plots](/docs/plots.png)
```cpp
String CharPlot<стиль>(float*, ширина (размер массива), высота);
String CharPlot<стиль>(float*, ширина (размер массива), высота, fill);
String CharPlot<стиль>(float*, ширина (размер массива), высота, fill, border);

// fill (0, 1) - fill the voids with spaces or points (silent). 1)
// border (0, 1) - solid or double frame style (silent 0)

// styles:
LINE_X1
LINE_X2
COLON_X2
COLON_X1
```

<a id="bar"></a>

## CharBar
![bars](/docs/bars.png)
```cpp
String CharBar<стиль>(размер, заполнение 0-100);

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
- v1.0.1 - refill
- v1.1.0 - improved CharMatrix acceleration, added output to Print

<a id="install"></a>

## Installation
- The library can be found under the name **CharDisplay** and installed through the library manager in:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Download the library](https://github.com/GyverLibs/CharDisplay/archive/refs/heads/main.zip).zip archive for manual installation:
    - Unpack and put in *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Unpack and put in *C:\Program Files\Arduino\libraries* (Windows x32)
    - Unpack and put in *Documents/Arduino/libraries/ *
    - (Arduino IDE) Automatic installation from .zip: *Sketch/Connect library/Add .ZIP library...* and specify downloaded archive
- Read more detailed instructions for installing libraries[here](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: new versions fix errors and bugs, as well as optimize and add new features.
- Through the library manager IDE: find the library as when installing and click "Update"
- Manually: **Delete the folder with the old version** and then put the new one in its place. “Replacement” can not be done: sometimes new versions delete files that will remain when replaced and can lead to errors!

<a id="feedback"></a>

## Bugs and feedback
If you find bugs, create **Issue**, or better write to the mail immediately.[alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
The library is open for revision and your **Pull Requests*!

When reporting bugs or incorrect work of the library, it is necessary to specify:
- Library version
- What is used by the IC
- SDK version (for ESP)
- Arduino IDE version
- Are embedded examples that use features and designs that cause bugs in your code working correctly?
- What code was downloaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed. Not a canvas of a thousand lines, but a minimum code.
