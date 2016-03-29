#pragma once
class Item;
class Player;
class Colision :public Sprite {
public:
	bool desflag = false;
	//剛体
	PhysicsBody* pbody;
	//     自分のカテゴリー、衝突判定する相手のカテゴリー
	void setpbody(int tag,int totag);
	virtual void callback(Colision*) {};
	virtual void callback(Item* i) {};
};