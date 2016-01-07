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


class PoemDiagram : public Ref
{
private:
    
	// char* _name;
    
	int _diagramWidth;
	int _diagramHeight;
	
	int* _data;
    
    
public:
    
	static PoemDiagram* loadByName(const char* name);
    static PoemDiagram* loadFromFile(const char* diagram_file);
    
	int getValue(int i, int j);
    int getWidth();
	int getHeight();
	
};
#endif /* PoemDiagram_hpp */
