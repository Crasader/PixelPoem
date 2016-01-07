//
//  TitleScene.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef TitleScene_hpp
#define TitleScene_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class TitleScene : public Layer
{
private:
    
    
    void buttonStartCallback(cocos2d::Ref* pSender);
    
public:
    
    static Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);
};



#endif /* TitleScene_hpp */
