#include "Battle.h"

void Battle::battleSystem(Characters *attacker, Characters *target)
{
	int damage = attacker->getPower() - attacker->getDefence();

	if (damage <= 0)
		damage = 1;

	target->loseHp(damage);
}