#ifndef GROUP
#define GROUP

#include "MultimediaObject.h"
#include <list>
#include <memory>

using MultimediaPtr = std::shared_ptr<MultimediaObject>;

class Group : public std::list<MultimediaPtr> {
    private :
        std::string name {};
        Group(){}
    protected :
        Group(std::string _name) : name{_name} {}
        friend class DataBase;
    public : 
        ~Group() {std::cout << "destroyed " << name << std::endl;}
        void display(std::ostream & os) const {
            os << "Name of group : " << name << std::endl;
            os << "This groups contains :" << std::endl << std::endl;
            for (auto  & obj : *this){
                obj->display(os);
                os << std::endl;
            }
        }
        std::string getName() const{
            return name;
        }
};

#endif