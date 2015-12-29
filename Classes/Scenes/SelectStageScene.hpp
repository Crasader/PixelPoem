//
//  SelectStageScene.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef SelectStageScene_hpp
#define SelectStageScene_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class SelectStageScene : public Layer
{
private:
    
    
    void buttonStartCallback(cocos2d::Ref* pSender);
    
public:
    
    virtual bool init();
    
    
};


#endif /* SelectStageScene_hpp */
