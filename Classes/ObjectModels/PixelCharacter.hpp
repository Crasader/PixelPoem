//
//  PixelCharacter.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef PixelCharacter_hpp
#define PixelCharacter_hpp

#include <stdio.h>

#include "cocos2d.h"

#include "../Common/Constants.hpp"
#include "../Common/Types.hpp"
#include "CharacterDefinition.hpp"

USING_NS_CC;

class PixelCharacter : public Ref
{
private:
    
    CharacterDefinition* _character;
    
    int _direction;
    int _widthInUnit;
    int _heightInUnit;
    
	Vec2 _positionInUnit;
    
public:
    
    PixelCharacter();
    PixelCharacter(CharacterDefinition* def);
    
    static PixelCharacter* dummyValue();
    
	Vec2 getPositionInUnit();
	void setPositionInUnit(Vec2 pos);
};

#endif /* PixelCharacter_hpp */
