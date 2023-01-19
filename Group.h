#ifndef GROUP
#define GROUP

#include "MultimediaObject.h"
#include <list>
#include <memory>

using MultimediaPtr = std::shared_ptr<MultimediaObject>;

class Group : public std::list<MultimediaPtr> {
    private :
        std::string name {};
    public : 
        Group(){}
        Group(std::string _name) : name{_name} {}
        void display(std::ostream & os) const {
            for (auto  & obj : *this){
                obj->display(os);
            }
        }
        std::string getName() const{
            return name;
        }
};

#endif