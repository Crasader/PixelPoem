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
	
    Vector<CharacterId*>* _characterSequence;
    Vector<CharacterId*>* _uniqueCharacters;
    
	PoemDirection _preferredDirection;
    
public:

	PoemDefinition();
	PoemDefinition(const char* name);
	virtual ~PoemDefinition();
	
	static PoemDefinition* createSample();
	
	void setSentenceCount(int count);
	void setWordCountPerSentence(int count);
	
	int getSentenceCount();
	int getWordCountPerSentence();
	
	void appendCharacter(CharacterId* character);
	
    Vector<CharacterId*>* getCharacterSequence();
    Vector<CharacterId*>* getUniqueCharacters();
    
    
};
#endif /* PoemDefinition_hpp */
