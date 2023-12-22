This is an automatic translation, may be incorrect in some places. See sources and examples!

# Chardisplay
Library for creating symbolic graphics:
- ** charmatrix ** - matrix for full -fledged drawing (4 styles)
- ** charbar ** - Loading strips (10 styles)
- ** charplot ** - graph (4 styles + 2 settings + 2 styles of frame)

Great for visualization of data in reports when sending to the mail or through [telegram-bot] (https://github.com/gyverlibs/fastbot)
** Attention! ** It is not displayed normally everywhere, you need a monomeric font.

## compatibility
Compatible with all arduino platforms (used arduino functions)

### Dependencies
To work Charmatrix, you need a library [gyvergfx] (https://github.com/gyverlibs/gyvergfx)

## Content
- [installation] (# Install)
- [charmatrix] (#matrix)
- [charplot] (#plot)
- [charbar] (#bar)
- [versions] (#varsions)
- [bugs and feedback] (#fedback)

<a id="install"> </a>
## Installation
- The library can be found according to the name ** champlay ** and installed through the library manager in:
    - Arduino ide
    - Arduino ide v2
    - Platformio
- [download library] (https://github.com/gyverlibs/chardisplay/archive/refs/heads/main.zip). Zip archive for manual installation:
    - unpack and put in * C: \ Program Files (X86) \ Arduino \ Libraries * (Windows X64)
    - unpack and put in * C: \ Program Files \ Arduino \ Libraries * (Windows X32)
    - unpack and put in *documents/arduino/libraries/ *
    - (Arduino id) Automatic installation from. Zip: * sketch/connect the library/add .Zip library ... * and specify downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%BD%D0%BE%BE%BE%BED0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: errors and bugs are corrected in the new versions, as well as optimization and new features are added
- through the IDE library manager: find the library how to install and click "update"
- Manually: ** remove the folder with the old version **, and then put a new one in its place.“Replacement” cannot be done: sometimes in new versions, files that remain when replacing are deleted and can lead to errors!


<a id="Matrix"> </a>
## Charmatrix
! [Matrix] (/doc/matrix.png)
## H initialization
`` `CPP
Charmatrix <style> disp (width, height);

// Styles:
Char_x1
Char_x2
Char_X4
Char_x8
`` `

### Drawing
Inherited from Gyvergfx
`` `CPP
// Fill:
// GFX_Clear - clean
// gfx_fill - pour the figure
// gfx_stroke - circle the figure

VOID Size (int X, int y);// Set the size
VOID DOT (Int X, Int Y, UINT8_T FILL = 1);// dot
VOID Fill (uint8_t fill = 1);// Pour
Void Clear ();// Clean
VOID FASTLINEH (Int Y, Int X0, Int X1, UINT8_T FILL = 1);// Vertical line
VOID FASTLINEV (Int X, Int Y0, Int Y1, UINT8_T FILL = 1);// horizontal line
VOID Line (Int X0, Int Y0, Int X1, Int Y1, UINT8_T FILL = 1);// Line
VOID RECT (Int X0, Int Y0, Int X1, Int Y1, UINT8_T FILL = 1);// rectangle
VOID Roundrect (Int X0, Int Y0, Int X1, Int Y1, UInt8_t fill = 1);// rounded rectangle
VOID Circle (Int X, Int y, int radius, uint8_t fill = 1);// circle
VOID Bezier (uint8_t* arr, uint8_t size, uint8_t dense, uint8_t fill = 1);// Curve Bezier
VOID Bezier16 (int* arr, uint8_t size, uint8_t dense, uint8_t fill = 1);// Curve Bezier 16 bits.Fill - GFX_Clear/GFX_Fill/GFX_STROKE
VOID DRAWBITMAP (Int X, Int Y, COST UINT8_T *FRAME, Int width, int Height, Uint8_t Invert = 0, Byte Mode = 0);// Bitmap

Print ()/println () Any data and text (+ Russian)
VOID setcursor (Int X, Int y);// install the cursor
VOID Setscale (Uint8_T Scale);// The scale of the text
VOID Invertext (Bool Inv);// Invert the text
Void Autoprintln (Bool Mode);// Automatic line transfer
VOID TextDisplayMode (Bool Mode);// Text output mode gfx_add/gfx_replas
`` `

### Conclusion
`` `CPP
String Render ();
`` `

<a id="plot"> </a>
## Charplot
! [Plots] (/doc/plots.png)
`` `CPP
String Charplot <style> (float*, width (array size), height);
String Charplot <style> (float*, width (array size), height, fill);
String Charplot <style> (Float*, width (array size), height, fill, border);

// Fill (0, 1) - fill the voids with gaps or dots (silence 1)
// border (0, 1) - continuous or double style of the frame (silence 0)

// Styles:
Line_x1
Line_x2
Colon_x2
Colon_x1
`` `

<a id="bar"> </a>
## Charbar
! [Bars] (/doc/bars.png)
`` `CPP
String charbar <style> (size, filling 0-100);

// Styles:
Bar_SQUARE
Bar_SQUARE2
Bar_SQUARE3
Bar_DIAMOND
Bar_rect
Bar_rect2
Bar_block
Bar_block2
Bar_circle
Bar_circle2
`` `

<a id="versions"> </a>
## versions
- V1.0
- v1.0.1 - re -called

<a id="feedback"> </a>
## bugs and feedback
Create ** Issue ** when you find the bugs, and better immediately write to the mail [alex@alexgyver.ru] (mailto: alex@alexgyver.ru)
The library is open for refinement and your ** pull Request ** 'ow!


When reporting about bugs or incorrect work of the library, it is necessary to indicate:
- The version of the library
- What is MK used
- SDK version (for ESP)
- version of Arduino ide
- whether the built -in examples work correctly, in which the functions and designs are used, leading to a bug in your code
- what code has been loaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed.Not a canvas of a thousand lines, but a minimum code