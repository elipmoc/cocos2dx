#pragma once
//ブロックの性質
	enum class Blocktype {
		blank=0,
		destory='b',
		wall='a',
	};
	//マップスプライトクラス
class Mapsprite : public cocos2d::Sprite
{
	friend Mapcontrol;
	//含んでいるボム
	Bom* bom =NULL;
	//含んでいるfire
	Firesprite* fire = NULL;
	Gamescene* scene;
	//ブロックの性質
	Blocktype type=Blocktype::blank;
public:
	//生成
	static Mapsprite* create(const std::string&, Gamescene*);
	static Mapsprite* create(Gamescene*);
	//ブロック性質ゲッター
	Blocktype gettype();
	//通行不可能ブロックならtrueを返す
	bool obstaclecheck();
	//bomを含ませる
	void havebom(Bom*);
	//ボムを外す
	void releasebom();
	//ボムによる破壊
	void bombreakblock();
	//ボムがヌルなら真を返す
	bool bomnull();
	//ボムをゲッター
	Bom* getbom();
	//fireを含ませる
	void havefire(Firesprite*);
	//fireを外す
	void releasefire();
	//fireがヌルなら真を返す
	bool firenull();
};
