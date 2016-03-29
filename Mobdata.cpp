#include "Mobdata.h"

Mobdata* Mobdata::create(ValueMap data) {
	Mobdata* ret = new (std::nothrow) Mobdata();
	if (ret &&ret->init(data))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool Mobdata::init(ValueMap& data) {
	if (!Layer::init())return false;
	mobkind=(Mobkind)data["mobkind"].asInt();
	mobxy.x = data["mobx"].asInt();
	mobxy.y = data["moby"].asInt();
	return true;
}