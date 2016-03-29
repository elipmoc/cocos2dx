#include "test3.h"
USING_NS_CC;
bool Test3::init() {
	if (!Layer::init())
	{
		return false;
	}
	//画面の大きさ取得
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//スプライト（画像の出力手順）
	//スプライト作成　　　　　　　画像パス
	sprite = Sprite::create("player.png");
	//位置設定
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height/2));
	//Test2に組み込み ラベル、[奥行き]
	this->addChild(sprite, 0);

	//イベントリスナー管理クラスを用意
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	//キーイベントリスナーを生成
	auto listener = EventListenerKeyboard::create();
	//キーが押された時に呼ばれる関数をラムダでぶっこむ
	listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == EventKeyboard::KeyCode::KEY_D) {
			addx=1;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_A) {
			addx=-1;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_W) {
			addy=1;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_S) {
			addy=-1;
		}
	};
	//キーがはなされた時に呼ばれる関数をラムダでぶっこむ
	listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (keyCode == EventKeyboard::KeyCode::KEY_D &&addx==1) {
			addx = 0;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_A &&addx == -1) {
			addx = 0;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_W &&addy == 1) {
			addy = 0;
		}
		if (keyCode == EventKeyboard::KeyCode::KEY_S &&addy == -1) {
			addy = 0;
		}
	};
	//リスナーを登録
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//update関数を呼び出せるようにする
	this->scheduleUpdate();
	return true;
}

void Test3::update(float dt) {
	//キーに応じて移動させる
	sprite->setPosition(Vec2(sprite->getPositionX() + speed*addx, sprite->getPositionY() + speed*addy));
}