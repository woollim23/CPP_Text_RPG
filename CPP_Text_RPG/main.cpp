#pragma once
#include "pch.h"
#include "Player.h"
#include "Warrior.h"
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
	cout << "< 전투 하시겠습니까? >" << endl;
	cout << "1. 예     2. 아니오" << endl;
	cout << "====================================" << endl;

	/* 게임 종료 */
	delete player;
	return 0;
}