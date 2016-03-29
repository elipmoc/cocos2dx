#include "test1.h"
USING_NS_CC;
bool Test1::init() { 
	if (!Layer::init())
	{
		return false;
	}
	//ラベル（文字列の出力手順）
	//label作成　　　　　　　　　　　表示文字列、フォントパス、文字大きさ
	auto label = Label::createWithTTF("test1", "fonts/Marker Felt.ttf", 24);
	//位置設定
	label->setPosition(Vec2(240, 100));
	//Test1に組み込み ラベル、[奥行き]
	this->addChild(label,0);
	
	return true; }