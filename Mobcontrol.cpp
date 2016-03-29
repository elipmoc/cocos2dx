#include "Gamescene.h"

//¶¬
Mobcontrol* Mobcontrol::create(Gamescene* _scene) {
	Mobcontrol* ret = new (std::nothrow) Mobcontrol();
	if (ret &&ret->init(_scene))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

//‰Šú‰»
bool Mobcontrol::init(Gamescene* _scene) {
	scene = _scene;
	mobcreate();
	return true;
}


//“G¶¬
void Mobcontrol::mobcreate() {
	auto moblist = scene->stagedata->getmoblist();
	for (int i = 0; i < moblist.size(); i++) {
		static Mob* mob;
		switch (moblist.at(i)->mobkind) {
		case Mobkind::mob1:
			mob = Mob1::create(scene);
			break;
		case Mobkind::mob2:
			mob = Mob2::create(scene);
			break;
		case Mobkind::mob3:
			mob = Mob3::create(scene);
			break;
		}
		static Mapcontrol* map;
		map = scene->mapcontrol;
		mob->setPosition(map->transblockcentralxy(moblist.at(i)->mobxy.x, moblist.at(i)->mobxy.y));
		mob->pbody = PhysicsBody::createCircle(5);
		mob->pbody->setRotationEnable(false);
		mob->setpbody(Colisionkind::mob, Colisionkind::player);
		this->addChild(mob);
	}
}