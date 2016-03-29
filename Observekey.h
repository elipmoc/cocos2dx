#pragma once
#include "cocos2d.h"
#define KEYMAX 11
class Observekey : public cocos2d::Layer
{
public:
	int keycount[KEYMAX];
	enum class Key {
		up1=0,
		up2,
		down1,
		down2,
		right1,
		right2,
		left1,
		left2,
		bomset1,
		bomset2,
		enter,
	};
	int getkey(const Key);
	virtual bool init();
	virtual void update(float);
	CREATE_FUNC(Observekey);

};