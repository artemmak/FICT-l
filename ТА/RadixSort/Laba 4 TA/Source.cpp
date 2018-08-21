
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int* input();
void output(int *arr, int n);
void Sort(int *arr, int n, int d);
void RadixSort(int*arr, int n, int d);

int main()
{
	cout << "Enter digit number: ";
	int d;
	cin >> d;
	int *arr = input();
	int n;
	ifstream f("Input.txt");
	f >> n;
	f.close();
	cout << "Array" << endl;
	output(arr, n);
	cout << endl;
	RadixSort(arr, n, d);
	cout << "Sorted array" << endl;
	output(arr, n);
	cout << endl;
	delete[] arr;
	system("Pause");
	return 0;
}

int* input()
{
	ifstream file("Input.txt");
	int n;
	file >> n;
	int *arr = new int[n];
	int i = 0;
	while (file.good())
	{
		file >> arr[i];
		cout << arr[i] << endl;
		i++;
	}
	file.close();
	return arr;
}

void RadixSort(int*arr, int n, int d)
{
	for (int i = 1; i <= d; i++)
	{
		Sort(arr, n, i);
	}
}

void Sort(int *arr, int n, int d)
{
	int *temp = new int[n];
	const int g = 10;
	int elem[g];
	for (int i = 0; i < g; i++)
		elem[i] = 0;
	for (int i = 0; i < n; i++)
		elem[int((arr[i] / pow(10, d - 1))) % 10]++;
	for (int i = 1; i < g; i++)
		elem[i] += elem[i - 1];
	for (int i = 0; i < n; i++)
	{
		int k = int((arr[i] / pow(10, d - 1))) % 10;
		temp[elem[k]-1] = arr[i];
		elem[k]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = temp[i];
}

void output(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
}