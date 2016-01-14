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

typedef enum CharacterRotateType
{
	CharacterRotate_None,
	CharacterRotate_Left,
	CharacterRotate_Right
	
} CharacterRotateType;

class CharacterSprite : public Ref
{
private:
    
    CharacterTexture* _texture;
	// Texture2D* _rawTexture;
    Sprite* _sprite;
    
    Vec2 _positionInUnit;
    
    int _widthInUnit;
    int _heightInUnit;
    
    CharacterRotateType _rotateType;
    
public:
    
    CharacterSprite(Texture2D* texture);
    CharacterSprite(CharacterTexture* texture);
    virtual ~CharacterSprite();
    
    static CharacterSprite* dummyValue();
    
    void setPositionInUnit(Vec2 pos);
    void setScale(int charWidth, int charHeight);
    void setRotate(CharacterRotateType rotate);
    
    CharacterTexture* getTexture();
    Size getTextureSize();
    Size getScale();
    Vec2 getPositionInUnit();
    CharacterRotateType getRotateType();
    Sprite* getSprite();
    
    bool isSame(CharacterSprite* another);
    
    void flip(float delayTime);
};

#endif /* CharacterSprite_hpp */
