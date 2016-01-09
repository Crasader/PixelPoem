//
//  CharacterId.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef CharacterId_hpp
#define CharacterId_hpp

#include <stdio.h>
#include "cocos2d.h"


#include "../Common/Constants.hpp"
#include "../Common/Types.hpp"

USING_NS_CC;

class CharacterId : public Ref
{
private:
    char* _id;
    
    
public:
    
	static CharacterId* create(const char* id);
    CharacterId(const char* id);
    CharacterId(CharacterId* def);
    
    const char* getId();
    
	bool isSame(CharacterId* another);
	
	
};
#endif /* CharacterId_hpp */
