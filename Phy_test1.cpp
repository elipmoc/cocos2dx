#include "Phy_test1.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;

bool Phy_test1::init() {
	if (!Layer::init())
	{
		return false;
	}
	//��ʂ̑傫���擾
	Size visibleSize = Director::getInstance()->getVisibleSize();

	TMXTiledMap* map = TMXTiledMap::create("map1.tmx");
	///map->setPosition(200, 200);
	//this->addChild(map);


	//�X�v���C�g�쐬�@�@�@�@�@�@�@�摜�p�X
	sprite = Sprite::create("hirosi.png");
	//�ʒu�ݒ�
	sprite->setPosition(Vec2(20, 330));
	//�����}�e���A���쐬
	auto material = PHYSICSBODY_MATERIAL_DEFAULT;
	//�����W���ݒ�
	material.restitution = 1.5;
	//�����{�f�B�[�쐬
	auto pbody = PhysicsBody::createCircle(25,material);
	pbody->setDynamic(true);
	pbody->setCategoryBitmask(1);
	pbody->setCollisionBitmask(2);
	pbody->setContactTestBitmask(2);
	//�����{�f�B�[�g�ݍ���
	sprite->setPhysicsBody(pbody);
	//�g�ݍ���
	this->addChild(sprite,1);

	// �`��p�̃m�[�h���쐬
	DrawNode* drawNode = DrawNode::create();
	drawNode->setPosition(Point(0.0f, 0.0f));
	this->addChild(drawNode);

	// �`��
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

	 //�Փ˔���p���X�i�[�𐶐�
	 auto plistener = EventListenerPhysicsContact::create();
	 //�ڐG�����Ƃ�
	 plistener->onContactBegin = [&](PhysicsContact &contact) {
		 soundEngine->playEffect("sound.wav");
		 return true; };
	 //���X�i�[��g�ݍ���
	 this->getEventDispatcher()->
		 addEventListenerWithSceneGraphPriority(plistener, this);
	return true;
}
