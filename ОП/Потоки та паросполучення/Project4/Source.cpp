#include <iostream>
#include <fstream>

using namespace std;

int** creatArr(int n, int m);
int** distribution(int** arr, int n, int m, int t);//������� ����������� ��'���� �� ���������

int main()
{
	setlocale(LC_ALL, "ukr");
	int n, m, k, t, ii, jj, i, j;
	ifstream fin("Input.txt");//³�������� ���� ��� ���������
	fin >> n;
	fin >> m;
	fin >> k;
	fin >> t;
	int** arr = creatArr(n, m);//�������� ���'��� �� ������� ������������
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			arr[i][j] = 0;
	int **coord = creatArr(k, 2);//�������� ���'��� �� ������� �������������
	for (i = 0; i < k; i++)
	{
		fin >> ii;
		fin >> jj;
		coord[i][0] = ii;
		coord[i][1] = jj;
		arr[ii-1][jj-1] = 1;//���������� ������� ������������
	}
	fin.close();
	cout << "������� i�����������i: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << arr[i][j] << "  ";
		cout << endl;
	}

	int **check = distribution(arr, n, m, t);//���������� �������� ������� � ���� ������������ �����
	int *w = new int[n + m];//�������� ���'��� ��� ������ ������������ �������
	int iw = 0;
	int max, min;
	int* company = new int[t + 1];//�������� ���'�� ��� ���������� ������, �� �������� ������
	for (i = 0; i < n; i++)//��������� �� ������ ������� ������������
	{
		for (int r = 0; r < t + 1; r++)
			company[r] = 0;
		for (j = 0; j < m; j++)//����������� �� ��������
			company[check[i][j]]++;//ϳ��������� ������� ���������� ����� � �����
		max = company[1];//����� ������� � ������������ ������� �����
		for (int g = 2; g < t + 1; g++)
			if (company[g] > max)
				max = company[g];
		min = company[1];//����� ������� � ��������� ������� �����
		for (int g = 2; g < t + 1; g++)
			if (company[g] < max)
				min = company[g];
		w[iw++] = max - min;//����� ������������ ������� ��� ���� � ������
	}
	for (i = 0; i < m; i++)//��������� �� ��������
	{
		for (int r = 0; r < t + 1; r++)	 
			company[r] = 0;
		for (j = 0; j < n; j++)//��������� �� ������
			company[check[j][i]]++;//ϳ��������� ������� ���������� ����� � �������
		max = company[1];
		for (int g = 2; g < t + 1; g++)//����� ������� � ������������ ������� �����
			if (company[g] > max)
				max = company[g];
		min = company[1];
		for (int g = 2; g < t + 1; g++)//����� ������� � ��������� ������� �����
			if (company[g] < max)
				min = company[g];
		w[iw++] = max - min;//����� ������������ ������� ��� ���� � ������
	}
	int wsum = 0;
	for (i = 0; i < n + m; i++)
		wsum += w[i];//�������� �������� ������������ �������
	cout << "������� ������i����� : " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << check[i][j] << "  ";
		cout << endl;
	}
	ofstream fout("Output.txt");
	fout << wsum << endl;//�������� ������� ��� � ����
	for (i = 0; i < k; i++)
		fout << check[coord[i][0]-1][coord[i][1]-1] << "  ";
	fout.close();
	system("Pause");
	return 0;
}

int** distribution(int** arr, int n, int m, int t)
{
	int* company = new int[t+1];//�������� ���'��� �� ����� ��� ����� ���� ������� ������� �'���� ��������� ������������
	int i, j;
	for(i = 0; i < t+1; i++)
		company[i] = 0;//��������� �������� ���������� ���� 0
	int** check = creatArr(n, m);//�������� ���'��� �� ����� ��� ������ ������������ ������
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			check[i][j] = 0;
	for (i = 0; i < n; i++)//��������� �� ������
		for (j = 0; j < m; j++)//��������� �� ��������
			if (arr[i][j])//���� �� ������ ��������� � ��'����
			{
				if (!check[i][j])//���� ����� ��'���� �� ������������
				{
					for (int ii = 0; ii < m; ii++)
						company[check[i][ii]]++;//���������� ����� ������������ ������ � ������ �����
					for (int ii = 0; ii < n; ii++)
						company[check[ii][j]]++;//���������� ����� ������������ ������ � ������ �������
					int min = company[1];
					int minindex = 1;//��������� ������ ������, ����� ����������� �������� ��'����
					for(int ii=2; ii<t+1; ii++)
						if (company[ii] < min)
						{
							min = company[ii];
							minindex = ii;
						}
					check[i][j] = minindex;//��������� ����� ��'���� �� ���������
					for (int ii = 0; ii < t + 1; ii++)
						company[ii] = 0;
				}
			}
	return check;//��������� ����� ����������� ������
}

int** creatArr(int n, int m)//������� ��� ������� ���'�� �� ����� nxm
{
	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	return arr;
}