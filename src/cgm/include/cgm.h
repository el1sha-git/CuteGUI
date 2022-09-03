//
// Created by el1sha on 29.8.22.
//

#ifndef CUTEGUI_CGM_H
#define CUTEGUI_CGM_H

#include <string>
#include <iostream>
#include <vector>

class cgm{
public:
    cgm(){

    };
    ~cgm(){

    };

    std::string parseStateDescription(int state){
        std::string state_decriptions[] ={
                "No Error",
                "Invalid Command",
                "Invalid Flag",
                "Invalid Argument"
        };
        return state_decriptions[state];
    }

    int startProject(std::string name);

    int parseCommand(int argc, char *argv[]);

    void printcCommand(){
        std::cout << this->command << std::endl;
    }

    void printArguments(){
        for(int i = 0; i < this->arguments.size(); ++i){
            std::cout << this->arguments[i] << std::endl;
        }
    }
    void printFlags(){
        for(int i = 0; i < this->flags.size(); ++i){
            std::cout << this->flags[i] << std::endl;
        }
    }

    int install();

    int uninstall();

    int lock();

    int sync();
private:
    std::string command;
    std::vector<std::string> arguments;
    std::vector<std::string> flags;

    enum parseStates{
        SUCCESS,
        INVALID_COMMAND,
        INVALID_FLAG,
        INVALID_ARGUMENT,
    };
};

#endif //CUTEGUI_CGM_H
