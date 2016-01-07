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
}

CharacterTexture::CharacterTexture()
{
    
}

CharacterTexture::CharacterTexture(CharacterTexture* def)
{
    
}
