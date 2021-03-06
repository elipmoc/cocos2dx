#include "Gamescene.h"

bool Colisioncontrol::init() {
	if (!Layer::init())return false;
	//接触時に呼ばれる関数を実装する
	auto contact = EventListenerPhysicsContact::create();

	//接触時に呼ばれる関数
	contact->onContactBegin = [this](PhysicsContact& c) {
		auto  a =(Colision*)(c.getShapeA()->getBody()->getNode());
		auto  b =(Colision*)(c.getShapeB()->getBody()->getNode());
			a->callback(b);
			b->callback(a);
			if (a->desflag)a->getParent()->removeChild(a);
			if (b->desflag)b->getParent()->removeChild(b);
		return true;
	};
	//接触判定の適応
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contact, this);


	return true;
}