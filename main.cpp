//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MultimediaObject.h"
#include "Picture.h"
#include "Video.h"
#include "Film.h"
#include "Group.h"
#include "DataBase.h"

using namespace std;

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
}