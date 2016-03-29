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
	//キー判定クラス
	Observekey* obsevekey;
	//ボム操作クラス
	Bomcontrol* bomcon;
	//主人公アニメーション
	cocos2d::RepeatForever* action[PLAYERACTIONMAX];
	void gameover();
	//ボム設置
	void bomset();
public:
	void setfirstposition();
	virtual void callback(Item*);
	virtual void callback(Colision*);
	virtual bool init(Gamescene*);
	virtual void update(float);
	virtual ~Player() { for (int i = 0; i < PLAYERACTIONMAX; i++)action[i]->release();}
};
