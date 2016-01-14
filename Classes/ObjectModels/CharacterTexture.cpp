//
//  CharacterTexture.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "CharacterTexture.hpp"

CharacterTexture::CharacterTexture(const char* font, const char* style, CharacterId* id)
{
    _fontId = (char*)font;
    _styleId = (char*)style;
    _characterId = id;
    
    if (_characterId == nullptr)
    {
        // Dummy value
        return;
    }
    
    _characterId->retain();
    
    char textureFileName[255];
    sprintf(textureFileName, "res/chars/%s/%s_%s_%s.png", font, font, style, id->getId());
    
    _texture = Director::getInstance()->getTextureCache()->addImage(textureFileName);
    
}

CharacterTexture::~CharacterTexture()
{
    _characterId->release();
}

CharacterTexture::CharacterTexture()
{
    
}

CharacterTexture::CharacterTexture(CharacterTexture* def)
{
    
}

CharacterTexture* CharacterTexture::dummyValue()
{
    CharacterTexture* result = new CharacterTexture(nullptr, nullptr, nullptr);
    
    result->autorelease();
    
    return result;
}

Texture2D* CharacterTexture::getTexture()
{
    return _texture;
}

CharacterId* CharacterTexture::getCharacterId()
{
    return _characterId;
}