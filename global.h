#pragma once

#ifdef FIRST_LOADING

#define E
#else
#define E extern
#endif

//�O���[�o���ϐ�������
E void globalinit();
E cocos2d::Size visibleSize;