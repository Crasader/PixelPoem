//
//  HorizionalFlipAction.cpp
//  PixelPoem
//
//  Created by SuiYi on 5/2/16.
//
//

#include "HorizionalFlipAction.hpp"




void HorizionalFlipAction::takeFlip(Sprite* sprite)
{
    float curScaleX = sprite->getScaleX();
    float curScaleY = sprite->getScaleY();
    
    auto delay = DelayTime::create(_delayTime);
    auto scale1 = ScaleTo::create(_executionTime / 2, 0.01f, curScaleY);
    auto fade = FadeTo::create(0, _targetOpacity);
    auto scale2 = ScaleTo::create(_executionTime / 2, curScaleX, curScaleY);
    
    auto sequence = Sequence::create(delay, scale1, fade, scale2, nullptr);
    sprite->runAction(sequence);
}
