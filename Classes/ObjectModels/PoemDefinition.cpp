//
//  PoemDefinition.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "PoemDefinition.hpp"
#include "../Common/TxtFileReader.hpp"
#include "../Common/Utils.hpp"

PoemDefinition::PoemDefinition()
	: PoemDefinition(NULL)
{
	
}
PoemDefinition::PoemDefinition(const char* name)
{
	this->_name = new char[255];
	strcpy(this->_name, name);
	
    _nameSequence = new Vector<CharacterId*>();
    _authorSequence = new Vector<CharacterId*>();
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

PoemDefinition* PoemDefinition::loadFromFileByName(std::string poemName)
{
    std::string poemfilename = StringUtil::format("res/poems/poem_%s.txt", poemName.c_str());
    TxtFileReader * fileReader = new TxtFileReader(poemfilename);
    
    poemName = fileReader->readString();
    
    PoemDefinition* def = new PoemDefinition(poemName.c_str());
    
    int nameLength = fileReader->readInt();
    def->setNameLength(nameLength);
    for(int i = 0; i < nameLength; i++)
    {
        std::string name = fileReader->readString();
        def->appendName(CharacterId::create(name.c_str()));
    }
    
    int authorLength = fileReader->readInt();
    def->setAuthorLength(authorLength);
    for(int i = 0; i < authorLength; i++)
    {
        std::string author = fileReader->readString();
        def->appendAuthor(CharacterId::create(author.c_str()));
    }
    
    int sentenceCount = fileReader->readInt();
    int wordCount = fileReader->readInt();
    def->setSentenceCount(sentenceCount);
    def->setWordCountPerSentence(wordCount);
    
    for(int i = 0; i < sentenceCount * wordCount; i++)
    {
        std::string charName = fileReader->readString();
        def->appendCharacter(CharacterId::create(charName.c_str()));
    }
    
    fileReader->release();
    
    def->autorelease();
    return def;
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
    
    return def;
}

void PoemDefinition::setNameLength(int value)
{
    this->_nameLength = value;
}

void PoemDefinition::setAuthorLength(int value)
{
    this->_authorLength = value;
}

void PoemDefinition::appendName(CharacterId* character)
{
    _nameSequence->pushBack(character);
}

void PoemDefinition::appendAuthor(CharacterId* character)
{
    _authorSequence->pushBack(character);
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
		_uniqueCharacters->pushBack(character);
	}
}

void PoemDefinition::setSentenceCount(int count)
{
	this->_sentenceCount = count;
}

int PoemDefinition::getSentenceCount()
{
    return this->_sentenceCount;
}

void PoemDefinition::setWordCountPerSentence(int count)
{
	this->_wordCountPerSentence = count;
}

int PoemDefinition::getWordCountPerSentence()
{
    return this->_wordCountPerSentence;
}


Vector<CharacterId*>* PoemDefinition::getCharacterSequence()
{
	return _characterSequence;
}
   
Vector<CharacterId*>* PoemDefinition::getUniqueCharacters()
{
	return _uniqueCharacters;
}
    
std::string PoemDefinition::getName()
{
    return std::string(this->_name);
}
