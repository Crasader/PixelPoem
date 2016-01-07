//
//  CharacterSprite.cpp
//  PixelPoem
//
//  Created by SuiYi on 1/4/16.
//
//

#include "CharacterSprite.hpp"

CharacterSprite::CharacterSprite(CharacterTexture* texture)
{
    
    _texture = texture;
    
    
    _texture->retain();
}

CharacterSprite::~CharacterSprite()
{
    _texture->release();
}

void CharacterSprite::setPositionInUnit(Vec2 pos)
{
    _positionInUnit = pos;
}

void CharacterSprite::setScale(int charWidth, int charHeight)
{
    _widthInUnit = charWidth;
    _heightInUnit = charHeight;
}

void CharacterSprite::setRotate(int rotate)
{
    _rotateStatus = rotate;
}
