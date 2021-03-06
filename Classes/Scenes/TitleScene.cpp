//
//  TitleScene.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "TitleScene.hpp"
#include "SelectStageScene.hpp"
#include "MainGameScene.hpp"

Scene* TitleScene::createScene()
{
    Scene* scene = Scene::create();
    auto layer = TitleScene::create();
    //layer->init();
    
    scene->addChild(layer);
    
    return scene;
}

bool TitleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size winSize = Director::getInstance()->getWinSize();
    Size winSizePixel = Director::getInstance()->getWinSizeInPixels();
    float pixelScale = winSizePixel.width / winSize.width;
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "res/ui/iphone6p/Button_Start.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(TitleScene::buttonStartCallback, this));
    
    closeItem->setPosition(Vec2(visibleSize.width/2 ,
                                visibleSize.height/2));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 200);
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    
    // add the label as a child to this layer
    //this->addChild(label, 1);
    
    // add "HelloWorld" splash screen"
    // auto sprite = Sprite::create("ui/iphone6p/Button_Start.png");
    // auto sprite = Sprite::create("Button_Start.png");
    auto sprite = Sprite::create("res/ui/iphone6p/Button_Start.png");
    
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    // this->addChild(sprite, 0);
    
    
    auto sample = Sprite::create("res/samples/sample_100_100_100dpi.png");
    sample->setPosition(Vec2(0 + origin.x, 0 + origin.y));
    Size size = sample->getTexture()->getContentSize();
    Size sizepixel = sample->getTexture()->getContentSizeInPixels();
    sample->setScale(pixelScale, pixelScale);
    sample->setAnchorPoint(Vec2(0, 0));
    this->addChild(sample, 0);
    
    auto sample2 = Sprite::create("res/samples/sample_100_100_300dpi.png");
    sample2->setPosition(Vec2(100 + origin.x, 100 + origin.y));
    sample2->setAnchorPoint(Vec2(0, 0));
    sample2->setScale(pixelScale, pixelScale);
    this->addChild(sample2, 0);
    size = sample->getTexture()->getContentSize();
    sizepixel = sample->getTexture()->getContentSizeInPixels();
    

    auto sample3 = Sprite::create("res/samples/sample_100_100_300dpi.png");
    sample3->setPosition(Vec2(200, 200));
    this->addChild(sample3, 0);
    
    return true;
}

void TitleScene::buttonStartCallback(Ref* pSender)
{
    // Transit to next Scene
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    // auto layer = SelectStageScene::create();
    auto layer = MainGameScene::createScene(0);
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    Director::getInstance()->replaceScene(TransitionFade::create(2.0f, scene, Color3B(0,255,255)));

    
}