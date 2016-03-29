#include "Gamescene.h"

Firesprite* Firesprite::create(const std::string& filename, Gamescene* _m, Firecontrol* _firecon) {
	Firesprite* sprite = new (std::nothrow) Firesprite();
	if (sprite &&sprite->initWithFile(filename) && sprite->init(_m, _firecon))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool Firesprite::init(Gamescene* _m, Firecontrol* _firecon) {
	scene = _m;
	firecon = _firecon;
	return true;
}

void Firesprite::clear() {
	scheduleOnce(schedule_selector(Firesprite::deletefire), 0.4f);
	this->runAction(action);
}

void Firesprite::deletefire(float dt) {
	Vec2 v = this->getPosition();
	scene->mapcontrol->getblock(v)->releasefire();
	activeflag = false;
	firecon->removeChild(this);
}

Firesprite::~Firesprite(){
	action->release();
}

