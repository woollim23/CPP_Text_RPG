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

void Characters::printStatus()
{
	cout << endl << "====================================" << endl;
	cout << "  " << name_ << " 의 현재 능력치" << endl;
	cout << "====================================" << endl;
	cout << "HP: " << hp_ << "   MP: " << mp_ << endl;
	cout << "공격력: " << power_ << "   방어력: " << defence_ << endl;
	cout << "====================================" << endl;
}


void Characters::setStat(int& HP, int& MP, bool& isGameStart)
{
	{

		while (!isGameStart)
		{
			cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다." << endl;
			cout << "============================================" << endl;
			cout << "< 캐릭터 강화 >" << endl;
			cout << "============================================" << endl;
			cout << "1. HP UP    2. MP UP    3. 공격력 2배" << endl;
			cout << "4. 방어력 2배  5. 현재 능력치  0. 게임 시작" << endl;
			int num;
			cout << "번호를 선택해주세요: ";
			cin >> num;

			switch (num)
			{
			case 0:
			{
				cout << "게임을 시작합니다!" << endl;
				isGameStart = true;
				break;
			}
			case 1:
				hp_ += 20;
				HP -= 1;
				cout << "* HP가 20 증가했습니다. (HP 포션 차감: 남은 포션 " << HP << "개)" << endl;
				break;
			case 2:
				mp_ += 20;
				MP -= 1;
				cout << "* MP가 20 증가했습니다. (MP 포션 차감: 남은 포션 " << MP << "개)" << endl;
				break;
			case 3:
				power_ *= 2;
				cout << "* 공격력이 2배 증가했습니다." << endl;
				break;
			case 4:
				defence_ *= 2;
				cout << "* 방어력이 2배 증가했습니다." << endl;
				break;
			case 5:
				printStatus();
				break;
			default:
				cout << "잘못된 번호를 입력했습니다." << endl;
				break;
			}
		}
	}
}