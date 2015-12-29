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
    
    int* _characterIndexes;  // Pointing to the corresponding character
    
    Vector<PixelCharacter*> _characters;
    
    
public:
    
    PixelPanel();
    PixelPanel(GameDefinition* def);
    PixelPanel(GameRecord* record);
    
    
    
};

#endif /* PixelPanel_hpp */
