//
//  PixelPanel.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef PixelPanel_hpp
#define PixelPanel_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "../Common/Constants.hpp"
#include "GameRecord.hpp"
#include "GameDefinition.hpp"

USING_NS_CC;

class PixelPanel : public Ref
{
private:
    
    GameDefinition* _definition;
    Sprite* _baseSprite;
    
    int[][] _characterIndexes;  // Map pointing to the corresponding character
    
    Vector<PixelCharacter*>* _pixelCharacters;
    
    float _defaultStretchX;
	float _defaultStretchY;
	
	char* _defaultFont;
	char* _defaultStyle;
	
	int _pixelUnitWidth;
	int _pixelUnitHeight;
	
	int _maxUnitScaleX;
	int _maxUnitScaleY;
	
	
	
	
	
public:
    
    PixelPanel();
    PixelPanel(GameDefinition* def);
    PixelPanel(GameRecord* record);
    
    void generatePixelCharacters();
    
};

#endif /* PixelPanel_hpp */
