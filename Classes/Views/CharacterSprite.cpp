//
//  CharacterSprite.cpp
//  PixelPoem
//
//  Created by SuiYi on 1/4/16.
//
//

#include "CharacterSprite.hpp"
#include "FlipActions/FlipActionFactory.hpp"


CharacterSprite::CharacterSprite(CharacterTexture* texture)
{
    if (texture != nullptr)
    {
        _texture = texture;
        _texture->retain();
        
        if(texture->getTexture() != nullptr && texture->getCharacterId() != nullptr)
        {
            _sprite = Sprite::createWithTexture(texture->getTexture());
            
            _sprite->setOpacity(50);
            _isForeSide = false;
            _sprite->retain();
        }
    }
}

CharacterSprite::~CharacterSprite()
{
	if(_texture != NULL)
		_texture->release();
}

CharacterSprite* CharacterSprite::dummyValue()
{
    CharacterTexture* charTexture = CharacterTexture::dummyValue();
    CharacterSprite* sprite = new CharacterSprite(charTexture);
    sprite->autorelease();
    
    return sprite;
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

void CharacterSprite::setRotate(CharacterRotateType rotate)
{
    _rotateType = rotate;
}

Size CharacterSprite::getTextureSize()
{
    return _texture->getTexture()->getContentSize();
}

Size CharacterSprite::getScale()
{
    return Size(_widthInUnit, _heightInUnit);
}

Vec2 CharacterSprite::getPositionInUnit()
{
    return _positionInUnit;
}

CharacterRotateType CharacterSprite::getRotateType()
{
    return _rotateType;
}

Sprite* CharacterSprite::getSprite()
{
    return _sprite;
}

CharacterTexture* CharacterSprite::getTexture()
{
    return _texture;
}

bool CharacterSprite::isSame(CharacterSprite* another)
{
    if (_texture->getCharacterId() == nullptr)
        return false;
    
    return (_texture->getCharacterId()->isSame(another->getTexture()->getCharacterId()));
}

bool CharacterSprite::isForeSide()
{
    return _isForeSide;
}

void CharacterSprite::flip(float delayTime)
{
    if (_sprite == nullptr)
        return;
    
    
    _isForeSide = !_isForeSide;
    
    FlipCharacterAction* action = FlipActionFactory::createRandomAction();
    
    int opacity = 300 - _sprite->getOpacity();
    action->initialize(delayTime, 0.6f, opacity);
    action->takeFlip(_sprite);
    
    
    /*
    float curScaleX = _sprite->getScaleX();
    float curScaleY = _sprite->getScaleY();
    
    auto delay = DelayTime::create(delayTime);
    auto scale1 = ScaleTo::create(0.3f, 0.01f, curScaleY);
    auto fade = FadeTo::create(0, opacity);
    auto scale2 = ScaleTo::create(0.3f, curScaleX, curScaleY);
    
    auto sequence = Sequence::create(delay, scale1, fade, scale2, nullptr);
    _sprite->runAction(sequence);
    */
    
}