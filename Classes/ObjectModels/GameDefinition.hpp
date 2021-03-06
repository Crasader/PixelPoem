//
//  GameDefinition.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef GameDefinition_hpp
#define GameDefinition_hpp

#include <stdio.h>

#include "cocos2d.h"

#include "../Common/Constants.hpp"
#include "../Common/Types.hpp"
#include "PoemDefinition.hpp"
#include "PoemDiagram.hpp"

USING_NS_CC;

class GameDefinition : public Ref
{
private:
    
	///
	PoemDiagram* _poemDiagram;
    
    ///
    PoemDefinition* _poemDefinition;
    
    Vector<CharacterId*>* _fuzzingCharacters;
    
    
public:
    
    static GameDefinition* loadFromFileByIndex(int index);
	static GameDefinition* createSample();
	
    GameDefinition(PoemDefinition* poem, PoemDiagram* diagram);
    GameDefinition();
    ~GameDefinition();
    
	void appendFuzzingCharacter(CharacterId* character);
	
	PoemDiagram* getPoemDiagram();
	PoemDefinition* getPoemDefinition();
    Vector<CharacterId*>* getFuzzingCharacters();
    
};

#endif /* GameDefinition_hpp */
