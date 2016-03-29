#include "Gamescene.h"

//����-----------------------
Item* Item::create(const Itemkind kind,Itemcontrol* _itemcon) {
	Item* ret = new (std::nothrow) Item();
	static char filename[14];
	sprintf(filename, "item%d.png", (int)kind+1);
	if (ret&&ret->initWithFile(filename) && ret->init(_itemcon,kind))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

//������----------------------
bool Item::init(Itemcontrol* _itemcon,Itemkind kind) {
	itemkind = kind;
	itemcon = _itemcon;
	pbody = PhysicsBody::createBox(Rect(0, 0, 6, 6).size);
	setpbody(Colisionkind::item, Colisionkind::player);
	return true;
}

//�����蔻��R�[���o�b�N---------------
void Item::callback(Colision* c) {
	if (c->getPhysicsBody()->getTag() == Colisionkind::player) {
		c->callback(this);
		this->desflag = true;
		AudioEngine::play2d("get.mp3");
	}
}