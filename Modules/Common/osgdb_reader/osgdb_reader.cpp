#include "osgdb_reader.h"
#include <osgDB/ReadFile>
#include <iostream>
_declspec(dllexport) int OpenOsgbFile(std::string filename)
{
    auto node = osgDB::readNodeFile(filename);
    if (!node) {
        std::cout << "node is empty" << std::endl;
    }
    return 3;
}

