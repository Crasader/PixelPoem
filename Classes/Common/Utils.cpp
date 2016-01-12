//
//  Utils.cpp
//  PixelPoem
//
//  Created by SuiYi on 1/7/16.
//
//

#include "Utils.hpp"


int MathUtils::GetRandomValue(int min, int max)
{
    assert(min <= max);
    return rand() % (max - min + 1) + min;
}

int MathUtils::Max(int a, int b)
{
    return (a > b) ? a : b;
}


int MathUtils::Min(int a, int b)
{
    return (a < b) ? a : b;
}