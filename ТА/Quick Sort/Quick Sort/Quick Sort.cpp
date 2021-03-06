// Quick Sort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>;
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string>

using namespace std;

struct Array
{
	int* array;
	int n;
};

Array* readFile(char*);
void OutputArray(int*, int);
void QuickSort3(int *arr, int left, int right, int &count);
void QuickSort2(int* arr, int left, int right, int &count);
void QuickSort(int *arr, int left, int right, int &count);
int Partition(int* arr, int left, int right, int &count);
int Border(int* arr, int left, int right);
void Partition3(int* arr, int left, int right, int &count, int &q1, int &q2, int &q3);
void SortingTetra(int *arr, int p, int r, int &kol);

int main()
{
	char name[30];
	cout << "Enter name file: ";
	gets_s(name, 30);
	Array *Arr = readFile(name);
	Array *Arr1 = readFile(name);
	Array *Arr2 = readFile(name);
	int n1 = Arr->n;
	int n2 = Arr->n;
	int n3 = Arr->n;
	int *arr1 = Arr->array;
	int *arr2 = Arr1->array;
	int *arr3 = Arr2->array;
	cout << "Array\n";
	for (int i = 0; i < n1; i++)
		cout << arr1[i] << " ";
	cout << endl;
	
	int count1, count2, count3;
	count1 = 0; count2 = 0; count3 = 0;
	cout << "sort1" << endl;
	QuickSort(arr1, 0, n1 - 1, count1);
	OutputArray(arr1, Arr->n);
	QuickSort2(arr2, 0, n2 - 1, count2);
	cout << "sort2" << endl;
	OutputArray(arr1, Arr->n);
	QuickSort3(arr3, 0, n3 - 1, count3);
	cout << "sort3" << endl;
	OutputArray(arr3, Arr->n);
	cout << "Sravni\n";
	cout << count1 << " " << count2 << " " << count3 << endl;
	ofstream fout("maksakov is-71.txt");
	fout << count1 << " " << count2 << " " << count3 << endl;
	fout.close();
	system("Pause");
    return 0;
}



Array* readFile(char* name)
{
	Array  *A = new Array;
	int i = 0;
	char line[20];
	ifstream read(name);
	read.getline(line, 20);
	A->n = atoi(line);
	A->array = new int[A->n];
	while (read.getline(line, 20))
	{
		A->array[i] = atoi(line);
		i++;
	}
	return A;
}

void OutputArray(int* arr, int n)
{
	cout << "Array:\n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void QuickSort(int *arr, int left, int right, int &count)
{
	int border;
	if (left < right)
	{
		border = Partition(arr, left, right, count);
		QuickSort(arr, left, border - 1, count);
		QuickSort(arr, border + 1, right, count);
	}
}

int Partition(int* arr, int left, int right, int &count)
{
	int x = arr[right];
	int i = left - 1;
	for (int j = left; j <= right - 1; j++)
	{
		count++;
		if (arr[j] <= x)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[right]);
	return i + 1;
}

int Border(int* arr, int left, int right)
{
	int border = (left + right) / 2;
	if (arr[left] < arr[border])
		if (arr[border] < arr[right])
			return border;
		else
			return right;
	if (arr[left] >= arr[border])
		if (arr[left] < arr[right])
			return left;
		else
			return right;
	if (arr[right] > arr[border])
		if (arr[left] < arr[right])
			return left;
		else
			return right;
	return border;
}



void QuickSort2(int* arr, int left, int right, int &count)
{
	if (left < right)
	{
		if (right - left < 3)
		{
			SortingTetra(arr, left, right, count);
			return;
		}
		int border = Border(arr, left, right - 1);
		swap(arr[border], arr[right]);
		border = Partition(arr, left, right, count);
		QuickSort2(arr, left, border - 1, count);
		QuickSort2(arr, border + 1, right, count);
	}
}



void Partition3(int* arr, int left, int right, int &count, int &q1, int &q2, int &q3)
{
	q1 = left + 2;
	int a = q1;
	q2 = left + 2;
	int b = q2;
	int c = right -1;
	q3 = right -1;
	int d = q3;
	int p = arr[left];
	int q = arr[left + 1];
	int r = arr[right];

	while (b <= c)
	{
		count++;
		while (arr[b] < q && b <= c)
		{
			count += 2;
			if (arr[b] < p)
				swap(arr[b], arr[a++]);
			b++;
		}
		count++;

		while (arr[c] > q && b <= c)
		{
			count += 2;
			if (arr[c] > r)
				swap(arr[c], arr[d--]);
			c--;
		}
		count++;
		count++;
		if (b <= c)
		{
			count++;
			if (arr[b] > r)
			{
				count++;
				if (arr[c] < p)
				{
					swap(arr[a], arr[b]);
					swap(arr[a++], arr[c]);
				}
				else
					swap(arr[b], arr[c]);
				swap(arr[c--], arr[d--]);
				b++;
			}
			else
			{
				count++;
				if (arr[c] < p)
				{
					swap(arr[b], arr[a]);
					swap(arr[a++], arr[c]);
				}
				else
					swap(arr[b], arr[c]);
				b++;
				c--;
			}
		}
	}
	count++;
	a--; b--;
	c++; d++;
	swap(arr[left + 1], arr[a]);
	swap(arr[a--], arr[b]);
	swap(arr[left], arr[a]);
	swap(arr[right], arr[d]);
	q1 = a;
	q2 = b;
	q3 = d;
}

void QuickSort3(int *arr, int left, int right, int &count)
{
	if (left<right)
	{
		if (right - left < 3)
		{
			SortingTetra(arr, left, right, count);
			
		}
		else
		{
			int q1, q2, q3;
			Partition3(arr, left, right, count, q1, q2, q3);
			QuickSort3(arr, left, q1 - 1, count);
			QuickSort3(arr, q1 + 1, q2 - 1, count);
			QuickSort3(arr, q2 + 1, q3 - 1, count);
			QuickSort3(arr, q3 + 1, right, count);
		} 
	}
}

void SortingTetra(int *arr, int p, int r, int &kol) {
	if (r - p == 1) {		// сортування двох елементів
		kol++;
		if (arr[p] > arr[r]) swap(arr[p], arr[r]);
		return;
	}
	if (r - p == 2) {		// сортування трьох елементів
		kol++;
		if (arr[p] > arr[p + 1]) {		// якщо лівий білше середнього
			swap(arr[p], arr[p + 1]);
			kol++;
			if (arr[p + 1] > arr[r]) {	// якщо середній більше правого
				swap(arr[p + 1], arr[r]);
				kol++;
				if (arr[p] > arr[p + 1]) swap(arr[p], arr[p + 1]);
			}
		}
		else {		// якщо лівий менше середнього
			kol++;
			if (arr[p + 1] > arr[r]) {		// якщо середній більше правого
				swap(arr[p + 1], arr[r]);
				kol++;
				if (arr[p] > arr[p + 1]) swap(arr[p], arr[p + 1]);	// якщо лівий білше нового середнього
			}
		}
		return;
	}
}