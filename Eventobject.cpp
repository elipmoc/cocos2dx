#include "Gamescene.h"

bool Eventobject::_init(Gamescene* _scene) {
	if (!Layer::init())return false;
	scene = _scene;
	return true;
}