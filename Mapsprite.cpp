#pragma execution_character_set("utf-8")
#include "Gamescene.h"


Mapsprite* Mapsprite::create(const std::string& filename,Gamescene* _scene)
{
	Mapsprite *sprite = new (std::nothrow) Mapsprite();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->scene = _scene;
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

Mapsprite* Mapsprite::create( Gamescene* _scene)
{
	Mapsprite *sprite = new (std::nothrow) Mapsprite();
	if (sprite && ((Sprite*)sprite)->init())
	{
		sprite->scene = _scene;
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

//ブロック性質ゲッター
Blocktype Mapsprite::gettype(){
	return type;
}

//通行不可能ブロックならtrueを返す
bool Mapsprite::obstaclecheck() {
	if(this->type == Blocktype::destory
		|| this->type == Blocktype::wall
		|| this->bom != NULL)return true;
	return false;
}

//bomを含ませる
void Mapsprite::havebom(Bom* _bom) {
	this->bom = _bom;
}

//bomを外す
void Mapsprite::releasebom() {
	this->bom =NULL;
}
//ボムによる破壊
void Mapsprite::bombreakblock() {
	if (type != Blocktype::wall) {
		scene->firecontrol->setfire(this->getPosition());
		if (type == Blocktype::blank) { if (bom != NULL)bom->afterexplosion(); }
		else {
			if(random()%3==0)scene->itemcontrol->setitem(this->getPosition());
			type = Blocktype::blank;
			this->setTexture("");
			scene->mapcontrol->plusbreakblock();
		}
	}
}

//bomを含んでいなかったらtrue
bool Mapsprite::bomnull() {
	if (bom == NULL)return true;
	return false;
}
//ボムゲッター
Bom* Mapsprite::getbom() {
	return bom;
}

//fireを含ませる
void Mapsprite::havefire(Firesprite* _fire) {
	this->fire = _fire;
}

//fireを外す
void Mapsprite::releasefire() {
	this->fire = NULL;
}

//fireを含んでいなかったらtrue
bool Mapsprite::firenull() {
	if (fire == NULL)return true;
	return false;
}