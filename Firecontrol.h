#pragma once
class Mapcontrol;
class Firesprite;
class Firecontrol : public cocos2d::Layer
{
	Gamescene* scene;
	Vector<Firesprite*> firepool;
	//RepeatForever* action;
public:
	virtual bool init(Gamescene*);
	//fireê›íu
	bool setfire(cocos2d::Vec2);
	static Firecontrol* create(Gamescene*);
};
