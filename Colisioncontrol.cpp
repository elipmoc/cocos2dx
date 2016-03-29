#include "Gamescene.h"

bool Colisioncontrol::init() {
	if (!Layer::init())return false;
	//�ڐG���ɌĂ΂��֐�����������
	auto contact = EventListenerPhysicsContact::create();

	//�ڐG���ɌĂ΂��֐�
	contact->onContactBegin = [this](PhysicsContact& c) {
		auto  a =(Colision*)(c.getShapeA()->getBody()->getNode());
		auto  b =(Colision*)(c.getShapeB()->getBody()->getNode());
			a->callback(b);
			b->callback(a);
			if (a->desflag)a->getParent()->removeChild(a);
			if (b->desflag)b->getParent()->removeChild(b);
		return true;
	};
	//�ڐG����̓K��
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contact, this);


	return true;
}