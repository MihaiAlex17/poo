#include "Aeroport.h"
class Meniu{

private:
    bool running;
    int input;
    Aeroport a;
    static Meniu* instancePtr;
public:
    Meniu();
    static Meniu* getInstance();
    void DisplayMeniu();
    void TakeMenuOption();
    bool getRunning();
};

