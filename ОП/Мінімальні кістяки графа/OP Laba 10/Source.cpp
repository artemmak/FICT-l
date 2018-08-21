
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;


int *nodes;	//����� ������		

float** CreateArray(int **, int, int&);	//������� ��� ���������� ������ �����
int getColor(int, int&);		//������� ��� ��������� ������� �����
void insertion(float** arr, int n); // ������� ���������� ��������

							
int main()
{
	setlocale(LC_ALL, "ukr");
	int **coords;				
	int n, v;	
	ifstream fin("Input.txt");//³�������� ���� ��� ����������
	fin >> n;//������� n
	coords = new int*[n];//�������� �������� ���'��� �� ����� ���������
	for (int i = 0; i < n; i++)
		coords[i] = new int[2];
	int i = 0;
	while (fin.good())
	{
		fin >> coords[i][0];//���������� ����� ���������
		fin >> coords[i++][1];
	}
	fin.close();
	float** arr = CreateArray(coords, n, v);	//��������� ����� ������	
	for (int i = 0; i < v; i++)
		cout << arr[i][0] << "   " << arr[i][1] << "    " << arr[i][2] << endl;
	nodes = new int[v];					
	for (int i = 0; i < v; i++)			
		nodes[i] = -1 - i;
	insertion(arr, v);		
	cout << "�'�����i �����:\n";
	float len = 0;			//������ ��� ������� �'�������
	int last_n = -1;			
	for (int i = 0; i < v; i++)	
	{		
		int c2 = getColor(arr[i][1], last_n);
		if (getColor(arr[i][0], last_n) != c2)//���������� ���� �������
		{
			nodes[last_n] = arr[i][1];
			cout << arr[i][0] << "->" << arr[i][1] << " = " << arr[i][2] << endl;
			len += arr[i][2];//�������� ������� �'�������
		}
	}
	cout << "������� ������������ ��������:" << len << endl;
	ofstream fout("Output.txt");	
	fout << len;	// �������� ���� ������� � ����	
	fout.close();
	system("Pause");
	return 0;
}

void insertion(float** arr, int n)//���������� ���������
{
	float x;
	int it, jt;
	for (int i = 1; i < n; i++)
	{
		int item = i;
		while (item > 0 && arr[item-1][2] > arr[item][2])
		{
			swap(arr[item-1], arr[item]);
			item--;
		}
	}
}

int getColor(int n, int &last_n) 
{
	if (nodes[n]<0)
		return nodes[last_n = n];
	int c = getColor(nodes[n], last_n);
	nodes[n] = last_n;
	return c;
}

float** CreateArray(int **coords, int n, int &ne) {
	ne = n * (n - 1) / 2;//ϳ��������� ������� �����
	float** arr = new float*[ne];   //������� ���'��� �� �����
	for (int i = 0; i < ne; i++)
		arr[i] = new float[3];
	int r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			//�������� ��� � �����
			arr[r][0] = i;
			arr[r][1] = j;
			arr[r][2] = sqrt(pow(coords[i][0] - coords[j][0], 2) + pow(coords[i][1] - coords[j][1], 2));
			r++;
		}
	}
	return arr;	//�������� ����� �����
}


