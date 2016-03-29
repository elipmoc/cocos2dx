#include "Gamescene.h"

bool Colisioncontrol::init() {
	if (!Layer::init())return false;
	//ÚGŽž‚ÉŒÄ‚Î‚ê‚éŠÖ”‚ðŽÀ‘•‚·‚é
	auto contact = EventListenerPhysicsContact::create();

	//ÚGŽž‚ÉŒÄ‚Î‚ê‚éŠÖ”
	contact->onContactBegin = [this](PhysicsContact& c) {
		auto  a =(Colision*)(c.getShapeA()->getBody()->getNode());
		auto  b =(Colision*)(c.getShapeB()->getBody()->getNode());
			a->callback(b);
			b->callback(a);
			if (a->desflag)a->getParent()->removeChild(a);
			if (b->desflag)b->getParent()->removeChild(b);
		return true;
	};
	//ÚG”»’è‚Ì“K‰ž
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contact, this);


	return true;
}