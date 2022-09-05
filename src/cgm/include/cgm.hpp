//
// Created by el1sha on 29.8.22.
//

#ifndef CUTEGUI_CGM_HPP
#define CUTEGUI_CGM_HPP

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <filesystem>
#include "../include/config.h"



namespace fs = std::filesystem;

std::string command;
std::vector<std::string> arguments;
std::vector<std::string> flags;

std::map<std::string, int(*)()> commands_map;

enum parseStates{
    SUCCESS,
    INVALID_COMMAND,
    INVALID_FLAG,
    INVALID_ARGUMENT
};
    int install(){
        std::cout << "\nInstall command\n" << std::endl;
        return 0;
    }

    int uninstall();

    int lock();

    int sync();

    int startProject(){
        std::string name = arguments[0];
        fs::path current = fs::current_path();
        std::cout << name << std::endl;
        std::cout << current << std::endl;
        fs::create_directory(name);
        fs::create_directory(name + "/app");

        const auto copyOptions = fs::copy_options::update_existing
                                 | fs::copy_options::recursive
        ;
        fs::copy(PROJECT_BASE_TEMPLATE_PATH, name, copyOptions);

        return 0;
    }




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


    int parseCommand(int argc, char *argv[]){
        if (argc > 1){
            command = argv[1];

            for (int i = 2; i < argc; ++i){
                std::string arg = argv[i];
                if (arg.rfind("--", 0) == 0){
                    flags.push_back(arg);
                }
                else{
                    arguments.push_back(arg);
                }
            }
        }
        return SUCCESS;
    }

    int execCommand(){
        auto it = commands_map.find(command);
        if(it != commands_map.end()){
            it->second();
        }else{
            std::cout << "Invalid command!" << std::endl;
        }
        return 0;
    }


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


#endif //CUTEGUI_CGM_HPP
