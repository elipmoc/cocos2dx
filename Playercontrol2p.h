#pragma once

class Playercontrol2p : public Player
{
public:

	virtual bool init(Gamescene*);
	static Playercontrol2p* create(Gamescene*);
};
