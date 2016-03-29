#include "Gamescene.h"

bool Eventobject::_init(Gamescene* _scene) {
	if (!Sprite::init())return false;
	scene = _scene;
	return true;
}