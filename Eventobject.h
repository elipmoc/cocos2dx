#pragma once
#define CREATE_EVENT(__TYPE__) \
static __TYPE__* create(Gamescene* _m) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet && pRet->_init(_m)&& pRet->init()) \
    { \
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

class Eventobject :public Colision{
protected:
	virtual bool init() = 0;
	bool _init(Gamescene*);
	Gamescene* scene;
public:
};