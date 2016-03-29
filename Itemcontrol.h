#pragma once
class Itemcontrol : public cocos2d::Layer
{
public:
	virtual bool init();
	//アイテム設置
	void setitem(cocos2d::Vec2);
	CREATE_FUNC(Itemcontrol);
};
