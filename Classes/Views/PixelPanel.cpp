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
	
	_unitWidth = 30;
	_unitHeight = 30;
	
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
    
    _unitWidth = 16;
    _unitHeight = 16;
    
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
    PoemDiagram* diagram = _definition->getPoemDiagram();
    int totalHeight = _unitHeight * diagram->getHeight();
    
	// Draw the characters on the base Sprite
	_baseSprite = Sprite::create();
	for(int i = 1; i < _characterSprites->size(); i++)	// Skip the dummyValue
	{
		CharacterSprite* character = _characterSprites->at(i);
		Size size = character->getTextureSize();
		Size scaleInUnit = character->getScale();
		CharacterRotateType rotateType = character->getRotateType();
		Point positionInUnit = character->getPositionInUnit();
		Sprite* sprite = character->getSprite();
		
        // int widthBlank = MathUtils::Max(0, (_pixelUnitWidth - size.width) / 2);
		// int heightBlank = MathUtils::Max(0, (_pixelUnitHeight - size.height) / 2);
		
        int widthBlank = 0;
        int heightBlank = 0;
        
		int posX = positionInUnit.x * _unitWidth + (scaleInUnit.width + 1) * _unitWidth / 2;
		int posY = totalHeight - positionInUnit.y * _unitHeight - (scaleInUnit.height + 1) * _unitHeight / 2;
		
        // posX /= 2;
        // posY /= 2;
        
		float scaleX = (_unitWidth * scaleInUnit.width - widthBlank * 2) / size.width;
		float scaleY = (_unitHeight * scaleInUnit.height - heightBlank * 2) / size.height;
		
		sprite->setPosition(Vec2(posX, posY));
		sprite->setScale(scaleX, scaleY);
        // sprite->setAnchorPoint(Vec2(0.5f, 0.5f));
		_baseSprite->addChild(sprite, 0);
	}
	
	parent->addChild(_baseSprite);
    _baseSprite->retain();
    
    setControllableState(true);
}

void PixelPanel::setControllableState(bool state)
{
    this->_isControllable = state;
}

void PixelPanel::checkGameWin()
{
    
    PoemDefinition * poem = this->_definition->getPoemDefinition();
    int charCount = poem->getSentenceCount() * poem->getWordCountPerSentence();
    
    bool isWinState = true;
    for (int i = 0; i < _characterSprites->size(); i++)
    {
        CharacterSprite *csprite = _characterSprites->at(i);
        
        bool inPoem = false;
        for (int j = 0; j < charCount; j++) {
            
            CharacterId * character = poem->getCharacterSequence()->at(j);
            if (character->isSame(csprite->getTexture()->getCharacterId()))
            {
                inPoem = true;
                break;
            }
        }
        
        if ((inPoem && !csprite->isForeSide()) || (!inPoem && csprite->isForeSide()))
        {
            isWinState = false;
            break;
        }
    }
    
    if (isWinState) {
        log("Game Win");
        
        this->doGameFinish();
    }
}


void PixelPanel::doGameFinish()
{
    _baseSprite->setScale(0.3f, 0.3f);
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
                
                bool hasConflict = false;
				for(int w = 1; w <= charWidth; w++)
				{
					if(_characterIndexes[i + w - 1][j + h -1] != 0)
					{
                        hasConflict = true;
						break;
					}
				}
                
                if (hasConflict)
                    break;
                
				validMaxHeight = h;
			}
			int charHeight = MathUtils::GetRandomValue(1, validMaxHeight);
			
			CharacterId* characterId = characters->at(MathUtils::GetRandomValue(0, (int)(characters->size() - 1)));
			
			// Rotate only if the char is 1x1
			int rotate = (charWidth == 1 && charHeight == 1) ? MathUtils::GetRandomValue(0, 3) : 0;
			
			// Put a random char with charWidth x charHeight
            CharacterTexture* texture = ResourceLibrary::getInstance()->retrieveCharacterTexture(_defaultFont.c_str(), _defaultStyle.c_str(), characterId);
            CharacterSprite* character = new CharacterSprite(texture);
			character->setPositionInUnit(Vec2(i, j));
			character->setScale(charWidth, charHeight);
			character->setRotate((CharacterRotateType)rotate);
			
			_characterSprites->pushBack(character);
            
            character->release();
            
			// Fill the character index
			int charIndex = (int)(_characterSprites->size() - 1);
            //log("Char %d: [%f, %f]", charIndex, character->getPositionInUnit().x, character->getPositionInUnit().y);
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

void PixelPanel::onClicked(Vec2& pos)
{
    if (!this->_isControllable) {
        
        log("The Panel is not in Controllable state, skip the touch.");
        return;
    }
    
    PoemDiagram* diagram = _definition->getPoemDiagram();
    int totalHeight = _unitHeight * diagram->getHeight();
    int totalWidth = _unitWidth * diagram->getWidth();
    
    if (pos.x < 0 || pos.x > totalWidth || pos.y < 0 || pos.y > totalHeight)
    {
        // Clicked on the outside
        return;
    }
    
    int unitX = pos.x / _unitWidth;
    int unitY = (totalHeight - pos.y) / _unitHeight;
    
    flipCharacter(_characterIndexes[unitX][unitY]);
}

void PixelPanel::setPosition(const Vec2& pos)
{
    _baseSprite->setPosition(pos);
}

Sprite* PixelPanel::getSprite()
{
    return _baseSprite;
}

void PixelPanel::flipCharacter(int charIndex)
{
    setControllableState(false);
    
    CharacterSprite* centerCharacter = _characterSprites->at(charIndex);
    Vec2 centerPos = centerCharacter->getPositionInUnit();
    
    float longestDelayTime = 0.0f;
    for(int i = 0 ; i < _characterSprites->size(); i++)
    {
        CharacterSprite* character = _characterSprites->at(i);
        if (!character->isSame(centerCharacter))
        {
            continue;
        }
        
        Vec2 pos = character->getPositionInUnit();
        float distance = std::abs(pos.x - centerPos.x) + std::abs(pos.y - centerPos.y);
        float delayTime = distance * 0.03f;
        character->flip(delayTime);
        
        longestDelayTime = MAX(delayTime, longestDelayTime);
    }
    
    auto delay = DelayTime::create(longestDelayTime);
    auto recoverState = CallFunc::create([&]() { this->setControllableState(true); } );
    auto checkWin = CallFunc::create([&]() { this->checkGameWin(); } );
    auto sequence = Sequence::create(delay, recoverState, checkWin, nullptr);
    _baseSprite->runAction(sequence);
    
}


