#include "test2.h"
USING_NS_CC;

bool Test2::init() {
	if (!Layer::init())
	{
		return false;
	}
	//��ʂ̑傫���擾
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//�X�v���C�g�i�摜�̏o�͎菇�j
	//�X�v���C�g�쐬�@�@�@�@�@�@�@�摜�p�X
	sprite = Sprite::create("player.png");
	//�ʒu�ݒ�
	sprite->setPosition(Vec2(visibleSize.width/2, 0));
	//�傫���ݒ�
	sprite->setScale(5);
	//10�b�����ď��500�h�b�g�ړ�����
	sprite->runAction(MoveBy::create(10,Vec2(0,500)));
	//Test2�ɑg�ݍ��� ���x���A[���s��]
	this->addChild(sprite, 0);

	return true;
}

/*
���A���J�[�|�C���g�̐ݒ�
�sSprite�t->setAnchorPoint(�sVec2�t);
���S�n�_��ݒ肷��B�l�́A�O�`�P�̎����Ŏw�肵�܂��B

���ʒu�̐ݒ�
�sSprite�t->setPosition( �� , �c );
�sSprite�t->setPosition(�sVec2�t);

���傫���̐ݒ�
�sSprite�t->setScale( float�l );
�sSprite�t->setScaleX( float�l );
�sSprite�t->setScaleY( float�l );
�Ⴆ�Ώc���Q�{�̑傫���ɂ�������΁AsetScale(2.0)�Ƃ����悤�ɂ��܂��B

����]�p�x�̐ݒ�
�sSprite�t->setRotation( float�l );
�Ⴆ�΁AsetRotation(90.0)�Ȃ�A�C���[�W���E����90�x��]���܂��B

���A�N�V����----

��MoveTo
auto �ϐ� = MoveTo::create( ���� , �sVec2�t);
MoveTo�́A������Vec2�Ŏw�肵���n�_�܂ŁA��莞�Ԃ������Ĉړ����܂��B
�Ⴆ�΁Acreate(10, Vec2(0, 0))�Ƃ���΁A�[���n�_�܂�10�b�����Ĉړ�����A�j���[�V���������܂��B

��MoveBy
auto �ϐ� = MoveBy::Create( ���� , �sVec2�t);
������́A���ݒn�_����w�肵�������������ꂽ�ꏊ�Ɉړ����邽�߂̂��̂ł��B

���A�N�V�����̎��s
�sSprite�t->runAction(�sAction�t);

�����̑��̃A�j���[�V����

��ScaleTo
ScaleTo::create( �b�� , �{�� );
�C���[�W���g��k������A�j���[�V�����ł��B�����ɂ͕b���Ɣ{�����w�肵�܂��B

��ScaleBy
ScaleBy::Create( �b�� , �{�� );
������́A���݂̉��{�Ɋg�傷�邩�H�Ƃ����`�Ŋg��k�����܂��B

��RotateTo
RotateTo::Create( �b�� , �p�x );
������͉�]�ł��B����͉E���Ɏw��̊p�x������]�����܂��B

��RotateBy
RotateBy::Create( �b�� , �p�x );
������A���݂̌�������w�肵���p�x������]�������܂��B



*/