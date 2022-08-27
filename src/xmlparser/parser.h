//
// Created by el1sha on 8/25/22.
//

#ifndef CUTEGUI_PARSER_H
#define CUTEGUI_PARSER_H

#include <fstream>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

class XmlDocument{
public:
    XmlDocument(std::string filename);
    ~XmlDocument(){};

    struct Element{
        std::string *tagName;
        std::string *value;
    };



    void getElements(std::string path);

    void printDoc(std::string str){
        BOOST_FOREACH(auto &v, doc.get_child(str))
        {
            if(v.first != "<xmlattr>"){
                std::cout << "Title is " << v.second.get<std::string>("title") << std::endl;

            }
//            if(v.first == "<xmlattr>"){
//                std::cout << v.second.get<std::string>("icon") << std::endl;
//            }
        }
    }
    std::string get(std::string str){
        return doc.get<std::string>(str);
    }
private:
    std::string filename;
    boost::property_tree::ptree doc;
    std::vector<Element> passwords;
};

#endif //CUTEGUI_PARSER_H
