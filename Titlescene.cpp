#include "Titlescene.h"
#include "Selectscene.h"

bool Titlescene::init() {
	if (!Scene::init())return false;
	audioid=AudioEngine::play2d("title.mp3",true);
	auto sprite = Sprite::create("title.png");
	//‰æ–Ê‚Ì‘å‚«‚³Žæ“¾
	auto visibleSize = Director::getInstance()->getVisibleSize();
	sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	sprite->setScale(2.2);
	this->addChild(sprite);
	key = Observekey::create();
	this->addChild(key);
	scheduleUpdate();
	return true;
}

void Titlescene::update(float dt) {
	if (key->getkey(Observekey::Key::enter) == 2) {
		AudioEngine::stop(audioid);
		AudioEngine::play2d("select.mp3");
		Scene* pScene = TransitionMoveInR::create(1,Selectscene::create());
		if (pScene) {
			Director::getInstance()->replaceScene(pScene);
		}


	}
}