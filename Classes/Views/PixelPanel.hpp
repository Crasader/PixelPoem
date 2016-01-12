//
//  PixelPanel.hpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#ifndef PixelPanel_hpp
#define PixelPanel_hpp

#include <stdio.h>
#include "cocos2d.h"

#include "../Common/Constants.hpp"
//#include "GameRecord.hpp"
#include "GameDefinition.hpp"
#include "CharacterSprite.hpp"

USING_NS_CC;

class PixelPanel : public Ref
{
private:
    
    GameDefinition* _definition;
    Sprite* _baseSprite;
    
    int** _characterIndexes; // Map pointing to the corresponding character
    
    Vector<CharacterSprite*>* _characterSprites;
    
    float _defaultStretchX;
	float _defaultStretchY;
	
    std::string _defaultFont;
	std::string _defaultStyle;
	
	int _pixelUnitWidth;
	int _pixelUnitHeight;
	
	int _maxUnitScaleX;
	int _maxUnitScaleY;
	
	void fillWithCharacters(Vector<CharacterId*>* characters);
	
	
	
public:
    
    PixelPanel();
    PixelPanel(GameDefinition* def);
    //PixelPanel(GameRecord* record);
    
    virtual ~PixelPanel();
    
    void generatePixelCharacters();
    void show(Node* parent);
    void setPosition(const Vec2& pos);
  
    Sprite* getSprite();
};

#endif /* PixelPanel_hpp */
