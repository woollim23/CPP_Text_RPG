#pragma once
#include "pch.h"

class Characters
{
protected:
	string name_;
	int hp_;
	int power_;
	int defence_;

	Characters() {}

	Characters(string name, int hp, int power, int defence)
		: name_(name), hp_(hp), power_(power), defence_(defence)
	{

	}

public:
	virtual void attack(Characters *attacker, Characters *target);
	virtual void loseHp(int damage);
	int getHP() { return hp_; }
	int setHP(int insetHp) { hp_ = insetHp; }
	int getPower() { return power_; }
	int getDefence() { return defence_; }
};

