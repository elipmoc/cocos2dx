#pragma once
using namespace std;
//縦と横のブロック数
#define MAPMAX_X 20
#define MAPMAX_Y 20

//ブロック単位の座標用
typedef struct {int x; int y;}Blockxy;

//マップスプライトを管理するクラス
class Mapcontrol : public cocos2d::Layer
{
	Mapsprite* msprite[MAPMAX_X][MAPMAX_Y];
	int breakblock = 0;//壊されたブロックの数
	Gamescene* scene;
	//マップを生成
	void mapload();
	virtual bool init(Gamescene*);
public:	

	//壊されたブロックの数をカウントアップ
	void plusbreakblock();
	//壊されたブロックの数を渡す
	int getbreakblock();
	//指定マスのブロック情報を得る
	Mapsprite* getblock(const cocos2d::Vec2);
	//ピクセル座標をブロック座標に変換
	Blockxy transblockxy(const cocos2d::Vec2);
	//ピクセル座標からブロックの中心の座標を得る
	cocos2d::Vec2 Mapcontrol::transblockcentralxy(const cocos2d::Vec2);
	//ブロック座標からブロックの中心の座標を得る
	cocos2d::Vec2 Mapcontrol::transblockcentralxy(const int,const int);
	static Mapcontrol* create(Gamescene*);
	void recreate();
};
