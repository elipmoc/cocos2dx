#pragma once

#include "cocos2d.h"

class Test2 : public cocos2d::Layer
{
public:
	cocos2d::Sprite* sprite;
	virtual bool init();
	CREATE_FUNC(Test2);
};
