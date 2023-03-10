#ifndef DATABASE
#define DATABASE

#include "MultimediaObject.h"
#include "Picture.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include <memory>
#include <string>
#include <map>

using GroupPtr = std::shared_ptr<Group>;


class DataBase{
    
    private :
        std::map<std::string, MultimediaPtr> objectsTable {};
        std::map<std::string, GroupPtr> groupsTable {};

    public :
        DataBase(){}
        MultimediaPtr createPicture(
            std::string _name,
            std::string _filepath,
            float _length,
            float _width
        ){
            MultimediaPtr pic (new Picture(_name,_filepath,_length,_width));
            objectsTable[_name] = pic;
            return pic;
        }
        MultimediaPtr createVideo(
            std::string _name,
            std::string _filepath,
            int _duration
        ){
            MultimediaPtr vid (new Video(_name,_filepath,_duration));
            objectsTable[_name] = vid;
            return vid;
        }
        MultimediaPtr createFilm(
            std::string _name,
            std::string _filepath,
            int _duration,
            int * _chapters,
            int _nb_chapters
        ){
            MultimediaPtr film (new Film(_name,_filepath,_duration,_chapters,_nb_chapters));
            objectsTable[_name] = film;
            return film;
        }
        GroupPtr createGroup(std::string _name){
            GroupPtr grp (new Group(_name));
            groupsTable[_name] = grp;
            return grp;
        }
        void displayObject(std::string name, std::ostream & os) const{
            auto search = objectsTable.find(name);
            if (search != objectsTable.end())
                search->second->display(os);
            else
                os << "Error : "<< name << " not found";
        }
        void displayGroup(std::string name, std::ostream &os) const {
            auto search = groupsTable.find(name);
            if (search != groupsTable.end())
                search->second->display(os);
            else
                os << "Error : "<< name << " not found";
        }
        bool playObject(std::string name) const {
            auto search = objectsTable.find(name);
            if (search != objectsTable.end()){
                search->second->play();
                return true;
            }
            else
                return false;
        }

        void removeObject(std::string name) {
            int found = objectsTable.erase(name);
            if (found) {
                for (auto const &group : groupsTable){
                        group.second->remove_if([=] (MultimediaPtr obj) {return obj->getName() == name;});
                }
            }
            else {
                std::cout << name << "not found\n";
            }
        }
        
        void removeGroup(std::string name){
            int found = groupsTable.erase(name);
            if (!found){
                std::cout << name << "not found\n";
            }
        }
};

#endif