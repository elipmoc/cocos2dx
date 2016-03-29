#pragma once
#include "Observekey.h"

#define PLAYERACTIONMAX 4

class Player : public Colision
{
	float speed = 0.22f;
	int maximumbom=1;
protected:
	enum Actiontype {
		FRONT = 0,
		BACK,
		LEFT,
		RIGHT,
	};
	typedef struct{
		int up;
		int	down;
		int	left;
		int	right;
		int bomset;
	}Playerkey;
	Playerkey playerkey;
	bool desflag = false;
	Gamescene* scene;
	//�L�[����N���X
	Observekey* obsevekey;
	//�{������N���X
	Bomcontrol* bomcon;
	//��l���A�j���[�V����
	cocos2d::RepeatForever* action[PLAYERACTIONMAX];
	void gameover();
	//�{���ݒu
	void bomset();
public:
	void setfirstposition();
	virtual void callback(Item*);
	virtual void callback(Colision*);
	virtual bool init(Gamescene*);
	virtual void update(float);
	virtual ~Player() { for (int i = 0; i < PLAYERACTIONMAX; i++)action[i]->release();}
};
