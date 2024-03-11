#include <iostream>
#include <thread>
#include "osgdb_reader.h"
int main(int argc, char* argv[])
{
    auto ptr = OpenOsgbFile("D:/data/osgb/Tile_+000_+001/Tile_+000_+001_L23_0000010.osgb");
    int  childnum = GetChildCount(ptr);
    std::cout << childnum << std::endl;
}
