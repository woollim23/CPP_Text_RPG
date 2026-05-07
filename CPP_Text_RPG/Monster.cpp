#include "Monster.h"

void Monster::attack(Characters* attacker, Characters* target)
{
	cout << endl << "====================================" << endl;
	cout << "<" << name_ << " 공격 차례!>" << endl;
	cout << endl << "====================================" << endl;
	cout << "몬스터 공격!!!!!" << endl;
	Characters::attack(attacker, target);
}