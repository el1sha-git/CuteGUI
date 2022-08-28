#include <iostream>
#include "include/parser.h"
#include <pugixml.hpp>
using namespace std;

int main(){
    XmlParser xml;
    if(xml.loadDocument("../src/parser/example.xml")){
        cout << "Seccusesful loading\n";
    };
    pugi::xml_node pg = xml.doc.child("root");
    cout << pg.child("div").text().get();
    return 0;
}