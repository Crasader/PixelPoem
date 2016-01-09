//
//  GameDefinition.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "GameDefinition.hpp"

GameDefinition::GameDefinition(PoemDefinition* poem)
{
	this->_poemDefinition = poem;
	this->_poemDefinition->retain();
	
	_fuzzingCharacters = new Vector<CharacterId*>();
}

GameDefinition::GameDefinition()
	: GameDefinition(NULL)
{
	
}
    
GameDefinition::~GameDefinition()
{
	if (this->_poemDefinition != NULL)
		this->_poemDefinition->release();
	
	_fuzzingCharacters->clear();
	delete(_fuzzingCharacters);
}
  
GameDefinition* GameDefinition::createSample()
{
	GameDefinition* definition = new GameDefinition();
	
	
	return definition;
}
	
GameDefinition::appendFuzzingCharacter(CharacterId* character)
{
	for(int i = 0; i < _fuzzingCharacters->size(); i++)
	{
		if (character->isSame(_fuzzingCharacters->at(i)))
		{
			return;
		}
	}
	
	_fuzzingCharacters->pushBack(characterId);
}