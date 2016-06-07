//
//  ScreenConfig.hpp
//  PixelPoem
//
//  Created by SuiYi on 4/11/16.
//
//

#ifndef ScreenConfig_hpp
#define ScreenConfig_hpp

#include "cocos2d.h"
#include "DeviceDefinition.h"

USING_NS_CC;


class ScreenConfig : public Ref
{
private:
    
    static ScreenConfig * _instance;
    
    int _screenHeight;
    int _screenWidth;
    
    int _screenHeightInPixel;
    int _screenWidthInPixel;
    
    
public:
    
    static ScreenConfig * loadByDevice(DeviceDefinition def);
    static ScreenConfig * getInstance();
    
    int getScreenHeight();
    int getScreenWidth();
    
    int getScreenHeightInPixel();
    int getScreenWidthInPixel();
    
    
};

#endif /* ScreenConfig_hpp */
