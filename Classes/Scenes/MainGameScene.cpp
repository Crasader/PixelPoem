//
//  MainGameScene.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "MainGameScene.hpp"
#include "GamePanelLayer.hpp"

Scene* MainGameScene::createScene(int gameDefinitionId)
{
    Scene* scene = Scene::create();
    auto layer = GamePanelLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}


