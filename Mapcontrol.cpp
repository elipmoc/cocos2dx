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
	////NULL�𖄂߂�///////////////
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
	////�S���ǂŖ��߂�///////////////
	for (int i = 0; i < MAPMAX_X; i++) {
		for (int ii = 0; ii < MAPMAX_Y; ii++) {
			msprite[i][ii]->setTexture("a.png");
			msprite[i][ii]->type = Blocktype::wall;
		}
	}
	mapload();
}

//�}�b�v���t�@�C������`��
void Mapcontrol::mapload() {
	static fstream f;
	static char filename[15];
	sprintf(filename, "stage%d.txt",scene->stagedata->getstagekind());
	f.open(filename, ios_base::in);

	static string buf;
	int countx=8,county=8;
	//////�}�b�v�𐶐�//////////////////////
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
	f.close();//����
}

//�w��}�X�̃u���b�N�𓾂�
Mapsprite* Mapcontrol::getblock(const Vec2 v) {
	Blockxy b=transblockxy(v);
	return msprite[b.x][b.y];
}

//�s�N�Z���P�ʂ̍��W����u���b�N�P�ʂ̍��W�ɂ���
Blockxy Mapcontrol::transblockxy(const Vec2 v) {
	//��ʂ̑傫���擾
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	Blockxy b;
	b.x = v.x / 16;
	b.y =(visibleSize.height-v.y )/ 16;
	return b;
}

//�w����W�̃u���b�N�̒��S�s�N�Z�����W��Ԃ�
Vec2 Mapcontrol::transblockcentralxy(const Vec2 _v) {
	Blockxy b=transblockxy(_v);
	//��ʂ̑傫���擾
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 v;
	v.x = b.x * 16 + 8;
	v.y = visibleSize.height - (b.y * 16 + 8);
	return v;
}

Vec2 Mapcontrol::transblockcentralxy(const int x,const int y) {
	//��ʂ̑傫���擾
	static Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 v;
	v.x = x * 16 + 8;
	v.y = visibleSize.height - (y * 16 + 8);
	return v;
}
//�󂳂ꂽ�u���b�N�̐����J�E���g�A�b�v
void Mapcontrol::plusbreakblock() {
	breakblock++;
}
//�󂳂ꂽ�u���b�N�̐���n��
int Mapcontrol::getbreakblock() {
	return breakblock;
}