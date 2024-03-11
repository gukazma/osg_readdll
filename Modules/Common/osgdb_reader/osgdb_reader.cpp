#include "osgdb_reader.h"
#include <iostream>
#include <osgDB/ReadFile>
void* OpenOsgbFile(const char* file)
{
    osg::Node* node = osgDB::readNodeFile(file);
    return (void*)node;
}

void CloseOsgbFile(void* ptr)
{
    osg::Node* node = (osg::Node*)ptr;
    node->unref();
}

int GetChildCount(void* ptr)
{
    osg::Node* node = (osg::Node*)ptr;
    osg::Group* group = node->asGroup();
    if (!group) {
        return 0;
    }
    return group->getNumChildren();
}
