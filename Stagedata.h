#pragma once
#include "Mobdata.h"
using namespace cocos2d;
//�e�X�e�[�W�̏����擾�A�Ǘ�����N���X
class Stagedata :public Layer {
	Vector<Mobdata*> moblist;
	//�X�e�[�W���
	int stagenom;
	//��l�������ʒu
	Vec2 playerposition;
	//�|�[�^���o���ʒu
	Vec2 portalposition;
	void load(const std::string&);
	//������
	bool init(const int);
public:
	//����
	static Stagedata* create(const int);
	void recreate(const int);
	//��l�������ʒu�Q�b�^�[
	Vec2 getplayerposition();
	//�X�e�[�W��ރQ�b�^�[
	int getstagekind();
	//�|�[�^���o���ʒu�Q�b�^�[
	Vec2 getportalposition();
	Vector<Mobdata*> getmoblist();
};