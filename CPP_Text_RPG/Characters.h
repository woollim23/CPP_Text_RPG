#pragma once
#include "pch.h"
#include "Battle.h"

class Characters
{
protected:
	string name_;
	int hp_;
	int mp_;
	int power_;
	int defence_;

public:

	Characters() {}

	Characters(string name, int hp, int mp, int power, int defence)
		: name_(name), hp_(hp), mp_(mp), power_(power), defence_(defence)
	{

	}
	virtual void attack(Characters *attacker, Characters *target);

	void loseHp(int damage);
	int getHP() { return hp_; }
	void setHP(int insetHp) { hp_ = insetHp; }
	int getPower() { return power_; }
	int getDefence() { return defence_; }
};

