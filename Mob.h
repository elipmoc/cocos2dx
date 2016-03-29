#pragma once
#define CREATE_MOB(__TYPE__) \
static __TYPE__* create(Gamescene* _m) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->init()) \
    { \
		pRet->scene = _m; \
		pRet->bomcon = Bomcontrol::create(_m); \
        pRet->autorelease(); \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = nullptr; \
        return nullptr; \
    } \
}

class Mob:public Colision{

protected:
	virtual bool init()=0;
	Gamescene* scene;
	Bomcontrol* bomcon;
public:
};