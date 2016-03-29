#pragma once
class Bom:public cocos2d::Sprite {
	Gamescene* scene;
	Bomcontrol* bomcon;
	void deletebom(float);
	void explosion(float);
	virtual bool init(Gamescene*,Bomcontrol*);
public:
	
	void afterexplosion();
	
	
	static Bom* create(const std::string&,Gamescene*,Bomcontrol*);
};