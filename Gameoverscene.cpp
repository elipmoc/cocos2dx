#pragma execution_character_set("utf-8")
#include "Gameoverscene.h"
#include "Titlescene.h"

bool Gameoverscene::init() {
	if (!Scene::init())return false;
	audioid = AudioEngine::play2d("victory.mp3", true);
	auto sprite = Sprite::create("clear.png");
	//��ʂ̑傫���擾
	auto visibleSize = Director::getInstance()->getVisibleSize();
	sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(sprite);
	key = Observekey::create();
	this->addChild(key);
	auto label = Label::createWithTTF("�A�i�^�͎��ɂ܂���", "fonts/meiryo.ttc", 50);
	label->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(label);
	scheduleUpdate();
	return true;
}

void Gameoverscene::update(float dt) {
	if (key->getkey(Observekey::Key::enter) == 2) {
		AudioEngine::stop(audioid);
		AudioEngine::play2d("select.mp3");
		Scene* pScene = TransitionFade::create(1, Titlescene::create());
		if (pScene) {
			Director::getInstance()->replaceScene(pScene);
		}
	}
}