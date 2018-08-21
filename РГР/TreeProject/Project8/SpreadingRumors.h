#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

void SpreadingRumors()
{
	SetConsoleOutputCP(1251);
	int n;
	int *nodes;	//масив вершин	
	ifstream fin("SpreadingRumorsInput.txt");//Відкриваємо файл для зчитування
	fin >> n;//зчитуємо n
	float** arr = new float*[n];   //Виділити пам'ять на ребра
	for (int i = 0; i < n; i++)
		arr[i] = new float[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = 0;
	int i = 0;
	int g, h;
	while (fin.good())
	{
		fin >> g;
		fin >> h;
		arr[g-1][h-1] = arr[h-1][g-1] = 1;
	}
	fin.close();
	int len = 0;
	nodes = new int[n];
	for (int i = 0; i < n; i++)
		nodes[i] = -1;
	cout << "З'єднанi ребра:\n";
	for (int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++)
			if (arr[i][j] == 1)
			{
				if (nodes[i] != 1)
				{
					cout << i + 1 << "->" << j + 1 << endl;
					nodes[i] = nodes[j] = 1;
					len++;
				}
				if (nodes[j] != 1)
				{
					cout << i + 1 << "->" << j + 1 << endl;
					nodes[i] = nodes[j] = 1;
					len++;
				}
			}
	int *zeronumber = new int[n];
	int k = 0;
	for (int i = 0; i < n; i++)
		if (nodes[i] != 1)
			zeronumber[k++] = i + 1;
	cout << "Кiлькiсть прокладених зустрiчей:" << len << endl;
	ofstream fout("SpreadingRumorsOutput.txt");
	if (k == 0)
	{
		cout << endl << "Чутка поширеться по всьому селi!" << endl;
		fout << endl << "Чутка поширеться по всьому селi!" << endl;
	}
	else
	{
		cout << endl <<  "Чутка не поширеться, оскiльки житель: ";
		for (int kk = 0; kk < k; kk++)
			cout << zeronumber[kk] << ", ";
		cout << "не має зустрiчi з жодним з жителiв!" << endl << endl;
		fout << endl << "Чутка не поширеться, оскiльки житель: ";
		for (int kk = 0; kk < k; kk++)
			fout << zeronumber[kk] << ", ";
		fout << "не має зустрiчi з жодним з жителiв!" << endl;
	}
	fout.close();

	system("Pause");
	system("cls");
}
