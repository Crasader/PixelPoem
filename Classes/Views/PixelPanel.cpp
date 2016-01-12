//
//  PixelPanel.cpp
//  PixelPoem
//
//  Created by SuiYi on 1/4/16.
//
//

#include "PixelPanel.hpp"
#include "CharacterSprite.hpp"
#include "../Common/Utils.hpp"
#include "../ObjectModels/ResourceLibrary.hpp"

PixelPanel::PixelPanel()
{
	_characterIndexes = NULL;
	_characterSprites = new Vector<CharacterSprite*>();
	
	_pixelUnitWidth = 30;
	_pixelUnitHeight = 30;
	
	_defaultStretchX = 0.3f;
	_defaultStretchY = 0.3f;
	
	_defaultFont = "song";
	_defaultStyle = "0";
	
	_maxUnitScaleX = 4;
	_maxUnitScaleY = 4;
}

PixelPanel::PixelPanel(GameDefinition* def)
{
    _definition = def;
    _definition->retain();
    
    _characterIndexes = NULL;
    _characterSprites = new Vector<CharacterSprite*>();
    
    _pixelUnitWidth = 30;
    _pixelUnitHeight = 30;
    
    _defaultStretchX = 0.25f;
    _defaultStretchY = 0.25f;
    
    _defaultFont = "song";
    _defaultStyle = "0";
    
    _maxUnitScaleX = 4;
    _maxUnitScaleY = 4;
}

PixelPanel::~PixelPanel()
{
	if(_characterIndexes != NULL)
	{
		delete(_characterIndexes);
		_characterIndexes = NULL;
	}
	
	delete(_characterSprites);
}

void PixelPanel::generatePixelCharacters()
{
	PoemDiagram* diagram = _definition->getPoemDiagram();
	int width = diagram->getWidth();
	int height = diagram->getHeight();
	
	_characterIndexes = new int*[width];
    for(int i = 0; i < width; i++)
    {
        _characterIndexes[i] = new int[height];
        for(int j = 0; j < height; j++)
        {
            PixelColor* clr = diagram->getValue(i, j);
			if (clr->isBlack())
			{
				// Fill with Valid characters
				_characterIndexes[i][j] = 0;
			}
			else
			{
				// Fill with Invalid characters
				_characterIndexes[i][j] = -1;
			}
		}
	}
	
	PoemDefinition* poemDefinition = _definition->getPoemDefinition();
	
	_characterSprites->clear();
	_characterSprites->pushBack(CharacterSprite::dummyValue());
	
	// Step 1: Fill the valid characters
    fillWithCharacters(poemDefinition->getUniqueCharacters());
	
	// Step 2: Fill the fuzzing characters
	for(int j = 0; j < height; j++)
	{
		for(int i = 0; i < width; i++)
		{
			if (_characterIndexes[i][j] == -1)
			{
				_characterIndexes[i][j] = 0;
			}
		}
	}
	
	fillWithCharacters(_definition->getFuzzingCharacters());
}

void PixelPanel::show(Node* parent)
{
	// Draw the characters on the base Sprite
	_baseSprite = Sprite::create();
	for(int i = 1; i < _characterSprites->size(); i++)	// Skip the dummyValue
	{
		CharacterSprite* character = _characterSprites->at(i);
		Size size = character->getTextureSizeInPixel();
		Size scaleInUnit = character->getScale();
		CharacterRotateType rotateType = character->getRotateType();
		Point positionInUnit = character->getPositionInUnit();
		Sprite* sprite = character->getSprite();
		
        int widthBlank = MathUtils::Max(0, (_pixelUnitWidth - size.width * _defaultStretchX) / 2);
		int heightBlank = MathUtils::Max(0, (_pixelUnitHeight - size.height * _defaultStretchY) / 2);
		
		int posX = (positionInUnit.x + scaleInUnit.width - 1) * _pixelUnitWidth / 2;
		int posY = (positionInUnit.y + scaleInUnit.height - 1) * _pixelUnitHeight / 2;
		
		float scaleX = (_pixelUnitWidth * scaleInUnit.width - widthBlank * 2) / size.width;
		float scaleY = (_pixelUnitHeight * scaleInUnit.height - heightBlank * 2) / size.height;
		
		sprite->setPosition(Vec2(posX, posY));
		sprite->setScale(scaleX, scaleY);
		_baseSprite->addChild(sprite, 0);
	}
	
	parent->addChild(_baseSprite);
    _baseSprite->retain();
}

void PixelPanel::fillWithCharacters(Vector<CharacterId*>* characters)
{
    PoemDiagram* diagram = _definition->getPoemDiagram();
    int width = diagram->getWidth();
    int height = diagram->getHeight();
    
	for(int j = 0; j < height; j++)
	{
		for(int i = 0; i < width; i++)
		{
			if(_characterIndexes[i][j] != 0)
			{
				continue;
			}
			
			int validMaxWidth = 1;
			for(int w = 2; w <= _maxUnitScaleX; w++)
			{
				if (i + w - 1 >= width || _characterIndexes[i + w - 1][j] != 0)
				{
					break;
				}
				validMaxWidth = w;
			}
            int charWidth = MathUtils::GetRandomValue(1, validMaxWidth);
			int validMaxHeight = 1;
			for(int h = 2; h <= _maxUnitScaleY; h++)
			{
				if (j + h - 1 >= height)
				{
					break;
				}
				for(int w = 1; w <= charWidth; w++)
				{
					if(_characterIndexes[i + w - 1][j + h -1] != 0)
					{
						break;
					}
				}
				validMaxHeight = h;
			}
			int charHeight = MathUtils::GetRandomValue(1, validMaxHeight);
			
			CharacterId* characterId = characters->at(MathUtils::GetRandomValue(0, (int)(characters->size() - 1)));
			
			// Rotate only if the char is 1x1
			int rotate = (charWidth == 1 && charHeight == 1) ? MathUtils::GetRandomValue(0, 3) : 0;
			
			// Put a random char with charWidth x charHeight
            Texture2D* texture = ResourceLibrary::getInstance()->retrieveCharacterTextureRaw(_defaultFont.c_str(), _defaultStyle.c_str(), characterId);
            CharacterSprite* character = new CharacterSprite(texture);
			character->setPositionInUnit(Vec2(i,j));
			character->setScale(charWidth, charHeight);
			character->setRotate((CharacterRotateType)rotate);
			
			_characterSprites->pushBack(character);
			
            character->release();
            
			// Fill the character index
			int charIndex = (int)(_characterSprites->size() - 1);
			for(int w = 1; w <= charWidth; w++)
			{
				for(int h = 1; h <= charHeight; h++)
				{
					_characterIndexes[i + w - 1][j + h -1] = charIndex;
				}
			}
		}
	}
}

void PixelPanel::setPosition(const Vec2& pos)
{
    _baseSprite->setPosition(pos);
}

Sprite* PixelPanel::getSprite()
{
    return _baseSprite;
}