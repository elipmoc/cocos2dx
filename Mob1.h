#pragma once
class Mob1 :public Mob{
	int y = 16;
public:
	CREATE_MOB(Mob1);
	virtual bool init();
	virtual void update(float);
};