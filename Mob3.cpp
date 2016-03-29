#include "Gamescene.h"

bool Mob3::init() {
	if (!this->initWithFile("yagi.png"))return false;
	setmovev();
	scheduleUpdate();
	return true;
}

//�ړ����������߂�
void Mob3::setmovev() {
	switch (random() % 4)
	{
	case 0:
		movev = Vec2(16, 0);
		break;
	case 1:
		movev = Vec2(-16, 0);
		break;
	case 2:
		movev = Vec2(0, 16);
		break;
	case 3:
		movev = Vec2(0, -16);
		break;
	}
}
void Mob3::update(float dt) {
	//////�ړ�////////////////////////
	//move�A�j���[�V�������Ă��Ȃ��Ƃ�
	if (getActionByTag(1) == nullptr || getActionByTag(1)->getTarget() == nullptr) {
		//�ړ���ɏ�Q�����Ȃ��Ƃ�
		if (scene->mapcontrol->getblock(Vec2(getPositionX() + movev.x, getPositionY()+movev.y))->obstaclecheck() == false) {
			//1�u���b�N���ړ�
			auto move = MoveBy::create(0.4f, movev);
			move->setTag(1);
			runAction(move);
		}else setmovev();
	}
	
	if (scene->mapcontrol->getblock(this->getPosition())->firenull() == false) {
		scene->mobcontrol->removeChild(this);
	}
}