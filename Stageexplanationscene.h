#pragma once
#include "cocos2d.h"
#include "Observekey.h"
#include "AudioEngine.h"
#include "Stagedata.h"
using namespace cocos2d;
using namespace experimental;

class Stageexplanationscene : public cocos2d::Scene
{
	bool flag2p = false;
	int figure;
	Observekey* key;
public:
	virtual bool init(int);
	virtual void update(float);
	static Stageexplanationscene* create(int);
};