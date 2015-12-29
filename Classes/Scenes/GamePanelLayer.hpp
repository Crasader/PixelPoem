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

USING_NS_CC;

class GamePanelLayer : public Layer
{
private:
    
    
    void buttonStartCallback(cocos2d::Ref* pSender);
    
public:
    
    virtual bool init();
    
    
};

#endif /* GamePanelLayer_hpp */
