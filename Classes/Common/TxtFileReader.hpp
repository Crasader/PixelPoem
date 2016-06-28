//
//  TxtFileReader.hpp
//  PixelPoem
//
//  Created by SuiYi on 6/7/16.
//
//

#ifndef TxtFileReader_hpp
#define TxtFileReader_hpp

#include <stdio.h>
#include <fstream>
#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class TxtFileReader : public Ref
{
private:
    
    ifstream inputStream;
public:
    
    
    TxtFileReader(std::string relativePath);
    ~TxtFileReader();
    
    int readInt();
    std::string readString();
    
};



#endif /* TxtFileReader_hpp */
