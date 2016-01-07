//
//  PixelPanel.cpp
//  PixelPoem
//
//  Created by SuiYi on 12/29/15.
//
//

#include "PixelPanel.hpp"

PixelPanel::PixelPanel()
{
	_characterIndexes = NULL;
	_pixelCharacters = new Vector<PixelCharacter*>();
}

PixelPanel::~PixelPanel()
{
	if(_characterIndexes != NULL)
	{
		delete(_characterIndexes);
		_characterIndexes = NULL;
	}
	
	delete(_pixelCharacters);
}

void PixelPanel::generatePixelCharacters()
{
	PoemDiagram* diagram = _definition->getPoemDiagram();
	int width = diagram->getWidth();
	int height = diagram->getHeight();
	
	_characterIndexes = new int[width][height];
	for(int j = 0; j < height; j++)
	{
		for(int i = 0; i < width; i++)
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
	
	_pixelCharacters->clear();
	_pixelCharacters->pushBack(PixelCharacter::dummyValue());
	
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
			int charWidth = rand(1, validMaxWidth);
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
			int charHeight = rand(1, validMaxHeight);
			
			CharacterId* characterId = validCharacters->at(rand(0, validCharacters->size()));
			
			// Rotate only if the char is 1x1
			int rotate = (charWidth == 1 && charHeight == 1) ? rand(0,3) : 0;
			
			// Put a random char with charWidth x charHeight
			PixelCharacter* character = new PixelCharacter(_defaultFont, _defaultStyle, characterId);
			character->setPositionInUnit(Vec2(i,j));
			character->setScale(charWidth, charHeight);
			character->setRotate(rotate);
			
			_pixelCharacters->pushBack(character);
			
			// Fill the character index
			int charIndex = _pixelCharacters->size() - 1;
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

