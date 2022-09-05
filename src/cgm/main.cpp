#include <iostream>
using namespace std;
#include "include/cgm.h"


int main(int argc, char *argv[]){
    cout << "Argc: " << argc << endl;
    int state = cgm::parseCommand(argc, argv);
    cout << "Command: ";
    cgm::printcCommand();
    cout << "Arguments: ";
    cgm::printArguments();
    cout << "Flags: ";
    cgm::printFlags();
    cgm::execCommand();

    cout << cgm::parseStateDescription(state) << endl;

    return 0;
}