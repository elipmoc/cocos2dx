#pragma once
class Firesprite :public cocos2d::Sprite {
	Gamescene* scene;
	Firecontrol* firecon;
	void deletefire(float);
	virtual bool init(Gamescene*, Firecontrol*);
public:
	Action* action;
	void clear();
	bool activeflag = false;
	static Firesprite* create(const std::string&, Gamescene*, Firecontrol*);
	~Firesprite();
};