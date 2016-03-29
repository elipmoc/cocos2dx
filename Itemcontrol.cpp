#include "Gamescene.h"

bool Itemcontrol::init() {
	if (!Layer::init())return false;
	return true;
}

void Itemcontrol::setitem(Vec2 v) {
	auto item = Item::create((Itemkind)(random() % 3),this);
	item->setPosition(v);
	this->addChild(item);
}
