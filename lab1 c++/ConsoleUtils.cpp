#include "ConsoleUtils.h"
#include <iostream>

void ConsoleUtils::clearScreen() {
    system("cls");
}

void ConsoleUtils::setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, pos);
}

void ConsoleUtils::setColor(int colorCode) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

void ConsoleUtils::resetColor() {
    setColor(7); // 7 - стандартный белый цвет
}