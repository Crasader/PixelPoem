//
//  GamePanelLayer.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "GamePanelLayer.hpp"
#include "PixelPanel.hpp"

bool GamePanelLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto sprite = Sprite::create("res/ui/iphone6p/MainGameMask.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}