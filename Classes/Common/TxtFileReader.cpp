//
//  TxtFileReader.cpp
//  PixelPoem
//
//  Created by SuiYi on 6/7/16.
//
//

#include "TxtFileReader.hpp"

using namespace std;

TxtFileReader::TxtFileReader(std::string relativePath)
{
    inputStream.open( FileUtils::getInstance()->fullPathForFilename(relativePath.c_str()).c_str());

    
}

TxtFileReader::~TxtFileReader()
{
    inputStream.close();
    
}

int TxtFileReader::readInt()
{
    string content = readString();
    return atoi(content.c_str());
}

string TxtFileReader::readString()
{
    char content[256];
    inputStream >> content;
    
    return content;
}