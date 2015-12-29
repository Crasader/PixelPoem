//
//  CharacterDefinition.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef CharacterDefinition_hpp
#define CharacterDefinition_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "../Common/Constants.hpp"
#include "../Common/Types.hpp"
USING_NS_CC;

class CharacterDefinition : public Ref
{
private:
    
    char* _fontId;
    char* _styleId;
    
    char* _characterId;
    
    
public:
    
    CharacterDefinition();
    CharacterDefinition(CharacterDefinition* def);
    
    
    
};
#endif /* CharacterDefinition_hpp */
