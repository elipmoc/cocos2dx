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
	//�O���[�o���ϐ�������
	globalinit();
	//////////�����ݒ�/////////////////
	//�������[���h���擾
	PhysicsWorld*  pworld = this->getPhysicsWorld();
	//�d�͐ݒ�
	pworld->setGravity(Vec2(0, 0));
	//���Ԃ̑����ݒ�
	pworld->setSpeed(1.0f);
	//�f�o�b�O�p�̕\���ݒ�(���̕\���Ƃ�)
	pworld->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
	///////���炩���߁A���y�f�[�^��ǂݍ���/////////////
	AudioEngine::preload("explosion.mp3");
	AudioEngine::preload("battleBGM.mp3");
	AudioEngine::preload("bomset.mp3");
	AudioEngine::preload("get.mp3");
	/////�w�i�����i���j///////
	auto sprite = Sprite::create("background.png");
	sprite->setPosition(visibleSize.width/2, visibleSize.height/2);
	sprite->setScale(2.2);
	this->addChild(sprite,0);
	/////�e��I�u�W�F�N�g�𐶐��o�^/////////
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
	
	/////���̓v���C�̂Ƃ�//////////
	if (flag2p) {
		playercontrol2p = Playercontrol2p::create(this);
		this->addChild(playercontrol2p, 2);
	}
	return true;
};


