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

public:
	Player()
		:name("없음"), hp(0), mp(0), power(0), defence(0)
	{
		job = "없음";
		level = 1;
	}
	Player(string name, string job, int hp, int mp, int power, int defence)
		:name(name), job(job), hp(hp), mp(mp), power(power), defence(defence)
	{
		level = 1;
	}
	virtual ~Player() {}

	virtual void attack() = 0;
	void printStatus();
	void setStat(int& HP, int& MP, bool& isGameStart);
	string getJob() { return job; }
};