//
//  PoemDefinition.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef PoemDefinition_hpp
#define PoemDefinition_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "../Common/Constants.hpp"
#include "../Common/Types.hpp"
#include "CharacterId.hpp"

USING_NS_CC;

typedef enum PoemDirection
{
	PoemDirection_Normal,
	PoemDirection_Traditional
	
} PoemDirection;

class PoemDefinition : public Ref
{
private:
    
	char* _name;
	
	int _sentenceCount;
	int _wordCountPerSentence;
	
    int _nameLength;
    int _authorLength;
    
    Vector<CharacterId*>* _nameSequence;
    Vector<CharacterId*>* _authorSequence;
    
    Vector<CharacterId*>* _characterSequence;
    Vector<CharacterId*>* _uniqueCharacters;
    
	PoemDirection _preferredDirection;
    
public:

	PoemDefinition();
	PoemDefinition(const char* name);
	virtual ~PoemDefinition();
	
	static PoemDefinition* createSample();
    static PoemDefinition* loadFromFileByName(std::string poemName);
    
	void setSentenceCount(int count);
	void setWordCountPerSentence(int count);
	
	int getSentenceCount();
	int getWordCountPerSentence();
	
    void setNameLength(int value);
    void setAuthorLength(int value);
    
    void appendName(CharacterId* character);
    void appendAuthor(CharacterId* character);
    void appendCharacter(CharacterId* character);
	
    Vector<CharacterId*>* getCharacterSequence();
    Vector<CharacterId*>* getUniqueCharacters();
    
    std::string getName();
    
};
#endif /* PoemDefinition_hpp */
