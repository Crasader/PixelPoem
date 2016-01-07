//
//  MainGameScene.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef MainGameScene_hpp
#define MainGameScene_hpp

#include <stdio.h>

#include "cocos2d.h"
#include "../ObjectModels/GameDefinition.hpp"

USING_NS_CC;

class MainGameScene : public Scene
{
private:
    
    GameDefinition* _definition;
    
public:
    
    static Scene* createScene(int gameDefinitionId);
    
};

#endif /* MainGameScene_hpp */
