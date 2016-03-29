#pragma once
enum class Itemkind {
	bommaxup,
	speedup,
	bompenetrate
};
class Item : public Colision {
	virtual bool init(Itemcontrol*,Itemkind);
	Itemcontrol* itemcon;
	Itemkind itemkind;
public:
	Itemkind getitemkind() { return itemkind; };
	static Item* create(const Itemkind,Itemcontrol*);
	virtual void callback(Colision*);

};