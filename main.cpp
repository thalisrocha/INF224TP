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

using namespace std;

int main(int argc, const char* argv[]){
    Group gr1 = Group("gr1");
    Group gr2 = Group("gr2");
    int * chapters = new int[4];
    chapters[0]=1;
    chapters[1]=2;
    chapters[2]=3;
    chapters[3]=4;
    MultimediaPtr pic (new Picture("test","./imagetest.jpg",10.,10.));
    MultimediaPtr vid (new Video("testvid","./videotest.mp4",10));
    MultimediaPtr film (new Film(chapters, 4, "filmtest","./videotest.mp4",10));
    gr1.push_back(pic);
    gr2.push_back(pic);
    gr2.push_back(film);
    pic.reset();
    vid.reset();
    film.reset();
    cout << "everythin reseted" << endl;
    gr2.pop_back();
    cout << "popped the film" << endl;
    gr1.display(cout);
    gr1.pop_back();
    gr2.pop_back();
    cout << "everything popped" << endl;
    gr2.display(cout);
}