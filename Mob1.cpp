#include "Gamescene.h"
bool Mob1::init() {
	if (!this->initWithFile("yagi.png"))return false;

	scheduleUpdate();
	return true;
}

void Mob1::update(float dt) {
	//////移動////////////////////////
	//moveアニメーションしていないとき
	if (getActionByTag(1) == nullptr || getActionByTag(1)->getTarget() == nullptr) {

		//移動先に障害物がないとき
		if (scene->mapcontrol->getblock(Vec2(getPositionX(), getPositionY()+y))->obstaclecheck() == false) {
			//1ブロック分移動
			auto move = MoveBy::create(0.5f, Vec2(0, y));
			move->setTag(1);
			runAction(move);
		}
		else {
			y *= -1;
		}
	}
	if (scene->mapcontrol->getblock(this->getPosition())->firenull() == false) {
		scene->mobcontrol->removeChild(this);
	}
}