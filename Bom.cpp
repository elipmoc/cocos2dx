#include "Gamescene.h"



//ì¬-------------------
Bom* Bom::create(const std::string& filename,Gamescene* _m,Bomcontrol* _bomcon) {
	Bom* ret = new (std::nothrow) Bom();
	if (ret&&ret->initWithFile(filename) &&ret->init(_m,_bomcon))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}
//‰Šú‰»----------------------
bool Bom::init(Gamescene* _m,Bomcontrol* _bomcon) {
	scene = _m;
	bomcon = _bomcon;
	AudioEngine::play2d("bomset.mp3");
	scheduleOnce(schedule_selector(Bom::explosion), 3.0f);
	return true;
}

void Bom::explosion(float dt){
	Vec2 v = this->getPosition();
	scene->mapcontrol->getblock(v)->releasebom();
	int plusx, plusy;
	for (int i = 0; i < 4; i++) {
		for (int ii = 0; ii < 2; ii++) {
			switch (i) {
			case 0:
				plusx = 16; plusy = 0;
				break;
			case 1:
				plusx = -16; plusy = 0;
				break;
			case 2:
				plusx = 0; plusy = 16;
				break;
			case 3:
				plusx = 0; plusy = -16;
				break;
			}
			Mapsprite* m = scene->mapcontrol->getblock(Vec2(v.x + plusx*(ii + 1), v.y + plusy*(ii + 1)));
			if (m->gettype() != Blocktype::blank) { m->bombreakblock(); break; }
			else m->bombreakblock();
				
		}
	}
	scene->mapcontrol->getblock(v)->bombreakblock();
	scene->firecontrol->setfire(v);
	AudioEngine::play2d("explosion.mp3");
	auto animation = Animation::create();
	animation->addSpriteFrameWithFile("boms_04.png");
	animation->addSpriteFrameWithFile("boms_05.png");
	animation->addSpriteFrameWithFile("boms_31.png");
	animation->addSpriteFrameWithFile("boms_32.png");
	animation->addSpriteFrameWithFile("boms_33.png");
	animation->addSpriteFrameWithFile("boms_34.png");
	animation->addSpriteFrameWithFile("boms_35.png");
	animation->addSpriteFrameWithFile("boms_36.png");
	animation->setDelayPerUnit(0.05f);
	animation->setRestoreOriginalFrame(true);
	this->runAction(Animate::create(animation));
	scheduleOnce(schedule_selector(Bom::deletebom), 0.4f);
}

void Bom::afterexplosion() {
	unschedule(schedule_selector(Bom::explosion));
	scheduleOnce(schedule_selector(Bom::explosion), 0.05f);
}

void Bom::deletebom(float dt){
	bomcon->removeChild(this);
}