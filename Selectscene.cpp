#pragma execution_character_set("utf-8")
#include "Selectscene.h"
#include "Stageexplanationscene.h"

bool Selectscene::init() {
	if (!Scene::init())return false;
	audioid = AudioEngine::play2d("menu.mp3", true);
	auto sprite = Sprite::create("menu.png");
	//画面の大きさ取得
	auto visibleSize = Director::getInstance()->getVisibleSize();
	sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	sprite->setScale(2.2);
	this->addChild(sprite);
	key = Observekey::create();
	this->addChild(key);
	auto label = Label::createWithTTF("ステージセレクト","fonts/meiryo.ttc",24);
	label->setPosition(visibleSize.width / 2, visibleSize.height - 20);
	stagetext=Label::createWithTTF("STAGE1", "fonts/meiryo.ttc", 24);
	stagetext->setPosition(visibleSize.width / 2, visibleSize.height - 60);
	this->addChild(label);
	this->addChild(stagetext);
	scheduleUpdate();
	return true;
}

void Selectscene::update(float dt) {
	if (key->getkey(Observekey::Key::enter) == 2) {
		AudioEngine::stop(audioid);
		AudioEngine::play2d("select.mp3");
		Scene* pScene = TransitionFade::create(1, Stageexplanationscene::create(figure));
		if (pScene) {
			Director::getInstance()->replaceScene(pScene);
		}
	}
	if (key->getkey(Observekey::Key::down1) == 2) {
		figure++;
		char str[10];
		sprintf(str, "STAGE%d", figure);
		stagetext->setString(str);
	}
	if (key->getkey(Observekey::Key::up1) == 2) {
		figure--;
		char str[10];
		sprintf(str, "STAGE%d", figure);
		stagetext->setString(str);
	}
}