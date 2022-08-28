//
// Created by el1sha on 8/27/22.
//
#include "../include/parser.h"

XmlParser::XmlParser(){

};

XmlParser::~XmlParser(){
    // Clear tree
    doc.reset();
}

int XmlParser::loadDocument(std::string src){
    result = doc.load_file(src.c_str());
    return result.status;
};

