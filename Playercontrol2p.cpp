#pragma execution_character_set("utf-8")
#include "Gamescene.h"
#include "Gameoverscene.h"


bool Playercontrol2p::init(Gamescene* _scene) {
	if (!Player::init(_scene))return false;
	//ƒL[‚ðÝ’è‚·‚é
	playerkey.right = (int)Observekey::Key::right2;
	playerkey.left = (int)Observekey::Key::left2;
	playerkey.down = (int)Observekey::Key::down2;
	playerkey.up = (int)Observekey::Key::up2;
	playerkey.bomset = (int)Observekey::Key::bomset2;
	setColor(Color3B(200, 155, 255));

	return true;
}

Playercontrol2p* Playercontrol2p::create(Gamescene* _scene)
{
	Playercontrol2p *ret = new (std::nothrow) Playercontrol2p();
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
