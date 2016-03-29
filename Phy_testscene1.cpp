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
	//物理ワールドを取得
	cocos2d::PhysicsWorld*  pworld = scene->getPhysicsWorld();
	//重力設定
	pworld->setGravity(Vec2(0, -50));
	//時間の速さ設定
	pworld->setSpeed(1.0f);
	//デバッグ用の表示設定(剛体表示とか)
	//pworld->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);
	scene->addChild(Phy_test1::create());
	return scene;
};