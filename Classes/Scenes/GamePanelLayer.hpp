//
//  GamePanelLayer.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef GamePanelLayer_hpp
#define GamePanelLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "PixelPanel.hpp"

USING_NS_CC;

class GamePanelLayer : public Layer
{
private:
    
    
    void buttonStartCallback(cocos2d::Ref* pSender);
    
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchCancelled(Touch* touch, Event* event);

    Vec2 _touchOffset;
    PixelPanel* _pixelPanel;
    
public:
    
    virtual bool init();
    
    CREATE_FUNC(GamePanelLayer);

};

#endif /* GamePanelLayer_hpp */
