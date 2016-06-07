//
//  FlipCharacterAction.cpp
//  PixelPoem
//
//  Created by SuiYi on 5/2/16.
//
//

#include "FlipCharacterAction.hpp"



void FlipCharacterAction::initialize(float delayTime, float executionTime, float targetOpacity)
{
    this->_delayTime = delayTime;
    this->_executionTime = executionTime;
    this->_targetOpacity = targetOpacity;
}

void FlipCharacterAction::takeFlip(Sprite* sprite)
{
    // Do nothing
}
