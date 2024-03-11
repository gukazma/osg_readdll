#include "osgdb_reader.h"
#include <iostream>
#include <osgDB/ReadFile>
int* OpenOsgbFile(const char* file)
{
    osg::Node* node = osgDB::readNodeFile(file);
    return (int*)node;
}

void CloseOsgbFile(int* ptr)
{
    osg::Node* node = (osg::Node*)ptr;
    node->unref();
}

int GetChildCount(int* ptr)
{
    osg::Node* node = (osg::Node*)ptr;
    osg::Group* group = node->asGroup();
    if (!group) {
        return 0;
    }
    return group->getNumChildren();
}
