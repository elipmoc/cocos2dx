#pragma once
#pragma execution_character_set("utf-8")
#include "cocos2d.h"
class Colisionkind {
public:
	static const int player = 1, mob = 2, portal = 4, item = 8;
};
class Gamescene;
using namespace cocos2d;
using namespace experimental;
#include "Colision.h"
#include "Colisioncontrol.h"
#include "Stagedata.h"
#include "Stage.h"
#include "Portal.h"
#include "Itemcontrol.h"
#include "Item.h"
#include "Firecontrol.h"
#include "Firesprite.h"
#include "Bomcontrol.h"
#include "Bom.h"
#include "Mapsprite.h"
#include "Mapcontrol.h"
#include "Eventcontrol.h"
#include "Eventobject.h"
#include "Player.h"
#include "Playercontrol.h"
#include "Playercontrol2p.h"
#include "Mobcontrol.h"
#include "Mob.h"
#include "Mob1.h"
#include "Mob2.h"
#include "Mob3.h"
#include "global.h"
#include "AudioEngine.h"


class Gamescene : public cocos2d::Scene
{
	virtual bool init(int,bool);
    //ステージクラス
	Stage* stage;
public:
	//ステージデータ管理クラス
	Stagedata* stagedata;
	//ファイアを生成するクラス
	Firecontrol* firecontrol;
	//マップ管理クラス
	Mapcontrol* mapcontrol;
	//敵管理クラス
	Mobcontrol* mobcontrol;
	//主人公クラス
	Playercontrol* playercontrol;
	Playercontrol2p* playercontrol2p=NULL;
	//アイテム管理クラス
	Itemcontrol* itemcontrol;
	//当たり判定管理クラス
	Colisioncontrol* colisioncontrol;
	//生成
	static Gamescene* createWithPhysics(int,bool);
};