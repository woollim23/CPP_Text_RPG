#pragma once
#include "pch.h"


class Player
{
protected:
	string name;
	string job;
	int level;
	int hp;
	int mp;
	int power;
	int defence;

	Player()
	{

	}

	Player(string name, int hp, int mp, int power, int defence)
		:name(name),hp(hp),mp(mp),power(power),defence(defence)
	{
		job = "¾øÀ½";
		level = 1;
	}
	virtual void attack() = 0;

public:

	void printStatus();

	void setStat(int& HP, int& MP, bool& isGameStart);

	virtual ~Player() {}
};