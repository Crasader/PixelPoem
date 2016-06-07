//
//  HorizionalFlipTwiceAction.cpp
//  PixelPoem
//
//  Created by SuiYi on 5/2/16.
//
//

#include "HorizionalFlipTwiceAction.hpp"


void HorizionalFlipTwiceAction::takeFlip(Sprite* sprite)
{
    float curScaleX = sprite->getScaleX();
    float curScaleY = sprite->getScaleY();
    
    auto delay = DelayTime::create(_delayTime);
    auto scale1 = ScaleTo::create(_executionTime / 4, 0.01f, curScaleY);
    auto scale2 = ScaleTo::create(_executionTime / 4, curScaleX, curScaleY);
    auto fade = FadeTo::create(0, _targetOpacity);
    auto scale3 = ScaleTo::create(_executionTime / 4, 0.01f, curScaleY);
    auto scale4 = ScaleTo::create(_executionTime / 4, curScaleX, curScaleY);
    
    auto sequence = Sequence::create(delay, scale1, scale2, fade, scale3, scale4, nullptr);
    sprite->runAction(sequence);
}
