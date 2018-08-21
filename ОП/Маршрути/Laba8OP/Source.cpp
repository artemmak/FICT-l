
#include <iostream>
#include <conio.h>

using namespace std;

int *Deykstra(int **GR, int V, int st);//�������� ������ ������������ ����� 
void input(int** arr, int n);//��������� ������� ������������
void output(int arr, int v);//��������� ���������� �����

int main()
{
	setlocale(LC_ALL, "ukr");
	int n;//ʳ������ ���
	cout << "����i�� �i���i��� �i��(>1, <100): ";
	cin >> n;//�������� ������� ���
	if (n < 1 || n>100)//��������� �� ����������� �������� �����
	{
		while (true)
		{
			cout << "���������� ��������. ��������� �� ���." << endl;
			cout << "������ ������� ���(>1, <100): ";
			cin >> n;
			if (!(n < 1 || n>100))
				break;
		}
	}
	cout << "����i�� �������: ";
	int k;
	cin >> k;
	int **mat = new int*[n];//�������� �������� ���'�� �� ������� ������������
	for (int i = 0; i < n; i++)
		mat[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = 0;
	input(mat, n);
	int **arr = new int*[n]; // �������� �������� ���'�� �� ������� ��� ��� ��������
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
	for (int i = 0; i < n; i++)//��������� �� ��� �����	
	{
		if (i != k - 1)
		{
			arr[i] = Deykstra(mat, n, i);//������ ������� ������ �������� ��� ������� �������
			output(arr[i][k-1], i);//��������� ��������� �����
		}
	}
	//��������� ��������������� ��������� ���'��
	for (int i = 0; i < n; i++)
		delete[] mat[i];
	delete[] mat;
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
	system("pause");
	return 0;
}

int *Deykstra(int **mat, int n, int v)
{
	int *d;//³����� �� ���
	bool *vis;//����� �������������� ��������� ����
	int index;
	d = new int[n];
	vis = new bool[n];
	for (int i = 0; i<n; i++)
	{
		d[i] = INT_MAX;//³������ �� ��� ���������������
		vis[i] = false; //�� ���� �������� �� ����������
	}
	d[v] = 0;//³������ �� ��������� ���� 0
	for (int k = 0; k < n - 1; k++) //��������� ����� ���
	{
		int min = INT_MAX;
		for (int i = 0; i < n; i++)//�������� �������, ��� �� �� ���������, ��� ���'����� � ����������
			if (!vis[i] && d[i] <= min)
			{
				min = d[i];
				index = i;
			}
		int u = index;//�����'������� ������ ������� �������
		vis[u] = true;//��������� �� �� ���������
		for (int i = 0; i < n; i++)//��������� �� ��� ��������
			if (!vis[i] && mat[u][i] && d[u] != INT_MAX &&
				d[u] + mat[u][i]<d[i])//���� ������� ������ � ������ �� �� �� ������� ����� �� ������� � ��
				d[i] = d[u] + mat[u][i];//���������� ���� �������
	}
	return d;//���������� ������� ����� ��������
}

void input(int** arr, int n)
{
	int i, j, t;

	while (true)
	{
		cout << "����i�� ������� ������: ";
		cin >> i;//������ ��������� ������� ������
		if (i - 1 < 0 || i - 1 > n-1)//��������� �� ����������� �������� �����
		{
			while (true)
			{
				cout << "���������� ��������. ��������� �� ���." << endl;
				cout << "����i�� ������� ������: ";
				cin >> i;
				if (!(i - 1 < 0 || i - 1 > n-1))
					break;
			}
		}
		cout << "����i�� �i���� ������: ";
		cin >> j;//������ ������ ������� ������
		if (j - 1 < 0 || j - 1 > n-1)//��������� �� ����������� �������� �����
		{
			while (true)
			{
				cout << "���������� ��������. ��������� �� ���." << endl;
				cout << "����i�� �i���� ������: ";
				cin >> j;
				if (!(j - 1 < 0 || j - 1 > n-1))
					break;
			}
		}
		cout << "����i�� ��� �� ���i� �����i: ";
		cin >> t;//������ ��� �� ���� �����
		if (t<0)//��������� �� ����������� �������� �����
		{
			while (true)
			{
				cout << "���������� ��������. ��������� �� ���." << endl;
				cout << "����i�� ��� �� ���i� �����i: ";
				cin >> t;
				if (!(t<0))
					break;
			}
		}
		if(i!=j)
			arr[i-1][j-1] = arr[j-1][i-1] = t;//�������� ��� �� ���� ����� � ������� ��������
		cout << "�i����-ESC\n" << "���i-Enter\n";
		int a = _getch();;
		if (a == 27) break;//��x���� � ����� ��������, ���� ��������� �� ������
	}	
}

void output(int arr, int v)
{
	cout << "��� �������� ������� � " << v + 1 << " �i��� � �������: " << arr << endl;//������� ��� �������� ������� � �������
}