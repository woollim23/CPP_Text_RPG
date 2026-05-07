#include "Characters.h"
void Characters::attack(Characters* attacker, Characters* target)
{
	Battle::battleSystem(attacker, target);
}

void Characters::loseHp(int damage)
{
	hp_ -= damage;
}
