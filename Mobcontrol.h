#pragma once
#include "Mobdata.h"
class Mobcontrol : public cocos2d::Layer
{
	virtual bool init(Gamescene*);
	Gamescene* scene;
public:
	void mobcreate();//�G����
	static Mobcontrol* create(Gamescene*);
	int mobcount() { return getChildrenCount();}
};