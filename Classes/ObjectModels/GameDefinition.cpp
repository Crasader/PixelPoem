//
//  GameDefinition.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "GameDefinition.hpp"

GameDefinition::GameDefinition(PoemDefinition* poem, PoemDiagram* diagram)
{
	this->_poemDefinition = poem;
	this->_poemDefinition->retain();
	
    this->_poemDiagram = diagram;
    this->_poemDiagram->retain();
    
	_fuzzingCharacters = new Vector<CharacterId*>();
}

GameDefinition::GameDefinition()
	: GameDefinition(NULL, NULL)
{
	
}
    
GameDefinition::~GameDefinition()
{
	if (this->_poemDefinition != NULL)
		this->_poemDefinition->release();
	
    if (this->_poemDiagram != NULL)
        this->_poemDiagram->release();
    
    _fuzzingCharacters->clear();
	delete(_fuzzingCharacters);
}
  
GameDefinition* GameDefinition::createSample()
{
    PoemDefinition* poem = PoemDefinition::createSample();
    PoemDiagram* diagram = PoemDiagram::loadFromFile("res/diagrams/poem_jingyesi.pp");
    
	GameDefinition* definition = new GameDefinition(poem, diagram);
    definition->appendFuzzingCharacter(CharacterId::create("gu_1_0"));
    definition->appendFuzzingCharacter(CharacterId::create("gu_3_0"));
    definition->appendFuzzingCharacter(CharacterId::create("gu_4_1"));
    definition->appendFuzzingCharacter(CharacterId::create("hun_1_0"));
    definition->appendFuzzingCharacter(CharacterId::create("hun_2_0"));
    definition->appendFuzzingCharacter(CharacterId::create("kao_3_0"));
    definition->appendFuzzingCharacter(CharacterId::create("qian_1_0"));
    definition->appendFuzzingCharacter(CharacterId::create("qian_1_1"));
	
	return definition;
}
	
void GameDefinition::appendFuzzingCharacter(CharacterId* character)
{
	for(int i = 0; i < _fuzzingCharacters->size(); i++)
	{
		if (character->isSame(_fuzzingCharacters->at(i)))
		{
			return;
		}
	}
	
	_fuzzingCharacters->pushBack(character);
}

PoemDiagram* GameDefinition::getPoemDiagram()
{
    return _poemDiagram;
}

PoemDefinition* GameDefinition::getPoemDefinition()
{
    return _poemDefinition;
}

Vector<CharacterId*>* GameDefinition::getFuzzingCharacters()
{
    return _fuzzingCharacters;
}


