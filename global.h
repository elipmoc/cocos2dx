#pragma once

#ifdef FIRST_LOADING

#define E
#else
#define E extern
#endif

//グローバル変数初期化
E void globalinit();
E cocos2d::Size visibleSize;