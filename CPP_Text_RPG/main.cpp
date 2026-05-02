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
	return 0;
}