//
//  PoemDiagram.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "PoemDiagram.hpp"
#include "cocos2d.h"

USING_NS_CC;

PixelColor::PixelColor()
{
}

PixelColor::PixelColor(unsigned char r, unsigned char g, unsigned char b)
{
    _red = r;
    _green = g;
    _blue = b;
}

PoemDiagram::PoemDiagram(int w, int h)
{
    _diagramWidth = w;
    _diagramHeight = h;
    
    _data = new PixelColor*[w * h];
}

PoemDiagram* PoemDiagram::loadByName(const char* name)
{
    return NULL;
}

PoemDiagram* PoemDiagram::loadFromFile(const char* diagramfile)
{
    std::string fullpath = FileUtils::getInstance()->fullPathForFilename(diagramfile);
    FILE *in = fopen(fullpath.c_str(), "r");
    
    int width, height;
    
    width = (int)fgetc(in);
    fgetc(in);
    fgetc(in);
    fgetc(in);
    height = (int)fgetc(in);
    fgetc(in);
    fgetc(in);
    fgetc(in);
    
    PoemDiagram* diagram = new PoemDiagram(width, height);
    
    for(int j = 0; j < height; j++)
    {
        for(int i = 0 ; i < width; i++)
        {
            char r = fgetc(in);
            char g = fgetc(in);
            char b = fgetc(in);
            PixelColor* clr = new PixelColor(r, g, b);
            diagram->setColor(i, j, clr);
        }
    }
    
    fclose(in);
    
    diagram->autorelease();
    return diagram;
}

void PoemDiagram::setColor(int x, int y, PixelColor* color)
{
    _data[x + _diagramWidth * y] = color;
}

PixelColor* PoemDiagram::getValue(int i, int j)
{
    return _data[i + _diagramWidth * j];
}

int PoemDiagram::getWidth()
{
    return _diagramWidth;
}

int PoemDiagram::getHeight()
{
    return _diagramHeight;
}

unsigned char PixelColor::getRed()
{
    return _red;
}

unsigned char PixelColor::getGreen()
{
    return _green;
}

unsigned char PixelColor::getBlue()
{
    return _blue;
}

bool PixelColor::isBlack()
{
    return (_red < 127 && _green < 127 && _blue < 127);
}