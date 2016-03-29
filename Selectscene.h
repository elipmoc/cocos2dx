#pragma once
#include "cocos2d.h"
#include "Observekey.h"
#include "AudioEngine.h"
using namespace cocos2d;
using namespace experimental;

class Selectscene : public cocos2d::Scene
{
	Label* stagetext;
	int figure=1;
	Observekey* key;
	int audioid;

public:
	virtual bool init();
	virtual void update(float);
	CREATE_FUNC(Selectscene);
};