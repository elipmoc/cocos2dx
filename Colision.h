#pragma once
class Item;
class Player;
class Colision :public Sprite {
public:
	bool desflag = false;
	//����
	PhysicsBody* pbody;
	//     �����̃J�e�S���[�A�Փ˔��肷�鑊��̃J�e�S���[
	void setpbody(int tag,int totag);
	virtual void callback(Colision*) {};
	virtual void callback(Item* i) {};
};