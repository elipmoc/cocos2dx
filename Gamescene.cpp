#pragma execution_character_set("utf-8")
#include "Gamescene.h"
Gamescene* Gamescene::createWithPhysics(int _stagenom,bool flag2p) {
	{
		Gamescene *ret = new (std::nothrow) Gamescene();
		if (ret && ret->initWithPhysics()&&ret->init(_stagenom,flag2p))
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
}


bool Gamescene::init(int _stagenom,bool flag2p) {
	//グローバル変数初期化
	globalinit();
	//////////物理設定/////////////////
	//物理ワールドを取得
	PhysicsWorld*  pworld = this->getPhysicsWorld();
	//重力設定
	pworld->setGravity(Vec2(0, 0));
	//時間の速さ設定
	pworld->setSpeed(1.0f);
	//デバッグ用の表示設定(剛体表示とか)
	pworld->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
	///////あらかじめ、音楽データを読み込む/////////////
	AudioEngine::preload("explosion.mp3");
	AudioEngine::preload("battleBGM.mp3");
	AudioEngine::preload("bomset.mp3");
	AudioEngine::preload("get.mp3");
	/////背景生成（仮）///////
	auto sprite = Sprite::create("background.png");
	sprite->setPosition(visibleSize.width/2, visibleSize.height/2);
	sprite->setScale(2.2);
	this->addChild(sprite,0);
	/////各種オブジェクトを生成登録/////////
	stagedata = Stagedata::create(_stagenom);
	stage = Stage::create(this);
	firecontrol = Firecontrol::create(this);
	mapcontrol = Mapcontrol::create(this);
	playercontrol = Playercontrol::create(this);
	mobcontrol = Mobcontrol::create(this);
	itemcontrol = Itemcontrol::create();
	colisioncontrol = Colisioncontrol::create();
	addChild(colisioncontrol);
	addChild(stage,3);
	addChild(firecontrol,2);
	addChild(itemcontrol, 1);
	addChild(mapcontrol,1);
	addChild(playercontrol,4);
	addChild(mobcontrol, 3);
	addChild(stagedata);
	
	/////協力プレイのとき//////////
	if (flag2p) {
		playercontrol2p = Playercontrol2p::create(this);
		this->addChild(playercontrol2p, 2);
	}
	return true;
};


