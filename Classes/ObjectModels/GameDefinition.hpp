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

USING_NS_CC;

class GameDefinition : public Ref
{
private:
    
    ///
    BYTE* _pixelMatrix;
    
    ///
    PoemDefinition* _poemDefinition;
    
    
    
    
public:
    
    GameDefinition();
    GameDefinition(PoemDefinition* poem);
    GameDefinition();
    
    
    
};

#endif /* GameDefinition_hpp */
