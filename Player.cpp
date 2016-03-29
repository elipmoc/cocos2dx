#pragma execution_character_set("utf-8")
#include "Gamescene.h"
#include "Gameoverscene.h"

//�{���ݒu
void Player::bomset() {
	//�{����ݒu������W�𓾂�
	const Vec2 central = scene->mapcontrol->transblockcentralxy(getPosition());
	//�{���ݒu
	bomcon->setbom(central);
}

//�Q�[���I�[�o�[�ɂ���
void Player::gameover() {
	if (desflag == false) {
		desflag = true;
		AudioEngine::stopAll();
		Scene* pScene = TransitionFade::create(1, Gameoverscene::create());
		if (pScene) {
			Director::getInstance()->replaceScene(pScene);
		}
	}
}

//������
bool Player::init(Gamescene* _scene) {
	if (!Sprite::init())return false;
	scene = _scene;
	//�X�v���C�g�쐬
	this->setTexture("�V���{����.png");
	setAnchorPoint(Vec2(0.5f, 0.3f));
	setScale(2);
	//���̐ݒ�
	pbody = PhysicsBody::createBox(Rect(0.0f, 0.0f, 4.0f, 5.0f).size);
	//�X�v���C�g���S����i0,-5�j���炷
	pbody->setPositionOffset(Vec2(0.0f, -5.0f));
	pbody->setDynamic(false);
	setpbody(Colisionkind::player, Colisionkind::mob + Colisionkind::portal+Colisionkind::item);
	setfirstposition();
	//�L�[�Ď��N���X��������
	obsevekey = Observekey::create();
	this->addChild(obsevekey);
	//�{������N���X��������
	bomcon = Bomcontrol::create(scene);
	scene->addChild(bomcon, 2);
	Animation* animation;
	char filename[20];
	for (int i = 0; i < PLAYERACTIONMAX; i++) {
		animation = Animation::create();
		sprintf(filename, "�V���{��_0%d.png", i * 2 + 1);
		animation->addSpriteFrameWithFile(filename);
		sprintf(filename, "�V���{��_0%d.png", i * 2 + 2);
		animation->addSpriteFrameWithFile(filename);
		animation->setDelayPerUnit(0.2f);
		animation->setRestoreOriginalFrame(true);
		action[i] = RepeatForever::create(Animate::create(animation));
		action[i]->retain();
		action[i]->setTag(2);
	}
	//update�֐����Ăяo����悤�ɂ���
	this->scheduleUpdate();
	return true;
}

//�����ʒu�ݒ�
void Player::setfirstposition() {
	stopAllActions();
	Vec2 position = scene->stagedata->getplayerposition();
	setPosition(scene->mapcontrol->transblockcentralxy(position.x, position.y));
}


//�����蔻��R�[���o�b�N
void Player::callback(Colision* c) {
	if (c->getPhysicsBody()->getTag() == Colisionkind::mob)gameover();
}

//�_�u���f�B�X�p�b�`
void Player::callback(Item* item) {
	if (item->getitemkind() == Itemkind::speedup) {
		speed -= 0.01f;
	}else
		if (item->getitemkind() == Itemkind::bommaxup) {
			maximumbom++;
		}
}


void Player::update(float dt) {
	//////////�����ɓ������Ă���Q�[���I�[�o�[�ɂ���///////////
	if (scene->mapcontrol->getblock(getPosition())->firenull() == false) {
		gameover();
	}
	///////enter�L�[�Ń{���ݒu///////////////
	if (obsevekey->getkey((Observekey::Key)playerkey.bomset) == 2
		&& bomcon->getChildrenCount()<maximumbom) {
		bomset();
	}
	//////��l���ړ�////////////////////////
	//��l����move�A�j���[�V�������Ă��Ȃ��Ƃ�
	if (getActionByTag(1) == nullptr) {
		static int x = 0, y = 0;
		if (obsevekey->getkey((Observekey::Key)playerkey.right) != 0) {

			if (x == 16 && y == 0) {}
			else {
				setTexture("�V���{���E.png");
				stopActionByTag(2);
				runAction(action[RIGHT]);
				x = 16; y = 0;
			}
		}
		else if (obsevekey->getkey((Observekey::Key)playerkey.left) != 0) {
			if (x == -16 && y == 0) {}
			else {
				setTexture("�V���{����.png");
				stopActionByTag(2);
				runAction(action[LEFT]);
				x = -16; y = 0;
			}
		}
		else if (obsevekey->getkey((Observekey::Key)playerkey.up) != 0) {
			if (x == 0 && y == 16) {}
			else {
				setTexture("�V���{���O.png");
				stopActionByTag(2);
				runAction(action[FRONT]);
				x = 0; y = 16;
			}
		}
		else if (obsevekey->getkey((Observekey::Key)playerkey.down) != 0) {
			if (x == 0 && y == -16) {}
			else {
				setTexture("�V���{����.png");
				stopActionByTag(2);
				runAction(action[BACK]);
				x = 0; y = -16;
			}
		}
		else { stopActionByTag(2); x = 0; y = 0; return; }
		//�ړ���ɏ�Q�����Ȃ��Ƃ�
		//if (scene->mapcontrol->getblock(Vec2(getPositionX() + x,getPositionY() + y))->obstaclecheck() == false) {
			//1�u���b�N���ړ�
			auto move = MoveBy::create(speed, Vec2(x, y));
			move->setTag(1);
			runAction(move);
		//}

	}
}