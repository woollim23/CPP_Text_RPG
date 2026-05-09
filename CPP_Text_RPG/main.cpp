#pragma once
#include "pch.h"
#include "Player.h"
#include "Warrior.h"
#include "Monster.h"
using namespace std;

int main()
{
	/* 캐릭터 생성 */
	string name;
	int HP = 5;
	int MP = 5;
	bool isGameStart = false;
	Player* player = nullptr;

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

	int jobChoice;
	while (true) {
		cout << endl << "====================================" << endl;
		cout << "< 전직 시스템 >" << endl;
		cout << "====================================" << endl;
		cout << name << "님, 직업을 선택해주세요!" << endl;
		cout << "1. 전사" << endl;
		cout << "선택: ";
		cin >> jobChoice;
		if (jobChoice >= 1 && jobChoice <= 1) break;
		system("cls");
		cout << "잘못된 입력입니다. 다시 선택해주세요." << endl;
	}

	switch (jobChoice) {
	case 1: 
		player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
		break;
	}
	
	system("cls");

	cout << "* " << player->getJob() << "로 전직하였습니다." << endl;
	
	player->printStatus();

	player->setStat(HP, MP, isGameStart);

	/* 전투 */
	cout << endl << "====================================" << endl;
	cout << "< 전투 하시겠습니다>" << endl;
	cout << "====================================" << endl;

	

	while (!isGameStart)
	{
		int num = 0;
		cin >> num;
		switch (num)
		{
		case 1:
			isGameStart = false;
			break;
		case 2:
			break;
		default:
			cout << "잘못 입력하셨습니다.";
			break;
		}
	}

	Monster* monster = new Monster();
	int isBattle = 1; // 1 - 플레이어 선공, 2 - 몬스터 선공

	while (player->getHP() > 0 && monster->getHP() > 0)
	{
		switch (isBattle)
		{
		case 1:
			player->attack(player, monster);
			isBattle = 2;
			break;
		case 2:
			monster->attack(monster, player);
			isBattle = 1;
			break;
		default:
			cout << "게임 오류";
			break;
		}

		if (player->getHP() <= 0)
		{
			cout << "몬스터 승리!!";
		}
		else if (monster->getHP() <= 0)
		{
			cout << "플레이어 승리!!";
		}
	}

	/* 게임 종료 */
	delete player;
	return 0;
}