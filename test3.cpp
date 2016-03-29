#include "test3.h"
USING_NS_CC;
bool Test3::init() {
	if (!Layer::init())
	{
		return false;
	}
	//��ʂ̑傫���擾
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//�X�v���C�g�i�摜�̏o�͎菇�j
	//�X�v���C�g�쐬�@�@�@�@�@�@�@�摜�p�X
	sprite = Sprite::create("player.png");
	//�ʒu�ݒ�
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height/2));
	//Test2�ɑg�ݍ��� ���x���A[���s��]
	this->addChild(sprite, 0);

	//�C�x���g���X�i�[�Ǘ��N���X��p��
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	//�L�[�C�x���g���X�i�[�𐶐�
	auto listener = EventListenerKeyboard::create();
	//�L�[�������ꂽ���ɌĂ΂��֐��������_�łԂ�����
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
	//�L�[���͂Ȃ��ꂽ���ɌĂ΂��֐��������_�łԂ�����
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
	//���X�i�[��o�^
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//update�֐����Ăяo����悤�ɂ���
	this->scheduleUpdate();
	return true;
}

void Test3::update(float dt) {
	//�L�[�ɉ����Ĉړ�������
	sprite->setPosition(Vec2(sprite->getPositionX() + speed*addx, sprite->getPositionY() + speed*addy));
}