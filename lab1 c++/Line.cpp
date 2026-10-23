#include "Line.h"
#include "ConsoleUtils.h"

Line::Line(int len, int spd, int clr)
    : length(len), speed(spd), colorCode(clr), currentX(0), currentY(0) {}

Line::~Line() {
    for (Symbol* sym : symbols) {
        delete sym;
    }
    symbols.clear();
}

void Line::spawn(int startX, int startY) {
    currentX = startX;
    currentY = startY - length;
}

void Line::moveDown(int screenHeight) {
    char randomChar = 'A' + (rand() % 26);
    Symbol* newSymbol = new Symbol(randomChar, currentX, currentY, colorCode);

    if (currentY >= 0 && currentY < screenHeight) {
        newSymbol->draw();
    }
    symbols.push_back(newSymbol);

    if (symbols.size() > length) {
        Symbol* tail = symbols.front();

        if (tail->getY() >= 0 && tail->getY() < screenHeight) {
            tail->erase();
        }

        delete tail;
        symbols.erase(symbols.begin());
    }

    currentY++;
}

bool Line::isFinished(int screenHeight) const {
    return currentY > screenHeight + length;
}