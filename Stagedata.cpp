#pragma execution_character_set("utf-8")
#include "Stagedata.h"

Stagedata* Stagedata::create(const int _stagenom) {
	Stagedata* ref = new (std::nothrow) Stagedata();
	if (ref &&ref->init(_stagenom))
	{
		ref->autorelease();
		return ref;
	}
	CC_SAFE_DELETE(ref);
	return nullptr;
}

void Stagedata::recreate(const int _stagenom) {
	stagenom = _stagenom;
	moblist.clear();
	char str[15];
	sprintf(str, "stage%d.plist", _stagenom);
	load(str);
}

//������(�X�e�[�W�f�[�^��ǂݍ���)---------------------------
bool Stagedata::init(const int _stagenom){
	if (!Layer::init())return false;
	stagenom = _stagenom;
	char str[15];
	sprintf(str, "stage%d.plist", _stagenom);
	load(str);
	/*auto file = "hello.plist";
	ValueMap data2;
	ValueVector a;
	ValueMap data3[2];
	data3[0]["mobkind"] = 0;
	data3[0]["mobx"] = 20;
	data3[0]["moby"] = 222;
	data3[1]["mobkind"] = -9;
	data3[1]["mobx"] = 3.14;
	data3[1]["moby"] = 4545;
	a.push_back(Value(data3[0]));
	a.push_back(Value(data3[1]));
	data2["mob"] = a;
	data2["greeting"] = "Hello World";
	if (FileUtils::getInstance()->writeToFile(data2, file))*/
	return true;
}
void Stagedata::load(const std::string& filename) {
	// ValueMap�Ƃ��ăX�e�[�W�f�[�^��ǂݍ���------------------
	ValueMap data =
		FileUtils::getInstance()->getValueMapFromFile(filename);
	//��l���̏������W�擾-----------------------------
	playerposition.x = data["playerpositionx"].asInt();
	playerposition.y = data["playerpositiony"].asInt();
	//portal�o���ʒu���擾------------------------------
	portalposition.x = data["portalpositionx"].asInt();
	portalposition.y = data["portalpositiony"].asInt();
	//�G�f�[�^�ǂݍ���----------------------------------
	if (!data["mob"].isNull()) {
		ValueVector a = data["mob"].asValueVector();
		for (int i = 0; i < a.size(); i++) {
			moblist.pushBack(Mobdata::create(a[i].asValueMap()));
		}
	}
}

Vec2 Stagedata::getplayerposition() {
	return playerposition;
}

Vec2 Stagedata::getportalposition() {
	return portalposition;
}

int Stagedata::getstagekind() {
	return stagenom;
}


Vector<Mobdata*> Stagedata::getmoblist() {
	return moblist;
}
