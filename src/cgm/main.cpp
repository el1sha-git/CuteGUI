#include <iostream>
using namespace std;
#include "include/cgm.hpp"


int main(int argc, char *argv[]){
    cout << "Argc: " << argc << endl;
    int state = parseCommand(argc, argv);
    init_command_map();
    cout << "Command: ";
    printcCommand();
    cout << "Arguments: ";
    printArguments();
    cout << "Flags: ";
    printFlags();
    execCommand();

    cout << parseStateDescription(state) << endl;

    return 0;
}