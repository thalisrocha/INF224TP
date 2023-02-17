//
// main.cpp
// Created on 21/10/2018
//

#define VERSION_AVEC_SERVEUR

#include <memory>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "MultimediaObject.h"
#include "Picture.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "DataBase.h"
#include "tcpserver/ccsocket.h"
#include "tcpserver/tcpserver.h"

using namespace std;

#ifdef VERSION_SANS_SERVEUR

int main(int argc, const char* argv[]){
    DataBase * db = new DataBase();
    GroupPtr gr1 = db->createGroup("gr1");
    GroupPtr gr2 = db->createGroup("gr2");   
    int * chapters = new int[4];
    chapters[0]=1;
    chapters[1]=2;
    chapters[2]=3;
    chapters[3]=4;
    MultimediaPtr pic = db->createPicture("test","./imagetest.jpg",10.,10.);
    MultimediaPtr vid = db->createVideo("testvid","./videotest.mp4",10);
    MultimediaPtr film = db->createFilm("filmtest","./videotest.mp4",10,chapters,4);
    gr1->push_back(pic);
    gr2->push_back(pic);
    gr2->push_back(film);
    pic.reset();
    vid.reset();
    film.reset();
    cout << "everythin reseted" << endl;
    db->playObject("test");
    db->playObject("ahi");
    gr1->display(cout);
    gr2->display(cout);
    return 0;
}

#endif

#ifdef VERSION_AVEC_SERVEUR

const int PORT = 3332;


int main(int argc, char* argv[])
{
    DataBase * db = new DataBase();
    GroupPtr gr1 = db->createGroup("gr1");
    GroupPtr gr2 = db->createGroup("gr2");   
    int * chapters = new int[4];
    chapters[0]=1;
    chapters[1]=2;
    chapters[2]=3;
    chapters[3]=4;
    MultimediaPtr pic = db->createPicture("test","./imagetest.jpg",10.,10.);
    MultimediaPtr vid = db->createVideo("testvid","./videotest.mp4",10);
    MultimediaPtr film = db->createFilm("filmtest","./videotest.mp4",10,chapters,4);
    gr1->push_back(pic);
    gr2->push_back(pic);
    gr2->push_back(film);

    // cree le TCPServer
    auto* server =
    new TCPServer( [&](std::string const& request, std::string& response) {

        stringstream ssreq {request};
        stringstream ssres {};

        string verb {};
        string object {};
        
        ssreq >> verb;
        ssreq >> object;

        if (verb == "DisplayObject") {
            db->displayObject(object,ssres);
        }
        else if (verb == "DisplayGroup") {
            db->displayGroup(object,ssres);
        }
        else if (verb == "Play"){
            bool result = db->playObject(object);
            if (!result){
                ssres << "Error : Could not find" << verb;
            }
        }
        else {
            ssres << "Error : could not understand request";
        }

        response = ssres.str();
        // Replace spaces with pipes as delimiter in the response 
        replace(response.begin(),response.end(),'\n','|');
        // return false would close the connecytion with the client
        return true;
    });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
    }

#endif