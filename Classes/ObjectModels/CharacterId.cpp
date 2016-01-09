//
//  CharacterId.cpp
//  PixelPoem
//
//  Created by SuiYi on 1/4/16.
//
//

#include "CharacterId.hpp"

CharacterId::CharacterId(const char* id)
{
	_id = id;
}

CharacterId* CharacterId::create(const char* id)
{
	CharacterId* obj = new CharacterId(id);
	
	obj->autorelease();
	
	return obj;
}