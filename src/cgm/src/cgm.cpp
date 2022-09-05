//
// Created by el1sha on 29.8.22.
//

#include "../include/cgm.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include "../include/config.h"

namespace fs = std::filesystem;

int cgm::parseCommand(int argc, char *argv[]) {

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

int cgm::startProject() {
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

int cgm::install() {
    std::cout << "install" << std::endl;
    return 0;
}

int cgm::execCommand(){

    auto it = cgm::commands_map.find(cgm::command);
    if(it != cgm::commands_map.end()){
        it->second();
    }else{
        std::cout << "Invalid command!" << std::endl;
    }
    return 0;
};