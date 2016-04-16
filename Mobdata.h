#pragma once
using namespace cocos2d;
enum Mobkind {
	mob1=0,
	mob2,
	mob3,
};
class Mobdata : public cocos2d::Layer
{
	virtual bool init(ValueMap&);
public:
	Mobkind mobkind;
	Vec2 mobxy;
	static Mobdata* create(ValueMap);
};