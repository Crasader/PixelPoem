//
//  PoemDiagram.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef PoemDiagram_hpp
#define PoemDiagram_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "../Common/Constants.hpp"
#include "../Common/Types.hpp"

USING_NS_CC;

class PixelColor : public Ref
{
private:
    
    unsigned char _red;
    unsigned char _green;
    unsigned char _blue;
    
public:
    
    PixelColor();
    PixelColor(unsigned char r, unsigned char g, unsigned char b);
    
    unsigned char getRed();
    unsigned char getGreen();
    unsigned char getBlue();
    
    bool isBlack();
};


class PoemDiagram : public Ref
{
private:
    
	// char* _name;
    
	int _diagramWidth;
	int _diagramHeight;
	
	PixelColor** _data;
    
    
public:
    
	static PoemDiagram* loadByName(const char* name);
    static PoemDiagram* loadFromFile(std::string & diagram_file);
    
    PoemDiagram(int w, int h);
    
    void setColor(int x, int y, PixelColor* color);
                  
    // void setWidth(int w);
    // void setHeight(int h);
    
	PixelColor* getValue(int i, int j);
    int getWidth();
	int getHeight();
	
};
#endif /* PoemDiagram_hpp */
