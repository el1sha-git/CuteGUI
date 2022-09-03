//
// Created by el1sha on 29.8.22.
//

#include "../include/cgm.h"
#include <unordered_map>
#include <cassert>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int cgm::parseCommand(int argc, char *argv[]) {

    if (argc > 1){
        this->command = argv[1];

        for (int i = 2; i < argc; ++i){
            std::string arg = argv[i];
            if (arg.rfind("--", 0) == 0){
                this->flags.push_back(arg);
            }
            else{
                this->arguments.push_back(arg);
            }
        }
    }
    return SUCCESS;
}

int cgm::startProject(std::string name){
    std::cout << name << std::endl;
    std::cout << std::filesystem::current_path() << std::endl;
    std::cout << std::filesystem::create_directory(name) << std::endl;
    std::cout << std::filesystem::create_directory(name+"/app") << std::endl;

    return 0;
}

int cgm::install() {
    return 0;
}