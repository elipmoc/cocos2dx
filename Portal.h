#pragma once
class Portal :public Colision {
	Stage* stage;
	virtual bool init(Stage*);
public:
	virtual void callback(Colision*);
	static Portal* create(Stage*);
};