#pragma once

class Playercontrol : public Player
{
public:
	virtual bool init(Gamescene*);
	static Playercontrol* create(Gamescene*);
};
