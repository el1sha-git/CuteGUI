//
// Created by el1sha on 29.8.22.
//

#ifndef CUTEGUI_CGM_H
#define CUTEGUI_CGM_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cassert>



namespace cgm{

    std::string command;
    std::vector<std::string> arguments;
    std::vector<std::string> flags;

    std::map<std::string, int(*)()> commands_map;
    enum parseStates{
        SUCCESS,
        INVALID_COMMAND,
        INVALID_FLAG,
        INVALID_ARGUMENT,
    };
    int install();

    int uninstall();

    int lock();

    int sync();

    int startProject();




    void init_command_map(){
        commands_map.insert(std::pair<std::string, int(*)()>("install", install));
        commands_map.insert(std::pair<std::string, int(*)()>("startproject", startProject));
    }

    std::string parseStateDescription(int state){
        std::string state_decriptions[] ={
                "No Error",
                "Invalid Command",
                "Invalid Flag",
                "Invalid Argument"
        };
        return state_decriptions[state];
    }


    int parseCommand(int argc, char *argv[]);

    int execCommand();


    /// Dev funcs
    void printcCommand(){
        std::cout << command << std::endl;
    }

    void printArguments(){
        for(auto & argument : arguments){
            std::cout << argument << std::endl;
        }
    }
    void printFlags(){
        for(auto & flag : flags){
            std::cout << flag << std::endl;
        }
    }





};


#endif //CUTEGUI_CGM_H
