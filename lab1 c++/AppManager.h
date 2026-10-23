#pragma once

class AppManager {
private:
    int speed;
    int length;
    bool epilepsyMode;

    bool parseArguments(int argc, char* argv[]);
    bool validateParameters(int spd, int len, char epi);
    void runDialogMode();
    void printHelp() const;
    void startAnimation();

public:
    AppManager();
    void run(int argc, char* argv[]);
};