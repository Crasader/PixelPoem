//
//  SelectStageScene.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "SelectStageScene.hpp"
#include "MainGameScene.hpp"



// on "init" you need to initialize your instance
bool SelectStageScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    return true;
}

void SelectStageScene::buttonStartCallback(cocos2d::Ref* pSender)
{
    Scene* scene = MainGameScene::createScene(1);
    
    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.5f, scene));
}
