#define FIRST_LOADING
#include "global.h"
USING_NS_CC;

void globalinit() {
	//画面の大きさ取得
	visibleSize = Director::getInstance()->getVisibleSize();
}