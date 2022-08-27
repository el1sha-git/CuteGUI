//
// Created by el1sha on 8/25/22.
//


#include <iostream>
#include "parser.h"



XmlDocument::XmlDocument(std::string filename){
    std::ifstream file(filename);
    boost::property_tree::read_xml(file, doc);
};



void XmlDocument::getElements(std::string path) {
    BOOST_FOREACH(boost::property_tree::ptree::value_type const &node, doc.get_child(path)) {
        boost::property_tree::ptree subtree = node.second;


        if (node.first == "record") {
            BOOST_FOREACH(boost::property_tree::ptree::value_type const &v, subtree.get_child("")) {
                std::string label = v.first;
//                std::cout << label << "\n-----------------\n" << std::endl;

//                if (label != "<xmlattr>") {
                    std::string value = subtree.get<std::string>(label);
                    std::cout << label << ":\t" << value << std::endl;
//                }
                if (label == "<xmlattr>") {
                            std::cout << "Attributes\n" << std::endl;
                            std::string value = subtree.get<std::string>("id");
                            std::cout << label << ":\t" << value << std::endl;
                }
            }
            std::cout << std::endl;
        }
    }
};

int main(){
    XmlDocument xml("./xml.xml");
    xml.getElements("root.notes");
//    xml.findElement("root.password.record.title");
    return 0;
}