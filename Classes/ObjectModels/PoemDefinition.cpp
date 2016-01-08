//
//  PoemDefinition.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "PoemDefinition.hpp"

PoemDefinition::PoemDefinition()
{
	this->_name = NULL;
}
PoemDefinition::PoemDefinition(const char* name)
{
	this->_name = new char[255];
	strcpy(this->_name, name);
}

PoemDefinition::~PoemDefinition()
{
	if (this->_name != NULL)
	{
		delete(this->_name);
	}
}

PoemDefinition* PoemDefinition::createSample()
{
	PoemDefinition* def = new PoemDefinition();
	
}

void PoemDefinition::appendCharacter(CharacterId* character)
{
		
}




