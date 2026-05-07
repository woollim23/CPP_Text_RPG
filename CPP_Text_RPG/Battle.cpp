#include "Battle.h"
#include "Characters.h"

void Battle::battleSystem(Characters *attacker, Characters *target)
{
	int damage = attacker->getPower() - target->getDefence();

	if (damage <= 0)
		damage = 1;

	target->loseHp(damage);
}