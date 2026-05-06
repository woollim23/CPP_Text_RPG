#pragma once
#include "pch.h"
#include "Characters.h"


class Player : public Characters
{
protected:
	string job_;
	int level_;

public:
	Player() {}
	Player(string name, string job, int hp, int mp, int power, int defence)
		: Characters(name, hp, mp, power, defence), job_(job), level_(1)
	{}
	virtual ~Player() {}

	virtual void attack(Characters* attacker, Characters* target) override;
	string getJob() const { return job_; }
};