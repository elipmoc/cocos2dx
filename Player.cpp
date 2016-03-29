#pragma execution_character_set("utf-8")
#include "Gamescene.h"
#include "Gameoverscene.h"

//ボム設置
void Player::bomset() {
	//ボムを設置する座標を得る
	const Vec2 central = scene->mapcontrol->transblockcentralxy(getPosition());
	//ボム設置
	bomcon->setbom(central);
}

//ゲームオーバーにする
void Player::gameover() {
	if (desflag == false) {
		desflag = true;
		AudioEngine::stopAll();
		Scene* pScene = TransitionFade::create(1, Gameoverscene::create());
		if (pScene) {
			Director::getInstance()->replaceScene(pScene);
		}
	}
}

//初期化
bool Player::init(Gamescene* _scene) {
	if (!Sprite::init())return false;
	scene = _scene;
	//スプライト作成
	this->setTexture("シロボン後.png");
	setAnchorPoint(Vec2(0.5f, 0.3f));
	setScale(2);
	//剛体設定
	pbody = PhysicsBody::createBox(Rect(0.0f, 0.0f, 4.0f, 5.0f).size);
	//スプライト中心から（0,-5）ずらす
	pbody->setPositionOffset(Vec2(0.0f, -5.0f));
	pbody->setDynamic(false);
	setpbody(Colisionkind::player, Colisionkind::mob + Colisionkind::portal+Colisionkind::item);
	setfirstposition();
	//キー監視クラスを初期化
	obsevekey = Observekey::create();
	this->addChild(obsevekey);
	//ボム操作クラスを初期化
	bomcon = Bomcontrol::create(scene);
	scene->addChild(bomcon, 2);
	Animation* animation;
	char filename[20];
	for (int i = 0; i < PLAYERACTIONMAX; i++) {
		animation = Animation::create();
		sprintf(filename, "シロボン_0%d.png", i * 2 + 1);
		animation->addSpriteFrameWithFile(filename);
		sprintf(filename, "シロボン_0%d.png", i * 2 + 2);
		animation->addSpriteFrameWithFile(filename);
		animation->setDelayPerUnit(0.2f);
		animation->setRestoreOriginalFrame(true);
		action[i] = RepeatForever::create(Animate::create(animation));
		action[i]->retain();
		action[i]->setTag(2);
	}
	//update関数を呼び出せるようにする
	this->scheduleUpdate();
	return true;
}

//初期位置設定
void Player::setfirstposition() {
	stopAllActions();
	Vec2 position = scene->stagedata->getplayerposition();
	setPosition(scene->mapcontrol->transblockcentralxy(position.x, position.y));
}


//当たり判定コールバック
void Player::callback(Colision* c) {
	if (c->getPhysicsBody()->getTag() == Colisionkind::mob)gameover();
}

//ダブルディスパッチ
void Player::callback(Item* item) {
	if (item->getitemkind() == Itemkind::speedup) {
		speed -= 0.01f;
	}else
		if (item->getitemkind() == Itemkind::bommaxup) {
			maximumbom++;
		}
}


void Player::update(float dt) {
	//////////爆風に当たってたらゲームオーバーにする///////////
	if (scene->mapcontrol->getblock(getPosition())->firenull() == false) {
		gameover();
	}
	///////enterキーでボム設置///////////////
	if (obsevekey->getkey((Observekey::Key)playerkey.bomset) == 2
		&& bomcon->getChildrenCount()<maximumbom) {
		bomset();
	}
	//////主人公移動////////////////////////
	//主人公がmoveアニメーションしていないとき
	if (getActionByTag(1) == nullptr) {
		static int x = 0, y = 0;
		if (obsevekey->getkey((Observekey::Key)playerkey.right) != 0) {

			if (x == 16 && y == 0) {}
			else {
				setTexture("シロボン右.png");
				stopActionByTag(2);
				runAction(action[RIGHT]);
				x = 16; y = 0;
			}
		}
		else if (obsevekey->getkey((Observekey::Key)playerkey.left) != 0) {
			if (x == -16 && y == 0) {}
			else {
				setTexture("シロボン左.png");
				stopActionByTag(2);
				runAction(action[LEFT]);
				x = -16; y = 0;
			}
		}
		else if (obsevekey->getkey((Observekey::Key)playerkey.up) != 0) {
			if (x == 0 && y == 16) {}
			else {
				setTexture("シロボン前.png");
				stopActionByTag(2);
				runAction(action[FRONT]);
				x = 0; y = 16;
			}
		}
		else if (obsevekey->getkey((Observekey::Key)playerkey.down) != 0) {
			if (x == 0 && y == -16) {}
			else {
				setTexture("シロボン後.png");
				stopActionByTag(2);
				runAction(action[BACK]);
				x = 0; y = -16;
			}
		}
		else { stopActionByTag(2); x = 0; y = 0; return; }
		//移動先に障害物がないとき
		//if (scene->mapcontrol->getblock(Vec2(getPositionX() + x,getPositionY() + y))->obstaclecheck() == false) {
			//1ブロック分移動
			auto move = MoveBy::create(speed, Vec2(x, y));
			move->setTag(1);
			runAction(move);
		//}

	}
}