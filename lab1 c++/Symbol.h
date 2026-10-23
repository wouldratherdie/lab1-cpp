#pragma once

class Symbol {
private:
    char character; // Сам символ
    int x;          // Координата X
    int y;          // Координата Y
    int colorCode;  // Цвет символа

public:
    // Конструктор
    Symbol(char ch, int startX, int startY, int color);

    // Нарисовать символ
    void draw() const;

    // Стереть символ (пробелом)
    void erase() const;

    // Сдвинуть символ вниз
    void moveDown();

    // Геттеры
    int getX() const { return x; }
    int getY() const { return y; }
};