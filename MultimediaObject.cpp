#include "MultimediaObject.h"

MultimediaObject::MultimediaObject(std::string _name, std::string _filepath){
    name = _name;
    filepath = _filepath;
}


void MultimediaObject::display (std::ostream &os) const{
    os << "name : " << name << "\nfilepath : " << filepath << "\n";
}