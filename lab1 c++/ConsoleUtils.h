#pragma once
#include <windows.h>

class ConsoleUtils {
public:
    static void clearScreen();

    static void setCursorPosition(int x, int y);

    static void setColor(int colorCode);

    static void resetColor();

    static void hideCursor();

    static void getConsoleSize(int& width, int& height);
};