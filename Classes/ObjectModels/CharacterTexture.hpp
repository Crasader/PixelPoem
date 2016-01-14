//
//  CharacterTexture.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef CharacterTexture_hpp
#define CharacterTexture_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "../Common/Constants.hpp"
#include "../Common/Types.hpp"
#include "CharacterId.hpp"


USING_NS_CC;

class CharacterTexture : public Ref
{
private:
    
    char* _fontId;
    char* _styleId;
    
    CharacterId* _characterId;
    
    Texture2D* _texture;
    
public:
    
    CharacterTexture(const char* font, const char* style, CharacterId* id);
    CharacterTexture();
    ~CharacterTexture();
    CharacterTexture(CharacterTexture* def);
    
    static CharacterTexture* dummyValue();
    
    
    CharacterId* getCharacterId();
    Texture2D* getTexture();
    
};
#endif /* CharacterTexture.hpp */
