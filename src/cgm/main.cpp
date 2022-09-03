#include <iostream>
#include "include/cgm.h"
using namespace std;


int main(int argc, char *argv[]){
    cgm a;
    cout << "Argc: " << argc << endl;
    int state = a.parseCommand(argc, argv);
    cout << "Command: ";
    a.printcCommand();
    cout << "Arguments: ";
    a.printArguments();
    cout << "Flags: ";
    a.printFlags();

    cout << cgm::parseStateDescription(state) << endl;
    return 0;
}