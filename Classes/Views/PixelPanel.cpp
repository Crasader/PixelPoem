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

PixelPanel::PixelPanel()
{
	_characterIndexes = NULL;
	_characterSprites = new Vector<CharacterSprite*>();
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
			if (diagram->getValue(i, j) == 0)
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
	Vector<CharacterId*>* validCharacters = poemDefinition->getUniqueCharacters();
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
			
			CharacterId* characterId = validCharacters->at(MathUtils::GetRandomValue(0, (int)(validCharacters->size())));
			
			// Rotate only if the char is 1x1
			int rotate = (charWidth == 1 && charHeight == 1) ? MathUtils::GetRandomValue(0,3) : 0;
			
			// Put a random char with charWidth x charHeight
            CharacterTexture* texture = new CharacterTexture(_defaultFont, _defaultStyle, characterId);
            CharacterSprite* character = new CharacterSprite(texture);
			character->setPositionInUnit(Vec2(i,j));
			character->setScale(charWidth, charHeight);
			character->setRotate(rotate);
			
			_characterSprites->pushBack(character);
			
            texture->release();
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
	
	Vector<CharacterId*>* invalidCharacters = _definition->getFuzzingCharacters();
    
}

