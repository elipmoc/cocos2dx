#pragma once
class Mob3 :public Mob {
	Vec2 movev;
public:
	CREATE_MOB(Mob3);
	virtual bool init();
	virtual void update(float);
	void setmovev();
};