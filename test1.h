#pragma once

#include "stdafx.h"


class Test1: public cocos2d::Layer
{
public:
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Test1);
};
