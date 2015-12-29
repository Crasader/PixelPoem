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

class ScentenceDefinition : public Ref
{
private:
    
    Vector<char*>* _characters;
    
public:
    
    ScentenceDefinition();
    
};

class PoemDefinition : public Ref
{
private:
    
    Vector<SentenceDefinition*>* _sentences;
    
    
    
public:
    
    
    
};
#endif /* PoemDefinition_hpp */
