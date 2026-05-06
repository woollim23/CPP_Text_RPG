#pragma once
#include "pch.h"
#include "Characters.h"


class Player : public Characters
{
protected:
	string name_;
	int hp_;
	int power_;
	int defence_;

	string job_;
	int level_;
	int mp_;

public:
	Player() {}
	Player(string name, string job, int hp, int mp, int power, int defence)
		: Characters(name, hp, power, defence), job_(job), level_(1), mp_(mp)
	{}
	virtual ~Player() {}

	virtual void attack(Characters* attacker, Characters* target) override;
	void printStatus();
	void setStat(int& HP, int& MP, bool& isGameStart);
	string getJob() const { return job_; }
};