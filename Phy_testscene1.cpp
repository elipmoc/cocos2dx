#include "Phy_testscene1.h"
USING_NS_CC;

bool Phy_testscene1::init() {
	if (!Scene::init())
	{
		return false;
	}


	this->addChild(Phy_test1::create());
	return true;
}

Scene* Phy_testscene1::createscene() {
	auto scene = Phy_testscene1::createWithPhysics();
	//�������[���h���擾
	cocos2d::PhysicsWorld*  pworld = scene->getPhysicsWorld();
	//�d�͐ݒ�
	pworld->setGravity(Vec2(0, -50));
	//���Ԃ̑����ݒ�
	pworld->setSpeed(1.0f);
	//�f�o�b�O�p�̕\���ݒ�(���̕\���Ƃ�)
	//pworld->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
	scene->addChild(Phy_test1::create());
	return scene;
};