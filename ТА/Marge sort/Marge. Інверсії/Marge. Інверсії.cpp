// Marge. Інверсії.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

int** readFile(int *);
void Outputmass(int**, int, int);
void sortmas(int**, int, int, int);
void output_out(int **out, int n);
int merg_sort(int**arr, int l, int r, int index);
int merg(int** arr, int l, int m, int r, int index);
void sortOut(int** , int);
void OutputFile(int** out, int x, int n);
int main()
{
	setlocale(LC_CTYPE, "ukr");
	int *arr1 = new int[2];
	int **arr = readFile(arr1);
	int x;
	int n = arr1[0];
	int k = arr1[1];
	cout << "Введiть номер користувача в порiвняннi з яким будуть пiдраховуватись iнверсiй: ";
	cin >> x;
	x--;
	cout << endl;
	sortmas(arr, n, k, x);
	int **out = new int*[n];
	for (int i = 0; i < n; i++)
		out[i] = new int[2]; 
	for (int i = 0; i < n; i++)
	{
		out[i][0] = i + 1;
		out[i][1] = merg_sort(arr, 1, k, i);
	}
	Outputmass(arr, n, k);
	output_out(out, n);
	sortOut(out, n);
	OutputFile(out, x, n);

	system("Pause");
    return 0;
}

int** readFile(int* arr1)
{
	char *ptr;
    const char *delimiter = " ";
	char *n = NULL;
	char line[100];
	char name[20];
	cout << "Введiть назву файлу: ";
	gets_s(name, 20);
	int q, p=0;
	ifstream file(name);
	file.getline(line, 100);
	ptr = strtok_s(line, delimiter, &n);
	while (ptr)
	{
		if (p == 0)
		{
			q = atoi(ptr);
				p++;
		}
		else p = atoi(ptr);
		ptr = strtok_s(NULL, delimiter, &n);
	}
	arr1[0] = q;
	arr1[1] = p;
	int **arr = new int*[q];
	for (int i = 0; i < q; i++) arr[i] = new int[p+1];
	int i = 0;
	int j = 0;
	while (file.getline(line, 100))
	{
		
		ptr = strtok_s(line, delimiter, &n);
		while (ptr)
		{
			arr[i][j] = atoi(ptr);
			j++;
			ptr = strtok_s(NULL, delimiter, &n);
		}
		i++;
		j = 0;
	}
	
	file.close();
	return arr;
}

void OutputFile()
{
	ifstream file3("Output.txt");
	char line[100];
	while (file3.getline(line, 100))
	{
		cout << line << endl;
	}
	file3.close();
}

void Outputmass(int **arr, int n, int k)
{
	cout << "Array:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++) cout << arr[i][j] << ", ";
		cout << endl;
	}
}

int merg(int** arr, int l, int m, int r, int index)
{
	int inversion = 0;
	int *bufer = new int[r - l + 1];
	int ind1 = l;
	int ind2 = m + 1;
	int indb = 0;

	while (ind1 <= m && ind2 <= r)
	{
		if (arr[index][ind1] < arr[index][ind2])
			bufer[indb++] = arr[index][ind1++];
		else
		{
			bufer[indb++] = arr[index][ind2++];
			inversion += 1;
		}
	}

	while (ind1 <= m)
		bufer[indb++] = arr[index][ind1++];
	while (ind2<=r)
		bufer[indb++] = arr[index][ind2++];

	return inversion;
}

int merg_sort(int**arr, int l, int r, int index)
{
	int inversion = 0;
	if (l == r)
		return inversion;
	int m = (l + r) / 2;
	inversion += merg_sort(arr, l, m, index);
	inversion += merg_sort(arr, m + 1, r, index);

	inversion += merg(arr, l, m, r, index);
	return inversion;
}


void sortmas(int**arr, int n, int k, int x)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j < k; j++)
		{
			if (arr[x][j] > arr[x][j + 1])
				for (int h = 0; h < n; h++)
					swap(arr[h][j], arr[h][j + 1]);
		}
	}
}


void output_out(int **out, int n)
{
	cout << "Out::::::::" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << out[i][0] << " " << out[i][1] << endl;
	}
}

void sortOut(int**out, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (out[j][1] > out[j + 1][1])
			{
				swap(out[j][1], out[j + 1][1]);
				swap(out[j][0], out[j + 1][0]);
			}
		}
	}
}

void OutputFile(int** out, int x, int n)
{
	ofstream file1("Output.txt");
	file1 << x+1 << endl;
	for (int i = 0; i < n; i++)
		file1 << out[i][0] << setw(2) << out[i][1] << endl;
	file1.close();
}