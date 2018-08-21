#include <iostream>
#include "SpreadingRumors.h"
#include "SCHOOLS.h"
#include "StudSity.h"
#include <conio.h>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

void Tasks();

int main()
{
	SetConsoleOutputCP(1251);
	bool flag = true;
	bool flag1 = true;
	while (flag)
	{
		cout << "1.Вивести cписок задань та зробити вибiр завдання." << endl;
		cout << "2.Вивести дані розробника." << endl;
		cout << "3.Вихiд з програми." << endl;
		int a;
		cout << "Вибiр пункту меню: ";
		cin >> a;
		switch (a)
		{
		case 1:
			Tasks();
			break;
		case 2:
			cout << "Костенко Артем Юрійович   ІС-71" << endl;
			system("Pause");
			system("cls");
			break;
		case 3:
			flag = false;
			break;
		}
	}
	system("Pause");
	return 0;
}

void Tasks()
{
	ifstream f("Tasks.txt");
	char *tasks = new char[1000];
	while (f.good())
	{
		f.getline(tasks, 1000);
		cout << tasks << endl;
	}
	f.close();
	int a;
	cout << "Вибiр завдання: ";
	cin >> a;
	switch (a)
	{
		case 1:
			SpreadingRumors();
			return;
		case 2:
			SCHOOLS();
			return;
		case 3:
			prima();
			return;
	}
}
