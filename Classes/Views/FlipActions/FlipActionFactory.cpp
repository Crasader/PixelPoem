//
//  FlipActionFactory.cpp
//  PixelPoem
//
//  Created by SuiYi on 5/2/16.
//
//

#include "FlipActionFactory.hpp"
#include "HorizionalFlipAction.hpp"
#include "VerticalFlipAction.hpp"
#include "HorizionalFlipTwiceAction.hpp"

FlipCharacterAction* FlipActionFactory::createRandomAction()
{
    if (rand() % 3 == 0)
    {
        return new HorizionalFlipAction();
    }
    else if (rand() % 3 == 1)
    {
        return new VerticalFlipAction();
    }
    else
    {
        return new HorizionalFlipTwiceAction();
    }
    
    return nullptr;
}
