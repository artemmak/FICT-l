#include <iostream>
#include <fstream>

using namespace std;

const int STR_SIZE = 255;

double** readFile(const char* fileName, int &n)
{
	ifstream file(fileName);

	file >> n;

	double **arr = new double*[n];

	for (int i = 0; i < n; ++i)
		arr[i] = new double[2];

	for (int i = 0; i < n; ++i)
		file >> arr[i][0] >> arr[i][1];

	file.close();

	return arr;
}

double** getTable(double **arr, int n)
{
	double **matrix = new double*[n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new double[n];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}

			matrix[i][j] = pow((pow(arr[j][0] - arr[i][0], 2) + pow(arr[j][1] - arr[i][1], 2)), 1. / 2.);
		}
	}

	return matrix;
}

void printMatr(double **a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int MinimalIndexElem(int ii, double **matrix, int *s, int n)
{
	double min = DBL_MAX;
	int minind;

	for (int i = 0; i < n; ++i)
	{
		if (ii == i || s[ii] == s[i]) continue;

		if (matrix[ii][i] < min)
		{
			minind = i;
			min = matrix[ii][i];
		}
	}

	return minind;
}

void unite(int *s, int n, int ii, int minInd)
{
	if (s[ii] == s[minInd])
		return;

	int t = s[minInd];

	for (int i = 0; i < n; ++i)
	{
		if (s[i] == t)
			s[i] = s[ii];
	}
}

bool CheckConect(int *s, int n)
{
	int a = s[0];

	for (int i = 1; i < n; ++i)
	{
		if (s[i] != a)
			return false;
	}

	return true;
}

int main()
{
	int n;
	char *fileName = new char[STR_SIZE];
	cout << "file name: ";
	cin >> fileName;
	double **input = readFile(fileName, n);
	double **matrix = getTable(input, n);
	int ii = 0,//Покажчик на поточну вершину
		minInd;
	double len = 0;
	int *s = new int[n];
	for (int i = 0; i < n; ++i)
		s[i] = i;

	int *v = new int[n + 1];
	int i = 1;

	v[0] = ii;

	while (!CheckConect(s, n))
	{
		minInd = MinimalIndexElem(ii, matrix, s, n);
		len += matrix[ii][minInd];
		cout << endl;
		unite(s, n, ii, minInd);
		ii = minInd;
		v[i++] = ii;
	}
	v[i++] = 0;
	len += matrix[ii][0];

	ofstream file("output_maksakov_is-71.txt");
	file << len << "\n";
	for (int i = 0; i < n; ++i)
		file << v[i] << " ";
	file.close();
	system("pause");
	return 0;
}