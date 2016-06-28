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
#include <cstdio>

#include "cocos2d.h"

USING_NS_CC;

class MathUtils : public Ref
{
public:
    
    static int GetRandomValue(int min, int max);
    static int Max(int a, int b);
    static int Min(int a, int b);
    
};

class StringUtil : public Ref
{
public:
    
    template <typename... Ts>
    static std::string format (const std::string &fmt, Ts... vs)
    {
        char b;
        unsigned required = std::snprintf(&b, 0, fmt.c_str(), vs...) + 1;
        // See comments: the +1 is necessary, while the first parameter
        //               can also be set to nullptr
        
        char bytes[required];
        std::snprintf(bytes, required, fmt.c_str(), vs...);
        
        return std::string(bytes);
    }
};

#endif /* Utils_hpp */
