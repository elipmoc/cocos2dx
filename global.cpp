#define FIRST_LOADING
#include "cocos2d.h"
#include "global.h"
USING_NS_CC;

void globalinit() {
	//��ʂ̑傫���擾
	visibleSize = Director::getInstance()->getVisibleSize();
}