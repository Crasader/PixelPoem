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

USING_NS_CC;


class PoemDefinition : public Ref
{
private:
    
	char* _name;
    Vector<CharacterId*>* _characterSequence;
    
    Vector<CharacterId*>* _uniqueCharacters;
    
    
public:

    Vector<CharacterId*>* getCharacterSequence();
    
    Vector<CharacterId*>* getUniqueCharacters();
    
    
};
#endif /* PoemDefinition_hpp */
