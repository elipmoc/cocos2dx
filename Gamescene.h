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
    //�X�e�[�W�N���X
	Stage* stage;
public:
	//�X�e�[�W�f�[�^�Ǘ��N���X
	Stagedata* stagedata;
	//�t�@�C�A�𐶐�����N���X
	Firecontrol* firecontrol;
	//�}�b�v�Ǘ��N���X
	Mapcontrol* mapcontrol;
	//�G�Ǘ��N���X
	Mobcontrol* mobcontrol;
	//��l���N���X
	Playercontrol* playercontrol;
	Playercontrol2p* playercontrol2p=NULL;
	//�A�C�e���Ǘ��N���X
	Itemcontrol* itemcontrol;
	//�����蔻��Ǘ��N���X
	Colisioncontrol* colisioncontrol;
	//����
	static Gamescene* createWithPhysics(int,bool);
};