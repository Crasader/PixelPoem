//
//  CharacterSprite.hpp
//  PixelPoem
//
//  Created by SuiYi on 1/4/16.
//
//

#ifndef CharacterSprite_hpp
#define CharacterSprite_hpp

#include <stdio.h>


#include "cocos2d.h"
#include "../ObjectModels/CharacterTexture.hpp"

USING_NS_CC;

class CharacterSprite : public Ref
{
private:
    
    CharacterTexture* _texture;
    Vec2 _positionInUnit;
    
    int _widthInUnit;
    int _heightInUnit;
    
    int _rotateStatus;
    
public:
    
    CharacterSprite(CharacterTexture* texture);
    virtual ~CharacterSprite();
    
    static CharacterSprite* dummyValue();
    
    void setPositionInUnit(Vec2 pos);
    void setScale(int charWidth, int charHeight);
    void setRotate(int rotate);
    

    
    
    
    
};

#endif /* CharacterSprite_hpp */
