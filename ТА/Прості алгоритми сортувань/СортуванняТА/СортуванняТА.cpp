// СортуванняТА.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>

using namespace std;

void Input(int*, int);
void Sort1(int*, int);
void Sort2(int*, int);
void Sort3(int*, int);
void Output(int*, int);
int menu();
int fun();
int readfile(int*);
int dopmenu();
void  Outputfile(int*, int);
void makeInput();

int main()
{
	setlocale(LC_ALL, "ukr");
	int n;
	int k;
	int *ptr = new int[100000];
	bool flag = true;
	while (flag)
	{
		cout << endl << endl;
		k = menu();
		switch (k)
		{
		case 1: 
			cout << "Сортування меодом бульбашки" << endl;
			while (flag)
			{
				int r = dopmenu();
				switch (r)
				{
				case 1:
					n = fun();
					Input(ptr, n);
					flag = false;
					break;
				case 2:
					n = readfile(ptr);
					flag = false;
					break;
				case 3: 
					makeInput();
					n = readfile(ptr);
					flag = false;
					break;
				default:
					cout << "Некоректне введення." << endl;
					break;
				}
			}
			flag = true;
			cout << "Масив даних: ";
			Output(ptr, n);
			Sort1(ptr, n);
			cout << "Вiдсортований масив даних: ";
			Output(ptr, n);
			Outputfile(ptr, n);
			system("Pause");
			break;
		case 2:
			while (flag)
			{
				int r = dopmenu();
				switch (r)
				{
				case 1:
					n = fun();
					Input(ptr, n);
					flag = false;
					break;
				case 2:
					n = readfile(ptr);
					flag = false;
					break;
				case 3:
					makeInput();
					n = readfile(ptr);
					flag = false;
					break;
				default:
					cout << "Некоректне введення." << endl;
					break;
				}
			}
			flag = true;
			cout << "Сортування вставками" << endl;
			cout << "Масив даних: ";
			Output(ptr, n);
			Sort2(ptr, n);
			cout << "Вiдсортований масив даних: ";
			Output(ptr, n);
			Outputfile(ptr, n);
			system("Pause");
			break;
		case 3:
			while (flag)
			{
				int r = dopmenu();
				switch (r)
				{
				case 1:
					n = fun();
					Input(ptr, n);
					flag = false;
					break;
				case 2:
					n = readfile(ptr);
					flag = false;
					break;
				case 3:
					makeInput();
					n = readfile(ptr);
					flag = false;
					break;
				default:
					cout << "Некоректне введення." << endl;
					break;
				}
			}
			flag = true;
			cout << "Сортування меодом вибору" << endl;
			cout << "Масив даних: ";
			Output(ptr, n);
			Sort3(ptr, n);
			cout << "Вiдсортований масив даних: ";
			Output(ptr, n);
			Outputfile(ptr, n);
			system("Pause");
			break;
		case 4:
			flag = false;
			system("Pause");
			break;
		case 5:
			system("cls");
			break;
		default:
			cout << "Некоректне введення.";
			system("Pause");
			break;
		}
	}
	delete[] ptr;
	return 0;
}

int fun()
{
	int p;
	cout << "Введiть кiлькiсть cимволiв у масивi: ";
	cin >> p;
	cout << endl;
	return p;
}

int readfile(int *ptr)
{
	int p;
	char line[20];
	int i = 0;
	ifstream read("Input.txt");
	read.getline(line, 20);
	int n = atoi(line);
	while (read.getline(line, 20))
	{
		ptr[i] = atoi(line);
		i++;
	}
	return n;
}

int menu()
{
	int k;
	cout << "Виберiть потрiбний пункт з меню" << endl;
	cout << "1. Сортування методом бульбашки" << endl;
	cout << "2. Сортування вставками" << endl;
	cout << "3. Сортування методом вибору" << endl;
	cout << "4. Завершити роботу програми" << endl;
	cout << "5. Очистити консольне вiкно" << endl;
	cin >> k;
	return k;
}

int dopmenu()
{
	int k;
	cout << "Виберiть потрiбний пункт з меню" << endl;
	cout << "1. Сортування випадкових чисел" << endl;
	cout << "2. Сортування чисел з вхiдного файлу" << endl;
	cout << "3. Створити вхiдний файл" << endl;
	cin >> k;
	return k;
}

void Input(int* ptr, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		ptr[i] = rand() % 10;
	}
}

void makeInput()
{
	int p, q;
	ofstream make("Input.txt");
	cout << "Введiть потрiбну кiлькiсть елементiв масиву: ";
	cin >> p;
	make << p << endl;
	cout << "Введiть елементи масиву: ";
	for (int i = 0; i < p; i++)
	{
		cin >> q;
		make << q << endl;;
	}
	make.close();
}

void Output(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(2) << p[i];
	}
	cout << endl;
}

void Outputfile(int *ptr, int n)
{
	ofstream out("Output.txt");
	for (int i = 0; i < n; i++)
	{
		out << ptr[i] << endl;
	}
	out.close();
}

//Сортування методом бульбашки

void Sort1(int*ptr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (ptr[j] > ptr[j + 1])
			{
				swap(ptr[j], ptr[j + 1]);
			}
		}
	}
}

//Сортування вставками
void Sort2(int *ptr, int n)
{
	int element;
	int index;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (ptr[i] % 2 == 0)
		{
			for (int j = 0; j < n; j++)
			{
				if (ptr[j] % 2 != 0)
				{
					swap(ptr[i], ptr[j]);
					break;
				}
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (ptr[i] % 2 == 0)
		{
			element = ptr[i];
			index = i - 1;
			while (index >= 0 && element < ptr[index])
			{
				ptr[index + 1] = ptr[index];
				ptr[index] = element;
				index--;
			}
			k++;
		}
		else
		{
			element = ptr[i];
			index = i + 1;
			while (index >= k && element < ptr[index])
			{
				ptr[index - 1] = ptr[index];
				ptr[index] = element;
				index++;
			}
		}
	}
}

//Сортування методом вибору

void Sort3(int *ptr, int n)
{
	int min;
	int h = 0;
	for (int i = 0; i < n-1; i++)
	{
		min = ptr[i];
		int z = 0;
		for (int j = i + 1; j < n; j++)
		{
			if (min > ptr[j])
			{
				min = ptr[j];
				h = j;
				z++;
			}
		}
		if (z == 0) continue;
		swap(ptr[i], ptr[h]);
	}
}