//
// Created by el1sha on 8/27/22.
//

#ifndef CUTEGUI_PARSER_H
#define CUTEGUI_PARSER_H

#include <pugixml.hpp>
#include <iostream>

class XmlParser{
public:
    XmlParser();
    ~XmlParser();


    /// @param src path to file
    int loadDocument(std::string src);

    pugi::xml_document doc;
    pugi::xml_parse_result result;
};

#endif //CUTEGUI_PARSER_H
