#include <iostream>
#include <fstream>

using namespace std;

int* readFile(int &n);
void piramida(int* arr, int n);
int Parent(int i);
int Left(int i);
int Right(int i);
void piramida(int* arr, int n);
void add1(int* arr, int a, int &size);
void add2(int* arr, int a, int &size);
int get1(int* arr, int &size);
int get2(int* arr, int &size);

int main()
{
	setlocale(LC_ALL, "ukr");
	int n;
	int *arr = readFile(n);
	piramida(arr, n);
	system("Pause");
	return 0;
}

int Parent(int i)
{
	return (i - 1) / 2;
}

int Left(int i)
{
	return 2 * i + 1;
}

int Right(int i)
{
	return 2 * i + 2;
}

int* readFile(int &n)
{
	char name[20];
	cout << "Ââåäiòü iì'ÿ ôàéëó: ";
	gets_s(name, 20);
	ifstream fin(name);
	fin >> n;
	int *arr = new int[n];
	int i = 0;
	while (fin.good())
		fin >> arr[i++];
	fin.close();
	return arr;
}

void piramida(int* arr, int n)
{
	ofstream fout("is71_maksakov.txt");
	int size1 = 1;
	int size2 = 0;
	int* hLeft = new int[n];
	int* hRight = new int[n];
	hLeft[0] = arr[0];
	fout << arr[0] << endl;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < hLeft[0])
			add1(hLeft, arr[i], size1);
		else
			add2(hRight, arr[i], size2);
		if (size1 - size2 > 1)
		{
			int elem = get1(hLeft, size1);
			add2(hRight, elem, size2);
		}
		if (size2 - size1 > 1)
		{
			int elem = get2(hRight, size2);
			add1(hLeft, elem, size1);
		}

		/*cout << "Arr1" << endl;
		for (int j = 0; j < size1; j++)
			cout << hLeft[j] << " ";
		cout << endl;
		cout << "Arr2" << endl;
		for (int j = 0; j < size2; j++)
			cout << hRight[j] << " ";
		cout << endl;

		if ((i + 1) % 2 == 0)
			cout << hLeft[0] << " " << hRight[0] << endl;
		else
			if (size1 > size2)
				cout << hLeft[0] << endl;
			else
				cout << hRight[0] << endl;*/

		if ((i + 1) % 2 == 0)
			fout << hLeft[0] << " " << hRight[0] << endl;
		else
			if (size1 > size2)
				fout << hLeft[0] << endl;
			else
				fout << hRight[0] << endl;
	}
}

void add1(int* arr, int a, int &size)
{
	arr[size] = a;
	int i = size;
	int temp;
	int parent = Parent(i);

	while (i > 0 && arr[parent] < arr[i])
	{
		swap(arr[i], arr[parent]);
		i = parent;
		parent = (i - 1) / 2;
	}
	size++;
}

void add2(int* arr, int a, int &size)
{
	arr[size] = a;
	int i = size;
	int temp;
	int parent = (i - 1) / 2;

	while (i > 0 && arr[parent] > arr[i])
	{
		swap(arr[i], arr[parent]);
		i = parent;
		parent = (i - 1) / 2;
	}
	size++;
}

int get1(int* arr, int &size)
{
	int number = arr[0];
	arr[0] = arr[size - 1];
	size--;
	int i = 0;
	int l = Left(0);
	int r = Right(0);

	while (l < size && (arr[i] < arr[l] || arr[i] < arr[r]))
	{
		if (arr[l] > arr[r])
		{
			swap(arr[l], arr[i]);
			i = l;
			l = Left(i);
			r = Right(i);
		}
		else
		{
			swap(arr[r], arr[i]);
			i = r;
			l = Left(i);
			r = Right(i);
		}
	}

	return number;
}

int get2(int* arr, int &size)
{
	int number = arr[0];
	arr[0] = arr[--size];
	int i = 0;
	int l = Left(0);
	int r = Right(0);

	while (l < size && (arr[i] > arr[l] || arr[i] > arr[r]))
	{
		if (arr[l] < arr[r])
		{
			swap(arr[l], arr[i]);
			i = l;
			l = Left(i);
			r = Right(i);
		}
		else
		{
			swap(arr[r], arr[i]);
			i = r;
			l = Left(i);
			r = Right(i);
		}
	}

	return number;
}