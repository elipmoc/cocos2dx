#include "Gamescene.h"
#include "Clearscene.h"


Stage* Stage::create(Gamescene* _m) {
	Stage *ret = new(std::nothrow) Stage();
	if (ret && ret->init(_m)) {
		ret->autorelease();
			return ret;
	}
	else {
		delete ret;
		ret = nullptr;
		return nullptr;
	}
}

void Stage::clear() {
	AudioEngine::stopAll();
	AudioEngine::play2d("stageclear.mp3");
	scene->playercontrol->pause();
	if (scene->playercontrol2p != NULL) {
		scene->playercontrol2p->pause();
	}
	auto label = Label::createWithTTF("ステージクリア", "fonts/meiryo.ttc", 40);
	label->setTag(labeltag);
	label->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(label,1);
	scheduleOnce(schedule_selector(Stage::nextstage), 4.0f);
}

//次のステージを準備する
void Stage::nextstage(float dt) {
	AudioEngine::play2d("battleBGM.mp3", true, 0.5);
	removeChild(getChildByTag(labeltag));//テロップを消す
	removeChild(getChildByTag(portaltag));//ポータルを消す
	portalflag = false;
	scene->stagedata->recreate(scene->stagedata->getstagekind()+1);
	scene->mapcontrol->recreate();
	scene->itemcontrol->removeAllChildren();
	scene->mobcontrol->mobcreate();
	scene->playercontrol->resume();
	scene->playercontrol->setfirstposition();
	if (scene->playercontrol2p != NULL) {
		scene->playercontrol2p->resume();
		scene->playercontrol2p->setfirstposition();
	}
}

void Stage::setportal() {
	auto sprite = Portal::create(this);
	sprite->setScale(2.2);
	sprite->setPosition(scene->mapcontrol->transblockcentralxy(portalv.x,portalv.y));
	sprite->setTag(portalflag);
	this->addChild(sprite);
}

bool Stage::init(Gamescene* _m) {
	if (!Layer::init())return false;
	scene = _m;
	AudioEngine::play2d("battleBGM.mp3", true, 0.5);
	portalv = scene->stagedata->getportalposition();
	scheduleUpdate();
	return true; }

void Stage::update(float dt) {
	if (scene->mobcontrol->mobcount() == 0 && portalflag == false) {
		setportal();
		portalflag = true;
	}
}

