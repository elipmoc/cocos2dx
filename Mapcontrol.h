#pragma once
using namespace std;
//�c�Ɖ��̃u���b�N��
#define MAPMAX_X 20
#define MAPMAX_Y 20

//�u���b�N�P�ʂ̍��W�p
typedef struct {int x; int y;}Blockxy;

//�}�b�v�X�v���C�g���Ǘ�����N���X
class Mapcontrol : public cocos2d::Layer
{
	Mapsprite* msprite[MAPMAX_X][MAPMAX_Y];
	int breakblock = 0;//�󂳂ꂽ�u���b�N�̐�
	Gamescene* scene;
	//�}�b�v�𐶐�
	void mapload();
	virtual bool init(Gamescene*);
public:	

	//�󂳂ꂽ�u���b�N�̐����J�E���g�A�b�v
	void plusbreakblock();
	//�󂳂ꂽ�u���b�N�̐���n��
	int getbreakblock();
	//�w��}�X�̃u���b�N���𓾂�
	Mapsprite* getblock(const cocos2d::Vec2);
	//�s�N�Z�����W���u���b�N���W�ɕϊ�
	Blockxy transblockxy(const cocos2d::Vec2);
	//�s�N�Z�����W����u���b�N�̒��S�̍��W�𓾂�
	cocos2d::Vec2 Mapcontrol::transblockcentralxy(const cocos2d::Vec2);
	//�u���b�N���W����u���b�N�̒��S�̍��W�𓾂�
	cocos2d::Vec2 Mapcontrol::transblockcentralxy(const int,const int);
	static Mapcontrol* create(Gamescene*);
	void recreate();
};
