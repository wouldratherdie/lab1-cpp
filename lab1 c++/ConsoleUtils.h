#pragma once
#include <windows.h>

class ConsoleUtils {
public:
    // Очистить экран
    static void clearScreen();

    // Переместить курсор в координаты X, Y
    static void setCursorPosition(int x, int y);

    // Установить цвет текста (коды цветов Windows)
    static void setColor(int colorCode);

    // Сбросить цвет на стандартный (белый)
    static void resetColor();
};