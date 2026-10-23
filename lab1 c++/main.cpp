#include <iostream>
#include <windows.h>
#include "ConsoleUtils.h"
#include "Symbol.h"

int main() {
    ConsoleUtils::clearScreen();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Symbol mySymbol('A', 10, 5, 2);

    mySymbol.draw();

    Sleep(1000);

    mySymbol.erase();

    Sleep(500);

    mySymbol.moveDown();
    mySymbol.draw();

    ConsoleUtils::setCursorPosition(0, 15);
    std::cout << "Тест завершен! Нажми Enter для выхода...";

    std::cin.get();

    return 0;
}