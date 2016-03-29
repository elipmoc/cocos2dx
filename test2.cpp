#include "test2.h"
USING_NS_CC;

bool Test2::init() {
	if (!Layer::init())
	{
		return false;
	}
	//画面の大きさ取得
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//スプライト（画像の出力手順）
	//スプライト作成　　　　　　　画像パス
	sprite = Sprite::create("player.png");
	//位置設定
	sprite->setPosition(Vec2(visibleSize.width/2, 0));
	//大きさ設定
	sprite->setScale(5);
	//10秒かけて上に500ドット移動する
	sprite->runAction(MoveBy::create(10,Vec2(0,500)));
	//Test2に組み込み ラベル、[奥行き]
	this->addChild(sprite, 0);

	return true;
}

/*
●アンカーポイントの設定
《Sprite》->setAnchorPoint(《Vec2》);
中心地点を設定する。値は、０～１の実数で指定します。

●位置の設定
《Sprite》->setPosition( 横 , 縦 );
《Sprite》->setPosition(《Vec2》);

●大きさの設定
《Sprite》->setScale( float値 );
《Sprite》->setScaleX( float値 );
《Sprite》->setScaleY( float値 );
例えば縦横２倍の大きさにしたければ、setScale(2.0)というようにします。

●回転角度の設定
《Sprite》->setRotation( float値 );
例えば、setRotation(90.0)なら、イメージを右回りに90度回転します。

●アクション----

●MoveTo
auto 変数 = MoveTo::create( 時間 , 《Vec2》);
MoveToは、引数にVec2で指定した地点まで、一定時間をかけて移動します。
例えば、create(10, Vec2(0, 0))とすれば、ゼロ地点まで10秒かけて移動するアニメーションが作れます。

●MoveBy
auto 変数 = MoveBy::Create( 時間 , 《Vec2》);
こちらは、現在地点から指定した距離だけ離れた場所に移動するためのものです。

●アクションの実行
《Sprite》->runAction(《Action》);

■その他のアニメーション

●ScaleTo
ScaleTo::create( 秒数 , 倍率 );
イメージを拡大縮小するアニメーションです。引数には秒数と倍率を指定します。

●ScaleBy
ScaleBy::Create( 秒数 , 倍率 );
こちらは、現在の何倍に拡大するか？という形で拡大縮小します。

●RotateTo
RotateTo::Create( 秒数 , 角度 );
こちらは回転です。これは右回りに指定の角度だけ回転させます。

●RotateBy
RotateBy::Create( 秒数 , 角度 );
これも、現在の向きから指定した角度だけ回転をさせます。



*/