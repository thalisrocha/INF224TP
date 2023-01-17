//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MultimediaObject.h"
#include "Picture.h"
#include "Video.h"
#include "Film.h"

using namespace std;

int main(int argc, const char* argv[])
{
    int tab[2] = {1,2};
    Film * vid = new Film(tab,2,"test","./videotest.mp4",10);
    Film * vid2= new Film();
    *vid2=*vid;
    int * tab2 = vid->getChapters();
    tab2[0]=4;
    vid->display(cout);
    vid2->display(cout);
    cout << tab[0];
}