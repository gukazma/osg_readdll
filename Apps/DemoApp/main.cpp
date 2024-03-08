#include <iostream>
#include <thread>
#include "osgdb_reader.h"
int main(int argc, char* argv[])
{
    int rnt = OpenOsgbFile("");
    std::cout << rnt << std::endl;
}
