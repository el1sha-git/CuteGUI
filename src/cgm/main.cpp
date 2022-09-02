#include <iostream>
#include "include/cgm.h"
using namespace std;


int main(int argc, char *argv[]){
    cgm a;
    cout << "Argc: " << argc << endl;
    a.parseCommand(argc, argv);
    cout << "Command: ";
    a.printcCommand();
    cout << "Arguments: ";
    a.printArguments();
    cout << "Flags: ";
    a.printFlags();
    return 0;
}