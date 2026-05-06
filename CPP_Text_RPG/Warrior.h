#pragma once
#include "Player.h"

class Warrior : public Player
{
public:

	Warrior()
	{

	}

	Warrior(string name, int hp, int mp, int power, int defence)
		:Player(name, "ภüป็", hp, mp, power, defence)
	{
		this->hp_ += 30;
	}

	~Warrior() override;

	void attack(Characters* attacker, Characters* target) override;
};