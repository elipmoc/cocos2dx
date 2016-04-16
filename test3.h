#pragma once

#include "stdafx.h"

class Test3 : public cocos2d::Layer
{
public:
	cocos2d::Sprite* sprite;
	int addx=0,addy=0;
	double speed = 1;
	virtual bool init();
	virtual void update(float);
	CREATE_FUNC(Test3);
};
