#include "Gamescene.h"

bool Portal::init(Stage* _stage){
	if (!initWithFile("portal.png"))return false;
	stage = _stage;
	//„‘ÌÝ’è////////
	pbody = PhysicsBody::createBox(Rect(0,0,6,6).size);
	setpbody(Colisionkind::portal,Colisionkind::player);
	return true;
}

void Portal::callback(Colision* c) {
	if(c->getPhysicsBody()->getTag()==Colisionkind::player)stage->clear();
}

Portal* Portal::create(Stage* _stage) {
	Portal* ret = new (std::nothrow) Portal();
	if (ret &&ret->init(_stage))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}