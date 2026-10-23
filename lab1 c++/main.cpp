#include <windows.h>
#include "AppManager.h"

int main(int argc, char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    AppManager app;
    app.run(argc, argv);
    
    return 0;
}