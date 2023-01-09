//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "MultimediaObject.h"
#include "Picture.h"
#include "Video.h"

using namespace std;

int main(int argc, const char* argv[])
{
    MultimediaObject ** tab = new MultimediaObject *[2];
    tab[0] = new Picture("testvid", "./imagetest.jpg", 3.1, 3.4);
    tab[1] = new Video("testvid", "./videotest.mp4", 34);
    for (int i=0; i<2; i++){
        tab[i]->display(cout);
        tab[i]->play();
    }
}