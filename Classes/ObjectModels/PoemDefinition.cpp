//
//  PoemDefinition.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "PoemDefinition.hpp"

PoemDefinition::PoemDefinition()
	: PoemDefinition(NULL)
{
	
}
PoemDefinition::PoemDefinition(const char* name)
{
	this->_name = new char[255];
	strcpy(this->_name, name);
	
	_characterSequence = new Vector<CharacterId*>();
	_uniqueCharacters = new Vector<CharacterId*>();
	
	_sentenceCount = 1;
	_wordCountPerSentence = 1;
}

PoemDefinition::~PoemDefinition()
{
	if (this->_name != NULL)
	{
		delete(this->_name);
	}
	
	if (_characterSequence != NULL)
		delete(_characterSequence);
	if (_uniqueCharacters != NULL)
		delete(_uniqueCharacters);

	
}

PoemDefinition* PoemDefinition::createSample()
{
	PoemDefinition* def = new PoemDefinition("jingyesi");
	def->setSentenceCount(4);
	def->setWordCountPerSentence(5);
	
	def->appendCharacter(CharacterId::create("chuang_2_0"));
	def->appendCharacter(CharacterId::create("qian_2_0"));
	def->appendCharacter(CharacterId::create("ming_2_0"));
	def->appendCharacter(CharacterId::create("yue_4_0"));
	def->appendCharacter(CharacterId::create("guang_1_0"));
	def->appendCharacter(CharacterId::create("yi_2_0"));
	def->appendCharacter(CharacterId::create("shi_4_0"));
	def->appendCharacter(CharacterId::create("di_4_0"));
	def->appendCharacter(CharacterId::create("shang_4_0"));
	def->appendCharacter(CharacterId::create("shuang_1_0"));
	def->appendCharacter(CharacterId::create("ju_3_0"));
	def->appendCharacter(CharacterId::create("tou_2_0"));
	def->appendCharacter(CharacterId::create("wang_4_0"));
	def->appendCharacter(CharacterId::create("ming_2_0"));
	def->appendCharacter(CharacterId::create("yue_4_0"));
	def->appendCharacter(CharacterId::create("di_1_0"));
	def->appendCharacter(CharacterId::create("tou_2_0"));
	def->appendCharacter(CharacterId::create("si_1_0"));
	def->appendCharacter(CharacterId::create("gu_4_0"));
	def->appendCharacter(CharacterId::create("xiang_1_0"));
}

void PoemDefinition::appendCharacter(CharacterId* character)
{
	if (_characterSequence->size() >= _wordCountPerSentence * _sentenceCount)
	{
		log("Warning: Character size is exceeded the maximum character count [%d]", _wordCountPerSentence * _sentenceCount);
		return;
	}
	
	_characterSequence->pushBack(character);
	
	bool hasChar = false;
	for(int i = 0; i < _uniqueCharacters->size(); i++)
	{
		if (character->isSame(_uniqueCharacters->at(i)))
		{
			hasChar = true;
			break;
		}
	}
	
	if (!hasChar)
	{
		_uniqueCharacters->pushBack(characterId);
	}
}

void PoemDefinition::setSentenceCount(int count)
{
	this->_sentenceCount = count;
}

void PoemDefinition::setWordCountPerSentence(int count)
{
	this->_wordCountPerSentence = count;
}
	

Vector<CharacterId*>* PoemDefinition::getCharacterSequence()
{
	return _characterSequence;
}
   
Vector<CharacterId*>* PoemDefinition::getUniqueCharacters()
{
	return _uniqueCharacters;
}
    

