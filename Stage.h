#pragma once


//仮想クラスです
class Stage :public Layer {
	//void scenechange(float);//シーン切り替え
private:
	const int portaltag = 0;
	const int labeltag=1;
	Gamescene* scene;
	Vec2 portalv;//ポータルを設置する座標
	void setportal();//ポータル出現
	bool init(Gamescene*);
	bool portalflag=false;
	void nextstage(float);
	void update(float);
public:
	static Stage* create(Gamescene*);
	void clear();//ステージクリアをする
};