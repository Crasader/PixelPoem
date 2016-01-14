//
//  ResourceLibrary.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "ResourceLibrary.hpp"

ResourceLibrary *ResourceLibrary::_instance = NULL;


ResourceLibrary * ResourceLibrary::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new ResourceLibrary();
	}

	return _instance;
}

ResourceLibrary::ResourceLibrary()
{
	loadCharacterTextures();
    
}

ResourceLibrary::~ResourceLibrary()
{
	_characterTextureDictionary->clear();
	delete(_characterTextureDictionary);
}

void ResourceLibrary::loadCharacterTextures()
{
	_characterTextureDictionary = new Map<std::string, CharacterTexture*>();
	
	
	
	
}

Texture2D* ResourceLibrary::retrieveCharacterTextureRaw(const char* font, const char* style, CharacterId* charId)
{
	char textureFileName[255];
	sprintf(textureFileName, "res/chars/%s/%s_%s_%s.png", font, font, style, charId->getId());
	
	auto texture = Director::getInstance()->getTextureCache()->addImage(textureFileName);
    
	return texture;
}

CharacterTexture* ResourceLibrary::retrieveCharacterTexture(const char* font, const char* style, CharacterId* charId)
{
    char key[255];
    sprintf(key, "%s%s%s", font, style, charId->getId());
    
    if (_characterTextureDictionary->at(key) == nullptr)
    {
        CharacterTexture* charTexture = new CharacterTexture(font, style, charId);
        _characterTextureDictionary->insert(key, charTexture);
        charTexture->autorelease();
    }
    
	return _characterTextureDictionary->at(key);
}




