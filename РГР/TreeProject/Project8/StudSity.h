#pragma once
#include <iostream>
#include <fstream>

using namespace std;

int minf(int** arr, int& ii, int& jj, int n, int min, int k);


void prima()
{
	int n;
	ifstream fin("StudSityInput.txt");
	fin >> n;
	int *nodes = new int[n];
	for (int i = 0; i < n; i++)
		nodes[i] = -1;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = INT_MAX;
	int k1, k2;
	while (fin.good())
	{
		fin >> k1;
		fin >> k2;
		fin >> arr[k1 - 1][k2 - 1];
		arr[k2 - 1][k1 - 1] = arr[k1 - 1][k2 - 1];
	}
	fin.close();
	nodes[0] = 1;
	int ii, jj;
	int k = 0;
	int len = 0;
	cout << "Прокладенi зв'зки: " << endl;
	for(int k=0; k<n-1; k++)
	{
		int min = INT_MAX;
		for(int i=0; i<n; i++)
			if (nodes[i] == 1)
			{
				min = minf(arr, ii, jj, n, min, i);

			}
		if (min < INT_MAX)
		{
			cout << ii + 1 << "->" << jj + 1 <<  endl;
			arr[ii][jj] = INT_MAX;
			arr[jj][ii] = INT_MAX;
			for (int i = 0; i < n; i++)
				arr[i][jj] = INT_MAX;
			nodes[ii] = 1;
			nodes[jj] = 1;
			len += min;
		}
	}
	cout << "Необхiдна довжина кабелю: " << len << endl;
	ofstream fout("StudSityOutput.txt");
	fout << "Необхiдна довжина кабелю: " << len << endl;
	fout.close();
	system("Pause");
	system("cls");
}

int minf(int** arr, int& ii, int& jj, int n, int min, int k)
{
	for(int i=0; i<n; i++)
		if (arr[k][i] < min)
		{
			min = arr[k][i];
			ii = k;
			jj = i;
		}
	return min;
}
