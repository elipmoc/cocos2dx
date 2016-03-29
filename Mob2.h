#pragma once
class Mob2 :public Mob {
	int x = 16;
public:
	CREATE_MOB(Mob2);
	virtual bool init();
	virtual void update(float);
};