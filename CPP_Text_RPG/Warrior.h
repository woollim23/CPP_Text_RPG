#pragma once
#include "Player.h"

class Warrior : public Player
{
public:
	Warrior(string name, int hp, int mp, int power, int defence)
		:Player(name, hp, mp, power, defence)
	{
		this->hp += 30;
	}

	void attack() override;
	~Warrior() override;
};