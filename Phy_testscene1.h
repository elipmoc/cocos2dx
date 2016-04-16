#pragma once
#include "stdafx.h"
#include "Phy_test1.h"


class Phy_testscene1 : public cocos2d::Scene
{
public:
	static Scene* createscene();
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(Phy_testscene1);
};