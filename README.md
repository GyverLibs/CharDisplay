[![latest](https://img.shields.io/github/v/release/GyverLibs/CharDisplay.svg?color=brightgreen)](https://github.com/GyverLibs/CharDisplay/releases/latest/download/CharDisplay.zip)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg?style=flat-square)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD$%E2%82%AC%20%D0%9D%D0%B0%20%D0%BF%D0%B8%D0%B2%D0%BE-%D1%81%20%D1%80%D1%8B%D0%B1%D0%BA%D0%BE%D0%B9-orange.svg?style=flat-square)](https://alexgyver.ru/support_alex/)
[![Foo](https://img.shields.io/badge/README-ENGLISH-blueviolet.svg?style=flat-square)](https://github-com.translate.goog/GyverLibs/CharDisplay?_x_tr_sl=ru&_x_tr_tl=en)  

[![Foo](https://img.shields.io/badge/ПОДПИСАТЬСЯ-НА%20ОБНОВЛЕНИЯ-brightgreen.svg?style=social&logo=telegram&color=blue)](https://t.me/GyverLibs)

# CharDisplay
Библиотека для создания символьной графики:
- **CharMatrix** - Матрица для полноценного рисования (4 стиля)
- **CharBar** - Полосы загрузки (10 стилей)
- **CharPlot** - График (4 стиля + 2 стиля заполнения + 2 стиля рамки)

Отлично подходит для визуализации данных в отчётах при отправке на почту или через [Телеграм-бота](https://github.com/GyverLibs/FastBot)  
**Внимание!** Нормально отображается не везде, нужен моноширинный шрифт.

### Совместимость
Совместима со всеми Arduino платформами (используются Arduino-функции)

### Зависимости
Для работы CharMatrix нужна библиотека [GyverGFX](https://github.com/GyverLibs/GyverGFX)

## Содержание
- [Установка](#install)
- [CharMatrix](#matrix)
- [CharPlot](#plot)
- [CharBar](#bar)
- [Версии](#versions)
- [Баги и обратная связь](#feedback)

<a id="install"></a>
## Установка
- Библиотеку можно найти по названию **CharDisplay** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://github.com/GyverLibs/CharDisplay/archive/refs/heads/main.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
- Читай более подробную инструкцию по установке библиотек [здесь](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Обновление
- Рекомендую всегда обновлять библиотеку: в новых версиях исправляются ошибки и баги, а также проводится оптимизация и добавляются новые фичи
- Через менеджер библиотек IDE: найти библиотеку как при установке и нажать "Обновить"
- Вручную: **удалить папку со старой версией**, а затем положить на её место новую. "Замену" делать нельзя: иногда в новых версиях удаляются файлы, которые останутся при замене и могут привести к ошибкам!


<a id="matrix"></a>
## CharMatrix
![matrix](/docs/matrix.png)
### Инициализация
```cpp
CharMatrix<стиль> disp(ширина, высота);

// стили:
CHAR_X1
CHAR_X2
CHAR_X4
CHAR_X8
```

### Рисование
Наследуется из GyverGFX
```cpp
// fill:
// GFX_CLEAR - очистить
// GFX_FILL - залить фигуру
// GFX_STROKE - обвести фигуру

void size(int x, int y);                                            // установить размер
void dot(int x, int y, uint8_t fill = 1);                           // точка
void fill(uint8_t fill = 1);                                        // залить
void clear();                                                       // очистить
void fastLineH(int y, int x0, int x1, uint8_t fill = 1);            // вертикальная линия
void fastLineV(int x, int y0, int y1, uint8_t fill = 1);            // горизонтальная линия
void line(int x0, int y0, int x1, int y1, uint8_t fill = 1);        // линия
void rect(int x0, int y0, int x1, int y1, uint8_t fill = 1);        // прямоугольник
void roundRect(int x0, int y0, int x1, int y1, uint8_t fill = 1);   // скруглённый прямоугольник
void circle(int x, int y, int radius, uint8_t fill = 1);            // окружность
void bezier(uint8_t* arr, uint8_t size, uint8_t dense, uint8_t fill = 1);   // кривая Безье
void bezier16(int* arr, uint8_t size, uint8_t dense, uint8_t fill = 1);     // кривая Безье 16 бит. fill - GFX_CLEAR/GFX_FILL/GFX_STROKE
void drawBitmap(int x, int y, const uint8_t *frame, int width, int height, uint8_t invert = 0, byte mode = 0);  // битмап

print()/println() любые данные и текст (+ русский язык)
void setCursor(int x, int y);           // установить курсор
void setScale(uint8_t scale);           // масштаб текста
void invertText(bool inv);              // инвертировать текст
void autoPrintln(bool mode);            // автоматический перенос строки
void textDisplayMode(bool mode);        // режим вывода текста GFX_ADD/GFX_REPLACE
```

### Вывод
```cpp
String render();
```

<a id="plot"></a>
## CharPlot
![plots](/docs/plots.png)
```cpp
String CharPlot<стиль>(float*, ширина (размер массива), высота);
String CharPlot<стиль>(float*, ширина (размер массива), высота, fill);
String CharPlot<стиль>(float*, ширина (размер массива), высота, fill, border);

// fill (0, 1) - заполнять пустоты пробелами или точками (умолч. 1)
// border (0, 1) - сплошной или двойной стиль рамки (умолч. 0)

// стили:
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

// стили:
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
## Версии
- v1.0

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!


При сообщении о багах или некорректной работе библиотеки нужно обязательно указывать:
- Версия библиотеки
- Какой используется МК
- Версия SDK (для ESP)
- Версия Arduino IDE
- Корректно ли работают ли встроенные примеры, в которых используются функции и конструкции, приводящие к багу в вашем коде
- Какой код загружался, какая работа от него ожидалась и как он работает в реальности
- В идеале приложить минимальный код, в котором наблюдается баг. Не полотно из тысячи строк, а минимальный код
