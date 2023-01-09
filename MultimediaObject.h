#ifndef MULTIMEDIA_OBJECT
#define MULTIMEDIA_OBJECT

#include <iostream>
#include <string>

class MultimediaObject {
private :
    std::string name{};
    std::string filepath{};

public :
    MultimediaObject() {}
    MultimediaObject(std::string name, std::string filepath);
    virtual ~MultimediaObject() {}
    std::string getName() const {return name;}
    std::string getFilePath() const {return filepath;}
    void setName(std::string _name) {name = _name;}
    void setFilePath(std::string _filepath) {filepath = _filepath;}
    virtual void display (std::ostream & os) const;
    virtual void play() const = 0;
};

#endif
