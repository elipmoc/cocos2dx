#pragma once
#include "Mobdata.h"
using namespace cocos2d;
//各ステージの情報を取得、管理するクラス
class Stagedata :public Layer {
	Vector<Mobdata*> moblist;
	//ステージ種類
	int stagenom;
	//主人公初期位置
	Vec2 playerposition;
	//ポータル出現位置
	Vec2 portalposition;
	void load(const std::string&);
	//初期化
	bool init(const int);
public:
	//生成
	static Stagedata* create(const int);
	void recreate(const int);
	//主人公初期位置ゲッター
	Vec2 getplayerposition();
	//ステージ種類ゲッター
	int getstagekind();
	//ポータル出現位置ゲッター
	Vec2 getportalposition();
	Vector<Mobdata*> getmoblist();
};