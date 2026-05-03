#pragma once
#include "pch.h"
#include "Player.h"
#include "Warrior.h"
using namespace std;

int main()
{
	string name;
	int HP = 5;
	int MP = 5;
	bool isGameStart = false;
	Player* player;

	cout << endl << "===========================================" << endl;
	cout << "       [ 던전 탈출 텍스트 RPG ]" << endl;
	cout << "===========================================" << endl;

	cout << "용사의 이름을 입력해주세요: ";
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

	player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
	player->printStatus();

	player->setStat(HP, MP, isGameStart);

	delete player;
	return 0;
}