#pragma once


//���z�N���X�ł�
class Stage :public Layer {
	//void scenechange(float);//�V�[���؂�ւ�
private:
	const int portaltag = 0;
	const int labeltag=1;
	Gamescene* scene;
	Vec2 portalv;//�|�[�^����ݒu������W
	void setportal();//�|�[�^���o��
	bool init(Gamescene*);
	bool portalflag=false;
	void nextstage(float);
	void update(float);
public:
	static Stage* create(Gamescene*);
	void clear();//�X�e�[�W�N���A������
};