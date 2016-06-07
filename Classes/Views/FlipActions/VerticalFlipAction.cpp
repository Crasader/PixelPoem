//
//  VerticalFlipAction.cpp
//  PixelPoem
//
//  Created by SuiYi on 5/2/16.
//
//

#include "VerticalFlipAction.hpp"



void VerticalFlipAction::takeFlip(Sprite* sprite)
{
    float curScaleX = sprite->getScaleX();
    float curScaleY = sprite->getScaleY();
    
    auto delay = DelayTime::create(_delayTime);
    auto scale1 = ScaleTo::create(_executionTime / 2, curScaleX, 0.01f);
    auto fade = FadeTo::create(0, _targetOpacity);
    auto scale2 = ScaleTo::create(_executionTime / 2, curScaleX, curScaleY);
    
    auto sequence = Sequence::create(delay, scale1, fade, scale2, nullptr);
    sprite->runAction(sequence);
}
