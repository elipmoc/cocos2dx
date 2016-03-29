#pragma once
#include "cocos2d.h"
#include "Observekey.h"
#include "AudioEngine.h"
using namespace cocos2d;
using namespace experimental;

class Titlescene : public cocos2d::Scene
{
	Observekey* key;
	int audioid;
public:
	virtual bool init();
	virtual void update(float);
	CREATE_FUNC(Titlescene);
};