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
    MultimediaObject * pict = new Picture("testvid", "./imagetest.jpg", 3.1, 3.4);
    MultimediaObject * video = new Video("testvid", "./videotest.mp4", 34);
    pict->display(cout);
    video->display(cout);
    pict->play();
    video->play(); 
}
