//
//  PoemPanel.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef PoemPanel_hpp
#define PoemPanel_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "../Common/Constants.hpp"
#include "GameRecord.hpp"
#include "GameDefinition.hpp"

USING_NS_CC;

class PoemPanel : public Ref
{
private:
    
	PoemDefinition* _definition;
	
	char* _defaultFont;
	char* _defaultStyle;
	
	int _pixelUnitWidth;
	int _pixelUnitHeight;
	float _defaultStretchX;
	float _defaultStretchY;
	
	Sprite* _baseSprite;
    
    
    
public:
    
    PoemPanel();
    PoemPanel(PoemDefinition* def);
    
    
    
};

#endif /* PoemPanel_hpp */
