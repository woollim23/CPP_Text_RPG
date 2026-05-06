#include "Characters.h"
void Characters::attack(Characters* attacker, Characters* target)
{
	target->loseHp(attacker->power_);
}

void Characters::loseHp(int damage)
{
	int resultDamage = damage - defence_;
	if (resultDamage <= 0)
		resultDamage = 1;
	hp_ -= resultDamage;
}
