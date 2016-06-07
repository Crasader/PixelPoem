//
//  ScreenConfig.cpp
//  PixelPoem
//
//  Created by SuiYi on 4/11/16.
//
//

#include "ScreenConfig.hpp"

ScreenConfig* ScreenConfig::_instance = nullptr;


ScreenConfig* ScreenConfig::loadByDevice(DeviceDefinition def)
{
    
    ScreenConfig * config = new ScreenConfig();
    switch (def) {
        case Device_iPhone6:
            break;
            
        case Device_iPhone6plus:
            
            
            break;
        
        default:
            break;
    }
    
    config->autorelease();
    return nullptr;
}

ScreenConfig* ScreenConfig::getInstance()
{
    return _instance;
}

int ScreenConfig::getScreenHeight()
{
    return this->_screenHeight;
}

int ScreenConfig::getScreenWidth()
{
    return this->_screenWidth;
}

int ScreenConfig::getScreenHeightInPixel()
{
    return this->_screenHeightInPixel;
}

int ScreenConfig::getScreenWidthInPixel()
{
    return this->_screenWidthInPixel;
}