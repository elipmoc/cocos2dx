#pragma once
#include "Mobdata.h"
class Mobcontrol : public cocos2d::Layer
{
	virtual bool init(Gamescene*);
	Gamescene* scene;
public:
	void mobcreate();//ìGê∂ê¨
	static Mobcontrol* create(Gamescene*);
	int mobcount() { return getChildrenCount();}
};