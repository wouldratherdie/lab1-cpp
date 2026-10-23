#include "AppManager.h"
#include "ConsoleUtils.h"
#include "Line.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

AppManager::AppManager() : speed(0), length(0), epilepsyMode(false) {}

void AppManager::run(int argc, char* argv[]) {
    if (argc > 1) {
        if (parseArguments(argc, argv)) {
            startAnimation();
        }
        else {
            std::cout << "Error: Invalid arguments. Use --help for usage.\n";
        }
    }
    else {
        runDialogMode();
        startAnimation();
    }
}

void AppManager::printHelp() const {
    std::cout << "Usage:\n";
    std::cout << "  matrix.exe [speed] [length] [epilepsy(Y/N)]\n";
    std::cout << "  matrix.exe --help | /?\n\n";
    std::cout << "Parameters:\n";
    std::cout << "  speed    : 1-30 (characters per second)\n";
    std::cout << "  length   : 1-30 (characters)\n";
    std::cout << "  epilepsy : Y/N (enable/disable)\n";
}

bool AppManager::parseArguments(int argc, char* argv[]) {
    if (argc == 2) {
        std::string arg = argv[1];
        if (arg == "--help" || arg == "/?") {
            printHelp();
            exit(0);
        }
    }

    if (argc != 4) {
        return false;
    }

    try {
        int spd = std::stoi(argv[1]);
        int len = std::stoi(argv[2]);
        char epi = argv[3][0];

        if (validateParameters(spd, len, epi)) {
            speed = spd;
            length = len;
            epilepsyMode = (epi == 'Y' || epi == 'y');
            return true;
        }
    }
    catch (...) {
        return false;
    }
    return false;
}

bool AppManager::validateParameters(int spd, int len, char epi) {
    if (spd < 1 || spd > 30) return false;
    if (len < 1 || len > 30) return false;
    if (epi != 'Y' && epi != 'y' && epi != 'N' && epi != 'n') return false;
    return true;
}

void AppManager::runDialogMode() {
    ConsoleUtils::clearScreen();
    std::cout << "=== Matrix Configuration ===\n";

    while (true) {
        std::cout << "Enter speed (1-30): ";
        if (std::cin >> speed && speed >= 1 && speed <= 30) break;
        std::cout << "Invalid input. Try again.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    while (true) {
        std::cout << "Enter length (1-30): ";
        if (std::cin >> length && length >= 1 && length <= 30) break;
        std::cout << "Invalid input. Try again.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    char epi;
    while (true) {
        std::cout << "Enable epilepsy mode? (Y/N): ";
        if (std::cin >> epi && (epi == 'Y' || epi == 'y' || epi == 'N' || epi == 'n')) {
            epilepsyMode = (epi == 'Y' || epi == 'y');
            std::cin.ignore(10000, '\n');
            break;
        }
        std::cout << "Invalid input. Try again.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

void AppManager::startAnimation() {
    ConsoleUtils::clearScreen();
    ConsoleUtils::hideCursor();
    srand(static_cast<unsigned int>(time(nullptr)));

    int width, height;

    while (true) {
        ConsoleUtils::getConsoleSize(width, height);

        int startX = rand() % width;

        int colorCode = epilepsyMode ? (rand() % 15 + 1) : 2;

        Line line(length, speed, colorCode);
        line.spawn(startX, 0);

        while (!line.isFinished(height)) {
            line.moveDown(height);
            Sleep(1000 / speed);
        }

        ConsoleUtils::clearScreen();
    }
}