#pragma once
//�u���b�N�̐���
	enum class Blocktype {
		blank=0,
		destory='b',
		wall='a',
	};
	//�}�b�v�X�v���C�g�N���X
class Mapsprite : public cocos2d::Sprite
{
	friend Mapcontrol;
	//�܂�ł���{��
	Bom* bom =NULL;
	//�܂�ł���fire
	Firesprite* fire = NULL;
	Gamescene* scene;
	//�u���b�N�̐���
	Blocktype type=Blocktype::blank;
public:
	//����
	static Mapsprite* create(const std::string&, Gamescene*);
	static Mapsprite* create(Gamescene*);
	//�u���b�N�����Q�b�^�[
	Blocktype gettype();
	//�ʍs�s�\�u���b�N�Ȃ�true��Ԃ�
	bool obstaclecheck();
	//bom���܂܂���
	void havebom(Bom*);
	//�{�����O��
	void releasebom();
	//�{���ɂ��j��
	void bombreakblock();
	//�{�����k���Ȃ�^��Ԃ�
	bool bomnull();
	//�{�����Q�b�^�[
	Bom* getbom();
	//fire���܂܂���
	void havefire(Firesprite*);
	//fire���O��
	void releasefire();
	//fire���k���Ȃ�^��Ԃ�
	bool firenull();
};
