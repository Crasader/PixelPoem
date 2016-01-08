//
//  ResourceLibrary.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef ResourceLibrary_hpp
#define ResourceLibrary_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "../Common/Constants.hpp"
#include "../Common/Types.hpp"
#include "CharacterTexture.hpp"


USING_NS_CC;

class ResourceLibrary : public Ref
{
private:
    
    static ResourceLibrary * _instance;

    Map<std::string, CharacterTexture*> * _characterTextureDictionary;
	
    void loadCharacterTextures();

public:
    
    static ResourceLibrary* getInstance();
	
    ResourceLibrary();
	virtual ~ResourceLibrary();
	
    CharacterTexture* retrieveCharacterTexture(const char* font, const char* style, CharacterId* charId);
    Texture2D* retrieveCharacterTextureRaw(const char* font, const char* style, CharacterId* charId);

    
};
#endif /* ResourceLibrary.hpp */
