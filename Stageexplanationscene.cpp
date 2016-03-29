#pragma execution_character_set("utf-8")
#include "Stageexplanationscene.h"
#include  "Gamescene.h"

Stageexplanationscene* Stageexplanationscene::create(int _figure) {
	Stageexplanationscene *ret = new (std::nothrow) Stageexplanationscene();
	if (ret && ret->init(_figure))
	{
		ret->autorelease();
		return ret;
	}
	else
	{
		CC_SAFE_DELETE(ret);
		return nullptr;
	}
}

bool Stageexplanationscene::init(int _figure) {
	if (!Scene::init())return false;
	key = Observekey::create();
	this->addChild(key);
	figure = _figure;
	////ステージナンバー表示////////////
	char str[10];
	sprintf(str, "STAGE%d", figure);
	auto stagefigure = Label::createWithTTF(str, "fonts/meiryo.ttc", 20);
	stagefigure->setAnchorPoint(Vec2(0, 1));
	stagefigure->setPosition(0, 320);
	this->addChild(stagefigure);
	//////1ｐ、2ｐ選択表示///////
	auto playermode = Label::createWithTTF("一人プレイ", "fonts/meiryo.ttc", 20);
	playermode->setPosition(240, 40);
	playermode->setTag(0);
	this->addChild(playermode);
	scheduleUpdate();
	return true;
}

void Stageexplanationscene::update(float dt) {
	if (key->getkey(Observekey::Key::enter) == 2) {
		AudioEngine::play2d("select.mp3");
		Scene* pScene = TransitionFade::create(1, Gamescene::createWithPhysics(figure,flag2p));
		if (pScene) {
			Director::getInstance()->replaceScene(pScene);
		}
	}
	if (key->getkey(Observekey::Key::right1) == 2) {
		flag2p = true;
		((Label*)this->getChildByTag(0))->setString("協力プレイ");
	}
	if (key->getkey(Observekey::Key::left1) == 2) {
		flag2p = false;
		((Label*)this->getChildByTag(0))->setString("一人プレイ");
	}
}