#include "Gamescene.h"

bool Firecontrol::setfire(Vec2 v) {
	if (scene->mapcontrol->getblock(v)->firenull() == false)return false;
	static Firesprite* fire = NULL;
	////プールから、非アクティブなfirespriteを取り出す///////
	for (int i=0;i<firepool.size(); i++) {
		if (firepool.at(i)->activeflag == false) {
			fire = firepool.at(i);
			fire->activeflag = true;
			break;
		}
	}
	///////登録と初期化////////////////
	fire->setPosition(v);
	fire->clear();
	this->addChild(fire);
	scene->mapcontrol->getblock(v)->havefire(fire);
	return true;
}

bool Firecontrol::init(Gamescene* _m) {
	if (!Layer::init())return false;
	
	scene = _m;
	////firespriteのアニメーション作成////////////////////
	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("bmb_o6_5.png");
	animation->addSpriteFrameWithFile("bmb_o6_4.png");
	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	auto action=RepeatForever::create(Animate::create(animation));
	
	//あらかじめ、firespriteを確保/////////////
	firepool = Vector<Firesprite*>();
	for (int i = 0; i < 1000; i++) {
		static Firesprite* fire = NULL;
		fire = Firesprite::create("bmb_o6_4.png", scene, this);
		fire->setScaleX(0.55f*2.0f);
		fire->setScaleY(0.25f*2.0f);
		fire->action=action->clone();
		fire->action->retain();
		firepool.pushBack(fire);
	}
	return true;
}

Firecontrol* Firecontrol::create(Gamescene* _m)
{
	Firecontrol* layer = new (std::nothrow) Firecontrol();
	if (layer && layer->init(_m))
	{
		layer->autorelease();
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return nullptr;
}
