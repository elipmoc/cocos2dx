#include "Phy_test1.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

bool Phy_test1::init() {
	if (!Layer::init())
	{
		return false;
	}
	//画面の大きさ取得
	Size visibleSize = Director::getInstance()->getVisibleSize();

	TMXTiledMap* map = TMXTiledMap::create("map1.tmx");
	///map->setPosition(200, 200);
	//this->addChild(map);


	//スプライト作成　　　　　　　画像パス
	sprite = Sprite::create("hirosi.png");
	//位置設定
	sprite->setPosition(Vec2(20, 330));
	//物理マテリアル作成
	auto material = PHYSICSBODY_MATERIAL_DEFAULT;
	//反発係数設定
	material.restitution = 1.5;
	//物理ボディー作成
	auto pbody = PhysicsBody::createCircle(25,material);
	pbody->setDynamic(true);
	pbody->setCategoryBitmask(1);
	pbody->setCollisionBitmask(2);
	pbody->setContactTestBitmask(2);
	//物理ボディー組み込み
	sprite->setPhysicsBody(pbody);
	//組み込み
	this->addChild(sprite,1);

	// 描画用のノードを作成
	DrawNode* drawNode = DrawNode::create();
	drawNode->setPosition(Point(0.0f, 0.0f));
	this->addChild(drawNode);

	// 描画
	const Point vertexes[] = {
		Point(visibleSize.width-10, 30),
		Point(visibleSize.width - 10, 10),
		Point(10, 10),
		Point(10, 70),
	};
	const float weight = 0;
	drawNode->drawPolygon(vertexes, 4, Color4F::WHITE, weight, Color4F::RED);
	 pbody = PhysicsBody::createPolygon(vertexes,4);
	 pbody->setDynamic(false);
	 pbody->setCategoryBitmask(2);
	 pbody->setCollisionBitmask(1);
	 pbody->setContactTestBitmask(1);
	 drawNode->setPhysicsBody(pbody);
	 static auto soundEngine = SimpleAudioEngine::getInstance();
	 soundEngine->setEffectsVolume(1.0f);
	 soundEngine->preloadEffect("sound.wav");

	 //衝突判定用リスナーを生成
	 auto plistener = EventListenerPhysicsContact::create();
	 //接触したとき
	 plistener->onContactBegin = [&](PhysicsContact &contact) {
		 soundEngine->playEffect("sound.wav");
		 return true; };
	 //リスナーを組み込む
	 this->getEventDispatcher()->
		 addEventListenerWithSceneGraphPriority(plistener, this);
	return true;
}
