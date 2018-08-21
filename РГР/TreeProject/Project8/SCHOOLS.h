#pragma once
#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;


void insertion(float** arr, int n); // Функція сортування вставкам
int getColor(int, int&, int*);

void SCHOOLS()
{
	SetConsoleOutputCP(1251);
	
	int n;
	int *nodes;	//масив вершин	
	ifstream fin("SCHOOLSInput.txt");//Відкриваємо файл для зчитування
	fin >> n;//зчитуємо n
	int ne;
	fin >> ne;
	float** arr = new float*[ne];   //Виділити пам'ять на ребра
	for (int i = 0; i < ne; i++)
		arr[i] = new float[3];
	for(int q=0; q<ne; q++)
	{
		fin >> arr[q][0];
		fin >> arr[q][1];
		fin >> arr[q][2];
	}
	fin.close();
	nodes = new int[ne];
	for (int i = 0; i < ne; i++)
		nodes[i] = -1 - i;
	insertion(arr, ne);//Сортування за зростанням
	cout << "З'єднанi школи:\n";
	float len = 0;			//Зміннна для мовжини з'єднання
	int last_n = -1;
	for (int i = 0; i < ne; i++)
	{
		int c2 = getColor(arr[i][1], last_n, nodes);
		if (getColor(arr[i][0], last_n, nodes) != c2)//Перевіряємо колір вершини
		{
			nodes[last_n] = arr[i][1];
			cout << arr[i][0] << "->" << arr[i][1] << " = " << arr[i][2] << endl;
			len += arr[i][2];//Збільшити кількість з'єднань
		}
	}
	cout << "Найменша вага схеми: " << len << endl;
	ofstream fout("SCHOOLSOutput.txt");
	fout << "Найменша вага схеми: " << len << endl;
	fout.close();
	system("Pause");
	system("cls");
}

void insertion(float** arr, int n)//сортування вставками
{
	for (int i = 1; i < n; i++)
	{
		int item = i;
		while (item > 0 && arr[item - 1][2] > arr[item][2])
		{
			swap(arr[item - 1], arr[item]);
			item--;
		}
	}
}

int getColor(int n, int &last_n, int* nodes)
{
	if (nodes[n]<0)//Якщо вершина не закрашена
		return nodes[last_n = n];//присвоюємо функції значення кольору
	int c = getColor(nodes[n], last_n, nodes);	//Рекурсивно викликаєу функцію для значення кольору
	nodes[n] = last_n;
	return c;//повертаємо отримане значення
}

