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

//�u���b�N�����Q�b�^�[
Blocktype Mapsprite::gettype(){
	return type;
}

//�ʍs�s�\�u���b�N�Ȃ�true��Ԃ�
bool Mapsprite::obstaclecheck() {
	if(this->type == Blocktype::destory
		|| this->type == Blocktype::wall
		|| this->bom != NULL)return true;
	return false;
}

//bom���܂܂���
void Mapsprite::havebom(Bom* _bom) {
	this->bom = _bom;
}

//bom���O��
void Mapsprite::releasebom() {
	this->bom =NULL;
}
//�{���ɂ��j��
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

//bom���܂�ł��Ȃ�������true
bool Mapsprite::bomnull() {
	if (bom == NULL)return true;
	return false;
}
//�{���Q�b�^�[
Bom* Mapsprite::getbom() {
	return bom;
}

//fire���܂܂���
void Mapsprite::havefire(Firesprite* _fire) {
	this->fire = _fire;
}

//fire���O��
void Mapsprite::releasefire() {
	this->fire = NULL;
}

//fire���܂�ł��Ȃ�������true
bool Mapsprite::firenull() {
	if (fire == NULL)return true;
	return false;
}