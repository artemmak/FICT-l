// Лаба_ОП_Структури.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

struct direction;
struct plane;
struct information;

void Input();
void dopInput();
void clearFile();
void dopInput();
void delInfo();
void outStruct();
void searchNumber();
void searchType();
void delInfoNum();
void replace();
int menu();

int main()
{
	setlocale(LC_CTYPE, "ukr");
	bool flag = true;
	while (flag)
	{
		switch(int(menu()))
		{
		case 1:
			Input();
			system("Pause");
			break;
		case 2:
			dopInput();
			system("Pause");
			break;
		case 3:
			delInfo();
			system("Pause");
			break;
		case 4:
			outStruct();
			system("Pause");
			break;
		case 5:
			searchNumber();// Визначити номери авiацiйних рейсiв заданого напрямку з мiнiмальною вартiстю квиткiв.
			system("Pause");
			break;
		case 6:
			searchType();
			system("Pause");
			break;
		case 7:
			delInfoNum();
			system("Pause");
			break;
		case 8:
			replace();
			system("Pause");
			break;
		case 9:
			clearFile();
			system("Pause");
			break;
		case 10:
			flag = false;
			cout << endl;
			system("Pause");
			break;
		default:
			cout << "Некоректне введення." << endl;
		}
	}
    return 0;
}

int menu()
{
	int v;
	cout << endl;
	cout << "Виберiть потрiбний пункт з меню." << endl;
	cout << "1. Створити пустий файл i зиписати в нього данi." << endl;
	cout << "2. Зробити додатковий запис до файлу." << endl;
	cout << "3. Видалити запис з файлу." << endl;
	cout << "4. Вивести записи з файлу." << endl;
	cout << "5. Визначити номери авiацiйних рейсiв заданого напрямку з мiнiмальною вартiстю квиткiв." << endl;
	cout << "6. Визначити типи лiтакiв i сумарну кiлькiсть посадкових мiсць у заданому напрямку по днях тижня." << endl;
	cout << "7. Bилучити з масиву вiдомостi про рейси, якщо кiлькiсть польотiв на тиждень менше двох." << endl;
	cout << "8. Замiнити запис." << endl;
	cout << "9. Очистити файл." << endl;
	cout << "10. Завершити програму." << endl;
	cin >> v;
	cout << endl;
	return v;
}

struct direction
{
	int day[7];
	int number;
};

struct planes
{
	char type[15];
	int place;
	int price;
};

struct information
{
	direction direct;
	planes plane;
};

void Input()
{
	ofstream file("Binary.txt", ios::binary);
	information info[100];
	for (int i = 0; i < 100; i++)
	{
		gets_s(info[i].plane.type, 15);
		cout << endl;
		cout << "Введiть тип лiтака: ";
		gets_s(info[i].plane.type, 15);
		cout << "Введiть кiлькiсть посадкових мiсць: ";
		cin >> info[i].plane.place;
		cout << "Введiть вартiсть квитка: ";
		cin >> info[i].plane.price;
		cout << "Введiть номер авiацiйного рейсу: ";
		cin >> info[i].direct.number;
		cout << "Введiть льотнi днi на тиждень" << endl;
		cout << "(Введiть \"1\", якщо день льотний, \"2\" - якщо день не льотний)" << endl;
		cout << "Понедiлок ";
		cin >> info[i].direct.day[0];
		cout << endl;			
		cout << "Вiвторок ";
		cin >> info[i].direct.day[1];
		cout << endl;
		cout << "Середа ";
		cin >> info[i].direct.day[2];
		cout << endl;
		cout << "Четвер ";
		cin >> info[i].direct.day[3];
		cout << endl;
		cout << "П'ятниця ";
		cin >> info[i].direct.day[4];
		cout << endl;
		cout << "Субота ";
		cin >> info[i].direct.day[5];
		cout << endl;
		cout << "Недiля ";
		cin >> info[i].direct.day[6];
		cout << endl;
		file.write((char*)&info[i], sizeof(info[i]));
		cout << "Для продовження введення натиснiть будь яку клавiшу. Для завершення натиснiть ESCAPE.";
		char a = _getch();
		cout << endl;
		if (int(a) == 27 || i == 49)
			break;
		cout << endl;
		//
	}
	file.close();
}

void dopInput()
{
	ofstream file1("Binary.txt", ios::binary|ios_base::app);
	information info;
	gets_s(info.plane.type, 15);
	cout << "Введiть тип лiтака: ";
	gets_s(info.plane.type, 15);
	cout << "Введiть кiлькiсть посадкових мiсць: ";
	cin >> info.plane.place;
	cout << "Введiть номер авiацiйного рейсу: ";
	cin >> info.direct.number;
	cout << "Введiть вартiсть квитка: ";
	cin >> info.plane.price;
	cout << "Введiть льотнi днi на тиждень" << endl;
	cout << "(Введiть \"1\", якщо день льотний, \"2\" - якщо день не льотний)" << endl;
	cout << "Понедiлок ";
	cin >> info.direct.day[0];
	cout << endl;
	cout << "Вiвторок ";
	cin >> info.direct.day[1];
	cout << endl;
	cout << "Середа ";
	cin >> info.direct.day[2];
	cout << endl;
	cout << "Четвер ";
	cin >> info.direct.day[3];
	cout << endl;
	cout << "П'ятниця ";
	cin >> info.direct.day[4];
	cout << endl;
	cout << "Субота ";
	cin >> info.direct.day[5];
	cout << endl;
	cout << "Недiля ";
	cin >> info.direct.day[6];
	cout << endl;
	file1.write((char*)&info, sizeof(info));
	file1.close();
	cout << endl;
}

void clearFile()
{
	ofstream f("Binary.txt", ios::binary);
	f.close();
}

void delInfo()
{
	information info[100];
	int i = 0;

	ifstream fi("Binary.txt", ios::binary);
	cout << "Введiть параметри для видалення." << endl;
	cout << "Введіть номер авiацiйного рейсу.";
	int num;
	int n;
	cin >> num;
	cout << "Введіть тип літака:";
	char type[16];
	gets_s(type, 15);
	gets_s(type, 15);
	while (fi.good())
	{
		fi.read((char *)&info[i], sizeof(info[i]));//прочитати інформацію
		if (fi.good())
		{
			if (strcmp(info[i].plane.type, type) == 0 && info[i].direct.number == num)
			{
				n = i;
				break;
			}
		}
		i++;
	}
	fi.close();
	ofstream file1("Binary.txt", ios::binary);
	for (int j = 0; j <= i; j++)
		if(i!=n)
			file1.write((char*)&info[j], sizeof(info[j]));
	file1.close();
	cout << endl;
}

void replace()
{
	information info[100];
	ifstream file2("Binary.txt", ios::binary);
	bool flag = true;
	int j = 0;
	cout << "Введiть параметри рейсу для зaмiни." << endl;
	cout << "Введiть номер авiацiйного рейсу: ";
	int num;
	cin >> num;
	cout << "Введiть тип лiтака: ";
	char type[15];
	gets_s(type, 15);
	gets_s(type, 15);
	while (file2.good())
	{
		file2.read((char *)&info[j], sizeof(info[j]));//прочитати інформацію
		if (strcmp(info[j].plane.type, type) == 0 && info[j].direct.number == num)
		{
			cout << "Знайдено потрiбний запис." << endl;
			cout << "Старi данi." << endl;
			cout << "Тип лiтака      " << "Kiлькiсть посадкових мiсць       ";
			cout << "Вартiсть квитка      " << "Номер авiацiого рейсу      ";
			cout << "Льотнi днi на тидждень " << endl;
			cout << info[j].plane.type << setw(23) << info[j].plane.place << setw(32) << info[j].plane.price
				<< setw(20) << info[j].direct.number << setw(20);
			if (info[j].direct.day[0] == 1)
				cout << "Пн";
			if (info[j].direct.day[1] == 1)
				cout << " Вт";
			if (info[j].direct.day[2] == 1)
				cout << " Ср";
			if (info[j].direct.day[3] == 1)
				cout << " Чт";
			if (info[j].direct.day[4] == 1)
				cout << " Пт";
			if (info[j].direct.day[5] == 1)
				cout << " Сб";
			if (info[j].direct.day[6] == 1)
				cout << " Нд";
			cout << endl;
			cout << "Введiть новi данi:" << endl;
			cout << "Введiть тип лiтака: ";
			gets_s(info[j].plane.type, 10);
			cout << "Введiть кiлькiсть посадкових мiсць: ";
			cin >> info[j].plane.place;
			cout << "Введiть вартiсть квитка: ";
			cin >> info[j].plane.price;
			cout << "Введiть номер авiацiйного рейсу: ";
			cin >> info[j].direct.number;
			cout << "Введiть льотнi днi на тиждень" << endl;
			cout << "(Введiть \"1\", якщо день льотний, \"2\" - якщо день не льотний)" << endl;
			cout << "Понедiлок ";
			cin >> info[j].direct.day[0];
			cout << endl;
			cout << "Вiвторок ";
			cin >> info[j].direct.day[1];
			cout << endl;
			cout << "Середа ";
			cin >> info[j].direct.day[2];
			cout << endl;
			cout << "Четвер ";
			cin >> info[j].direct.day[3];
			cout << endl;
			cout << "П'ятниця ";
			cin >> info[j].direct.day[4];
			cout << endl;
			cout << "Субота ";
			cin >> info[j].direct.day[5];
			cout << endl;
			cout << "Недiля ";
			cin >> info[j].direct.day[6];
			cout << endl;
			
			flag = false;
		}
		j++;
	}
	if (flag)
		cout << "Не знайдено потрібного рейсу!" << endl;
	if (!flag)
	{
		file2.close();
		ofstream file("Binary.txt", ios::binary);
		for (int i = 0; i < j-1; i++)
			file.write((char*)&info[i], sizeof(info[i]));
		file.close();
	}
}

void delInfoNum()
{
	information info[100];
	information newinfo[100];
	ifstream file2("Binary.txt", ios::binary);
	int i = 0;
	int k = 0;
	while (file2.good())
	{
		file2.read((char *)&info[i], sizeof(info[i]));//прочитати інформацію
		i++;
	}
	int *arr = new int[i+1];
	for (int j = 0; j < i; j++)
	{
		int n = 0;
		for (int h = 0; h < 7; h++)
		{
			if (info[j].direct.day[h] == 1)
				n++;
		}
		if (n > 2)
		{
			newinfo[k++] = info[j];
		}
	}
	file2.close();
	ofstream fil("Binary.txt", ios::binary);
	for (int j = 0; j < k; j++)
	{
		fil.write((char*)&newinfo[j], sizeof(newinfo[j]));
	}
	fil.close();

}

void searchNumber()
{
	information info;
	information sinfo[100];
	int i = 0;
	ifstream filee("Binary.txt", ios::binary);
	cout << "Введiть параметри для пошуку." << endl;
	cout << "Введiть номер авiацiйного рейсу.";
	int num;
	int n;
	cin >> num;
	while (filee.good())
	{
		filee.read((char *)&info, sizeof(info));//прочитати інформацію
		if (filee.good())
		{
			if (info.direct.number == num)
			{
				sinfo[i] = info;
				i++;
			}
		}
	}
	filee.close();
	if (i != 0)
	{
		for (int k = 0; k < i; k++)
			for (int j = 0; j < i - 1; j++)
				if (sinfo[j].plane.price > sinfo[j + 1].plane.price)
					swap(sinfo[j], sinfo[j + 1]);
		cout << "Тип лiтака      " << "Kiлькiсть посадкових мiсць       ";
		cout << "Вартiсть квитка      " << "Номер авiацiого рейсу      ";
		cout << "Льотнi днi на тидждень " << endl;
		for (int j = 0; j < i; j++)
		{
			cout << sinfo[j].plane.type << setw(25) << sinfo[j].plane.place << setw(29) << sinfo[j].plane.price
				<< setw(20) << sinfo[j].direct.number << setw(20);
			if (sinfo[j].direct.day[0] == 1)
				cout << "Пн";
			if (sinfo[j].direct.day[1] == 1)
				cout << " Вт";
			if (sinfo[j].direct.day[2] == 1)
				cout << " Ср";
			if (sinfo[j].direct.day[3] == 1)
				cout << " Чт";
			if (sinfo[j].direct.day[4] == 1)
				cout << " Пт";
			if (sinfo[j].direct.day[5] == 1)
				cout << " Сб";
			if (sinfo[j].direct.day[6] == 1)
				cout << " Нд";
			cout << endl;
		}
	}
	cout << endl;
}

void searchType()
{
	information info[100];
	ifstream fi("Binary.txt", ios::binary);
	cout << "Введiть параметри для пошуку." << endl;
	cout << "Введiть номер авiацiйного рейсу: ";
	int num;
	cin >> num;
	gets_s(info[0].plane.type, 15);
	int j = 0;
	while (fi.good())
	{
		fi.read((char *)&info[j], sizeof(info[j]));//прочитати інформацію
		if (fi.good())
			j++;
	}
	int t = 0;
	information sinfo[100];
	for (int i = 0; i < j; i++)
	{
		if (info[i].direct.number == num)
		{
			sinfo[t] = info[i];
			t++;
		}
	}
	if (t != 0)
	{
		int *sum = new int[7];
		for (int u = 0; u < 7; u++)
			sum[u] = 0;
		for (int i = 0; i < t; i++)
		{
			if (sinfo[i].direct.day[0] == 1)
				sum[0] += sinfo[i].plane.place;
			if (sinfo[i].direct.day[1] == 1)
				sum[1] += sinfo[i].plane.place;
			if (sinfo[i].direct.day[2] == 1)
				sum[2] += sinfo[i].plane.place;
			if (sinfo[i].direct.day[3] == 1)
				sum[3] += sinfo[i].plane.place;
			if (sinfo[i].direct.day[4] == 1)
				sum[4] += sinfo[i].plane.place;
			if (sinfo[i].direct.day[5] == 1)
				sum[5] += sinfo[i].plane.place;
			if (sinfo[i].direct.day[6] == 1)
				sum[6] += sinfo[i].plane.place;
		}
		cout << "День тиждня   " << setw(3) << "Кiлькiсть посадкових мiсць   " << setw(3) << "Типи лiтакiв" << endl;
		cout << "Понеділок" << setw(19) << sum[0] << setw(14) << "";
		for (int i = 0; i < t; i++)
			if(sum[0]!=0)
				cout << "  " << sinfo[i].plane.type;
		cout << endl;
		cout << "Вiвторок" << setw(20) << sum[1] << setw(14) << "";
		for (int i = 0; i < t; i++)
			if (sum[1] != 0)
				cout << "  " << sinfo[i].plane.type;
		cout << endl;
		cout << "Середа" << setw(22) << sum[2] << setw(14) << "";
		for (int i = 0; i < t; i++)
			if (sum[2] != 0)
				cout << "  " << sinfo[i].plane.type;
		cout << endl;
		cout << "Четвер" << setw(22) << sum[3] << setw(14) << "";
		for (int i = 0; i < t; i++)
			if (sum[3] != 0)
				cout << "  " << sinfo[i].plane.type;
		cout << endl;
		cout << "П'ятниця" << setw(20) << sum[4] << setw(14) << "";
		for (int i = 0; i < t; i++)
			if (sum[4] != 0)
				cout << "  " << sinfo[i].plane.type;
		cout << endl;
		cout << "Субота" << setw(22) << sum[5] << setw(14) << "";
		for (int i = 0; i < t; i++)
			if (sum[5] != 0)
				cout << "  " << sinfo[i].plane.type;
		cout << endl;
		cout << "Недiля" << setw(22) << sum[6] << setw(14) << "";
		for (int i = 0; i < t; i++)
			if (sum[6] != 0)
				cout << "  " << sinfo[i].plane.type;
		cout << endl;
	}
}

void outStruct()
{
	information info;
	ifstream fi("Binary.txt", ios::binary);
	if (fi.eof())
		cout << "Не знайдено жодного запису!!";
	else
	{
		cout << "Тип лiтака      " << "Kiлькiсть посадкових мiсць       ";
		cout << "Вартiсть квитка      " << "Номер авiацiого рейсу      ";
		cout << "Льотнi днi на тидждень " << endl;
	}
		
	while (fi.good())
	{
		fi.read((char *)&info, sizeof(info));//прочитати інформацію
		if (fi.good())
		{
			cout << info.plane.type << setw(23) << info.plane.place << setw(32) << info.plane.price
				<< setw(20) << info.direct.number << setw(20);
			if (info.direct.day[0] == 1)
				cout << "Пн";
			if (info.direct.day[1] == 1)
				cout << " Вт";
			if (info.direct.day[2] == 1)
				cout << " Ср";
			if (info.direct.day[3] == 1)
				cout << " Чт";
			if (info.direct.day[4] == 1)
				cout << " Пт";
			if (info.direct.day[5] == 1)
				cout << " Сб";
			if (info.direct.day[6] == 1)
				cout << " Нд";
			cout << endl;
		}
	}
	fi.close();
	cout << endl;
}