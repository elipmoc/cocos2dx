#pragma once
class Mapcontrol;
class Bomcontrol : public cocos2d::Layer
{
	Gamescene* scene;
	
	cocos2d::RepeatForever* action;
public:
	virtual bool init(Gamescene*);
	//É{ÉÄê›íu
	bool setbom(cocos2d::Vec2);
	static Bomcontrol* create(Gamescene*);
};
