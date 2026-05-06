#pragma once
#include "pch.h"
#include "Player.h"

class Monster : public Characters
{
	string dropItemName_;
	int dropItemPrice_;

	Monster()
		:Characters("°íºí¸°", 30, 20, 10), dropItemName_("°ñµå"), dropItemPrice_(500)
	{}

public:
	void attack(Characters* attacker, Characters* target);
};