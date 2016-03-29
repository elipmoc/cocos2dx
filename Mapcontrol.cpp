#include "Gamescene.h"
#include <fstream>


Mapcontrol* Mapcontrol::create(Gamescene* _scene)
{
	Mapcontrol *ref = new (std::nothrow) Mapcontrol();
	if (ref && ref->init(_scene))
	{
		
		ref->mapload();
		ref->autorelease();
		return ref;
	}
	CC_SAFE_DELETE(ref);
	return nullptr;
}

bool Mapcontrol::init(Gamescene* _scene) {
	if (!Layer::init())return false;
	scene = _scene;
	////NULLを埋める///////////////
	for (int i = 0; i < MAPMAX_X; i++) {
		for (int ii = 0; ii < MAPMAX_Y; ii++) {
				msprite[i][ii] = Mapsprite::create("a.png", scene);
				msprite[i][ii]->type = Blocktype::wall;
				msprite[i][ii]->setPosition(i * 16 + 8, visibleSize.height - (ii * 16 + 8));
				msprite[i][ii]->setScale(2.2f);
				this->addChild(msprite[i][ii],1);
		}
	}
	return true;
}



void Mapcontrol::recreate() {
	////全部壁で埋める///////////////
	for (int i = 0; i < MAPMAX_X; i++) {
		for (int ii = 0; ii < MAPMAX_Y; ii++) {
			msprite[i][ii]->setTexture("a.png");
			msprite[i][ii]->type = Blocktype::wall;
		}
	}
	mapload();
}

//マップをファイルから形成
void Mapcontrol::mapload() {
	static fstream f;
	static char filename[15];
	sprintf(filename, "stage%d.txt",scene->stagedata->getstagekind());
	f.open(filename, ios_base::in);

	static string buf;
	int countx=8,county=8;
	//////マップを生成//////////////////////
	while (f&&getline(f,buf))
	{
		for (int i=0; i < buf.size(); i++) {
			if (buf[i] == ' ') {
				msprite[i][(county-8)/16]->setTexture("");
				msprite[i][(county - 8) / 16]->type = Blocktype::blank;
			}else {
				sprintf(filename, "%c.png",buf[i]);
				msprite[i][(county-8)/16]->setTexture(filename);
				msprite[i][(county-8)/16]->type = (Blocktype)buf[i];
			}
			msprite[i][(county-8)/16]->setPosition(countx, visibleSize.height - county);
			countx += 16;
		}
		county += 16;
		countx = 8;
	}
	f.close();//閉じる
}

//指定マスのブロックを得る
Mapsprite* Mapcontrol::getblock(const Vec2 v) {
	Blockxy b=transblockxy(v);
	return msprite[b.x][b.y];
}

//ピクセル単位の座標からブロック単位の座標にする
Blockxy Mapcontrol::transblockxy(const Vec2 v) {
	//画面の大きさ取得
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	Blockxy b;
	b.x = v.x / 16;
	b.y =(visibleSize.height-v.y )/ 16;
	return b;
}

//指定座標のブロックの中心ピクセル座標を返す
Vec2 Mapcontrol::transblockcentralxy(const Vec2 _v) {
	Blockxy b=transblockxy(_v);
	//画面の大きさ取得
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 v;
	v.x = b.x * 16 + 8;
	v.y = visibleSize.height - (b.y * 16 + 8);
	return v;
}

Vec2 Mapcontrol::transblockcentralxy(const int x,const int y) {
	//画面の大きさ取得
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 v;
	v.x = x * 16 + 8;
	v.y = visibleSize.height - (y * 16 + 8);
	return v;
}
//壊されたブロックの数をカウントアップ
void Mapcontrol::plusbreakblock() {
	breakblock++;
}
//壊されたブロックの数を渡す
int Mapcontrol::getbreakblock() {
	return breakblock;
}