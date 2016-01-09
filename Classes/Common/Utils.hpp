//
//  Utils.hpp
//  PixelPoem
//
//  Created by SuiYi on 1/7/16.
//
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>

#include "cocos2d.h"

USING_NS_CC;

class MathUtils : public Ref
{
public:
    
    static int GetRandomValue(int min, int max);
    static int Max(int a, int b);
    static int Min(int a, int b);
    
};


#endif /* Utils_hpp */
