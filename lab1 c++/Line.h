#pragma once
#include <vector>
#include "Symbol.h"

class Line {
private:
    std::vector<Symbol*> symbols;
    int length;
    int speed;
    int colorCode;
    int currentX;
    int currentY;

public:
    Line(int len, int spd, int clr);
    ~Line();

    void spawn(int startX, int startY);

    void moveDown(int screenHeight);

    bool isFinished(int screenHeight) const;

    int getSpeed() const { return speed; }
};