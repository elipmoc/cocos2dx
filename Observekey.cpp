#include "Observekey.h"
USING_NS_CC;
bool Observekey::init() {
	if (!Layer::init()) {
		return false;
	}
	//イベントリスナー管理クラスを用意
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	//キーイベントリスナーを生成
	auto listener = EventListenerKeyboard::create();
	//キーが押された時に呼ばれる関数をラムダでぶっこむ
	listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
			if (keyCode == EventKeyboard::KeyCode::KEY_D) {
				keycount[(int)(Key::right1)]++;
			}else
			if (keyCode == EventKeyboard::KeyCode::KEY_A) {
				keycount[(int)(Key::left1)]++;
			}else
			if (keyCode == EventKeyboard::KeyCode::KEY_W) {
				keycount[(int)(Key::up1)]++;
			}else
			if (keyCode == EventKeyboard::KeyCode::KEY_S) {
				keycount[(int)(Key::down1)]++;
			}else
			if (keyCode == EventKeyboard::KeyCode::KEY_CTRL) {
				keycount[(int)(Key::bomset1)]++;
			}else
			if (keyCode == EventKeyboard::KeyCode::KEY_L) {
				keycount[(int)(Key::right2)]++;
			}else
			if (keyCode == EventKeyboard::KeyCode::KEY_J) {
				keycount[(int)(Key::left2)]++;
			}else
			if (keyCode == EventKeyboard::KeyCode::KEY_I) {
				keycount[(int)(Key::up2)]++;
			}else
			if (keyCode == EventKeyboard::KeyCode::KEY_K) {
				keycount[(int)(Key::down2)]++;
			}else
			if (keyCode == EventKeyboard::KeyCode::KEY_SLASH) {
			keycount[(int)(Key::bomset2)]++;
			}else
			if (keyCode == EventKeyboard::KeyCode::KEY_ENTER) {
				keycount[(int)(Key::enter)]++;
			}
	};
	//キーがはなされた時に呼ばれる関数をラムダでぶっこむ
	listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == EventKeyboard::KeyCode::KEY_D) {
			keycount[(int)(Key::right1)]=0;
		}else
		if (keyCode == EventKeyboard::KeyCode::KEY_A) {
			keycount[(int)(Key::left1)]=0;
		}else
		if (keyCode == EventKeyboard::KeyCode::KEY_W) {
			keycount[(int)(Key::up1)]=0;
		}else
		if (keyCode == EventKeyboard::KeyCode::KEY_S) {
			keycount[(int)(Key::down1)]=0;
		}else
		if (keyCode == EventKeyboard::KeyCode::KEY_CTRL) {
			keycount[(int)(Key::bomset1)]=0;
		}else
		if (keyCode == EventKeyboard::KeyCode::KEY_L) {
			keycount[(int)(Key::right2)]=0;
		}else
		if (keyCode == EventKeyboard::KeyCode::KEY_J) {
			keycount[(int)(Key::left2)]=0;
		}else
		if (keyCode == EventKeyboard::KeyCode::KEY_I) {
			keycount[(int)(Key::up2)]=0;
		}else
		if (keyCode == EventKeyboard::KeyCode::KEY_K) {
			keycount[(int)(Key::down2)]=0;
		}else
		if (keyCode == EventKeyboard::KeyCode::KEY_SLASH) {
			keycount[(int)(Key::bomset2)]=0;
		}else
		if (keyCode == EventKeyboard::KeyCode::KEY_ENTER) {
			keycount[(int)(Key::enter)] = 0;
		}
	};
	//リスナーを登録
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	//update関数を呼び出せるようにする
	this->scheduleUpdate();
	return true;
}

void Observekey::update(float dt){
	for (int i = 0;i<KEYMAX; i++) {
		if (keycount[i] > 0)keycount[i]++;
	}
}

int Observekey::getkey(const Key k) {
	return keycount[(int)(k)];
}