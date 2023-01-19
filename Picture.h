#ifndef PICTURE
#define PICTURE

#include "MultimediaObject.h"

class Picture : public MultimediaObject {
private :
    float length{};
    float width{};

public :
    Picture(){}
    Picture(
        std::string _name,
        std::string _filepath,
        float _length, 
        float _width
        ) : MultimediaObject(_name,_filepath), length{_length}, width{_width} {}
    ~Picture() override {}
    void setWidth(float _width) {width = _width;}
    float getWidth() const {return width;}
    void setLength(float _length) {length = _length;}
    float getLength() const {return length;}
    void display(std::ostream & os) const override {
        MultimediaObject::display(os);
        os << "length : " << length
        << "\n width : " << width << "\n";
    }
    void play() const override {
        std::string arg = "imagej " + getFilePath() + " &";
        system(arg.data());
    }

};

#endif