#pragma execution_character_set("utf-8")
#include "Gamescene.h"
#include "Gameoverscene.h"


bool Playercontrol::init(Gamescene* _scene) {
	if (!Player::init(_scene))return false;
	//ƒL[‚ðÝ’è‚·‚é
	playerkey.right = (int)Observekey::Key::right1;
	playerkey.left = (int)Observekey::Key::left1;
	playerkey.down = (int)Observekey::Key::down1;
	playerkey.up = (int)Observekey::Key::up1;
	playerkey.bomset = (int)Observekey::Key::bomset1;

	return true;
}


Playercontrol* Playercontrol::create(Gamescene* _scene)
{
	Playercontrol *ret = new (std::nothrow) Playercontrol();
	if (ret &&ret->init(_scene))
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
