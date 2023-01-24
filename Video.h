#ifndef VIDEO
#define VIDEO

#include "MultimediaObject.h"

class Video : public MultimediaObject {
private :
    int duration{};
protected :
    Video(){}
    Video(
        std::string _name, 
        std::string _filepath, 
        int _duration) :
        MultimediaObject(_name,_filepath), duration{_duration} {}
    friend class DataBase;
public :
    ~Video() override {}
    void setDuration(float _duration) {duration = _duration;}
    float getDuration() const {return duration;}
    void display(std::ostream & os) const override {
        MultimediaObject::display(os);
        os << "duration : " << duration << "\n";
    }
    void play() const override {
        std::string arg = "mpv " + getFilePath() + " &";
        system(arg.data());
    }

};

#endif