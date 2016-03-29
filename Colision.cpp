#include "Gamescene.h"

void Colision::setpbody(int tag, int totag) {
	pbody->setCategoryBitmask(tag);
	pbody->setTag(tag);
	pbody->setContactTestBitmask(totag);
	pbody->setCollisionBitmask(0);
	setPhysicsBody(pbody);
}