#include "test1.h"
USING_NS_CC;
bool Test1::init() { 
	if (!Layer::init())
	{
		return false;
	}
	//���x���i������̏o�͎菇�j
	//label�쐬�@�@�@�@�@�@�@�@�@�@�@�\��������A�t�H���g�p�X�A�����傫��
	auto label = Label::createWithTTF("test1", "fonts/Marker Felt.ttf", 24);
	//�ʒu�ݒ�
	label->setPosition(Vec2(240, 100));
	//Test1�ɑg�ݍ��� ���x���A[���s��]
	this->addChild(label,0);
	
	return true; }