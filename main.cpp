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

    Film * vid = new Film();
    vid->display(cout);
    delete vid;
}