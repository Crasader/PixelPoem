//
//  FlipCharacterAction.hpp
//  PixelPoem
//
//  Created by SuiYi on 5/2/16.
//
//

#ifndef FlipCharacterAction_hpp
#define FlipCharacterAction_hpp

#include "cocos2d.h"
USING_NS_CC;

class FlipCharacterAction
{
protected:
    
    float _delayTime;
    float _executionTime;
    float _targetOpacity;
    
    
public:
    
    void initialize(float delayTime, float executionTime, float targetOpacity);
    
    void virtual takeFlip(Sprite* sprite);
    
};


#endif /* FlipCharacterAction_hpp */
