#include "Symbol.h"
#include "ConsoleUtils.h"
#include <iostream>

Symbol::Symbol(char ch, int startX, int startY, int color)
    : character(ch), x(startX), y(startY), colorCode(color) {}

void Symbol::draw() const {
    ConsoleUtils::setCursorPosition(x, y);
    ConsoleUtils::setColor(colorCode);
    std::cout << character;
    ConsoleUtils::resetColor();
}

void Symbol::erase() const {
    ConsoleUtils::setCursorPosition(x, y);
    std::cout << ' '; // Затираем пробелом
}

void Symbol::moveDown() {
    y++; // Двигаем вниз (ось Y в консоли идет вниз)
}