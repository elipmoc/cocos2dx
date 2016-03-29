#include "Gamescene.h"

USING_NS_CC;

bool Bomcontrol::setbom(Vec2 v) {
	static Bom* bom=NULL;
	if (scene->mapcontrol->getblock(v)->bomnull() == false)return false;
	bom = Bom::create("boms_02.png",scene,this);
	bom->setPosition(v);
	this->addChild(bom);
	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("boms_02.png");
	animation->addSpriteFrameWithFile("boms_03.png");
	animation->setDelayPerUnit(0.5f);
	animation->setRestoreOriginalFrame(true);
	action = RepeatForever::create(Animate::create(animation));
	bom->runAction(action);
	scene->mapcontrol->getblock(v)->havebom(bom);
	return true;
}

bool Bomcontrol::init(Gamescene* _m) {
	if (!Layer::init())return false;
	scene = _m;
	return true;
}

Bomcontrol* Bomcontrol::create(Gamescene* _m)
{
	Bomcontrol* layer = new (std::nothrow) Bomcontrol();
	if (layer && layer->init(_m))
	{
		layer->autorelease();
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return nullptr;
}
