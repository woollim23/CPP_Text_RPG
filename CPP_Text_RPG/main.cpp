#include <iostream>
using namespace std;

void printStatus(string name, int stat[])
{
	cout << endl << "====================================" << endl;
	cout << "  " << name << " 의 현재 능력치" << endl;
	cout << "====================================" << endl;
	cout << "HP: " << stat[0] << "   MP: " << stat[1] << endl;
	cout << "공격력: " << stat[2] << "   방어력: " << stat[3] << endl;
	cout << "====================================" << endl;
}


int main()
{
	cout << endl << "===========================================" << endl;
	cout << "       [ 던전 탈출 텍스트 RPG ]" << endl;
	cout << "===========================================" << endl;

	cout << "용사의 이름을 입력해주세요: ";
	string name;
	cin >> name;

	int stat[4] = { 0, }; // 0 - HP, 1 - MP, 2 - 공격력, 3 - 방어력 
	while (true)
	{
		cout << endl << "HP와 MP를 입력해주세요: ";
		cin >> stat[0] >> stat[1];
		if (stat[0] > 50 && stat[1] > 50)
			break;
	}
	while (true)
	{
		cout << endl << "공격력과 방어력을 입력해주세요: ";
		cin >> stat[2] >> stat[3];
		if (stat[2] > 50 && stat[3] > 50)
			break;
	}

	printStatus(name, stat);

	cout << "* HP 포션 5개, MP 포션 5개가 기본 지급되었습니다." << endl;
	cout << "============================================" << endl;
	cout << "< 캐릭터 강화 >" << endl;
	cout << "============================================" << endl;
	cout << "1. HP UP    2. MP UP    3. 공격력 2배" << endl;
	cout << "4. 방어력 2배  5. 현재 능력치  0. 게임 시작" << endl;

	int HP = 5;
	int MP = 5;
	bool isGameStart = false;

	while (!isGameStart)
	{
		int num;
		cout << "번호를 선택해주세요: ";
		cin >> num;

		switch (num)
		{
		case 0:
			cout << "게임을 시작합니다!" << endl;
			isGameStart = true;
			break;
		case 1:
			stat[0] += 20;
			HP -= 1;
			cout << "* HP가 20 증가했습니다. (HP 포션 차감: 남은 포션 " << HP << "개)"<<endl;
			break;
		case 2:
			stat[1] += 20;
			MP -= 1;
			cout << "* MP가 20 증가했습니다. (MP 포션 차감: 남은 포션 " << MP << "개)"<<endl;
			break;
		case 3:
			stat[2] *= 2;
			cout << "* 공격력이 2배 증가했습니다." << endl;
			break;
		case 4:
			stat[3] *= 2;
			cout << "* 방어력이 2배 증가했습니다." << endl;
			break;
		case 5:
			printStatus(name, stat);
			break;
		default:
			cout << "잘못된 번호를 입력했습니다" << endl;
		}
	}
	return 0;
}