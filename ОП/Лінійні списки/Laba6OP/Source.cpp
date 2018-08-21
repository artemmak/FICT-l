#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

struct List//��������� ������
{
	char *str;//������� ������
	List *next;//�������� �� �������� �������
};

void push(List*, char*);//������� ��������� �������� � ������
List* readFile();//������� ���������� �������� � �����
void OutputList(List*);//����� �������� ������
List* makeList();//������� ������� �������� � ���������
List* NewList(List *list, int n, int k);//������ �������� ���������� ������

int main()
{
	setlocale(LC_ALL, "ukr");

	List *list = NULL;//��������� ��������� ������

	List *newlist = NULL;//��������� �������� ������

	cout << "1.���������� ������'����� ������ �������� ���i � ���������� �����." << endl;
	cout << "2. ���������� ������'����� ������ ��i��� ���i � ����i�����." << endl;
	int a = _getch();
	while (true)
	{
		if (a == 49)
		{
			list = readFile();//�������� � �����
			break;
		}
		if (a == 50)
		{
			list = makeList();//��������� � ���������
			break;
		}
		cout << "���������� ���i�! ������i�� �����.";//������ �� ����������� �������
		a = _getch();
	}
	cout << endl;
	OutputList(list);//������� �������� ������
	cout << "����i�� ������� ������ �������i� ��� ������ ������: ";
	int n, k;//������ �������� ��� ����������� ������
	cin >> n;//������� ������ ������� ��������� ������
	cin >> k;

	newlist = NewList(list, n, k);//������� ���������� ������
	OutputList(newlist);//�������� ���������� ������
	system("Pause");
	return 0;
}

void push(List *list_, char *str)
{
	list_->next = new List;//������� ���'��� �� �������  
	list_->next->str = new char[100];
	strcpy_s(list_->next->str, 100, str);//������� ����
	list_->next->next = NULL;//���������� ��������� ������� ���� ���������� �� ������
}

void OutputList(List *list_)
{
	List *templist = list_;//�������� ��������� �������� ���� ������
	cout << templist->str << endl;//��������  ������� ������
	do {
		templist = templist->next;//���������� �� ���������� ��������
		cout << templist->str << endl;//������� ����
	} while (templist->next != NULL);//���� �� ������ �� ����
}

List* readFile()
{
	char *str = new char[100];
	List *list = new List;//�������� ���'��� �� ������ 
	list->str = new char[100];
	strcpy_s(list->str, 100, "List:");
	List *list_ = list;
	list_->next = new List;
	//list_ = list_->next;
	ifstream fin("Input.txt");//³�������� ����
	while (fin.good())
	{
		fin.getline(str, 100);//������� ������ � �����
		push(list_, str);//�������� �� � ������
		list_ = list_->next;//��������� �������� �� �������� �������
	}
	fin.close();//��������� ����
	return list;
}

List* makeList()
{
	char *str = new char[100];
	List *list = new List;
	list->str = new char[100];
	strcpy_s(list->str, 100, "List:");
	List *list_ = list;
	list_->next = new List;
	while (true)
	{
		cout << "����i�� ������� �������� ������: ";
		gets_s(str, 100);//������ � ��������� ������ ������
		push(list_, str);//�������� ������� � ������
		cout << "�i����-ESC\n" << "���i-Enter\n";
		int a = _getch();
		list_ = list_->next;
		if (a == 27) break;//������ � ����� �������, ���� �������� �� ������
	}
	return list;//��������� �������� �� ������
}

List* NewList(List *list, int n, int k)
{
	List *newlist = new List;//�������� ���'��� �� ������� �������
	newlist->str = new char[100];
	strcpy_s(newlist->str, 100, "New List:");
	List *list_ = newlist;
	list_->next = new List;
	int i = 0;
	char *str = new char[100];
	while (list->next != NULL)//����������� �� ��������� ��������� ������
	{
		if (i >= n && i <= k)//��� ��� ������ ������ �� ��������� ��������
		{
			strcpy_s(str, 100, list->str);
			push(list_, str);//������ ����� ������� � ����� ������
			list_ = list_->next;//��������� �������� ������� ������ �� �������� �������
		}
		i++;
		list = list->next;//��������� �������� ��������� ������ �� �������� �������
	}
	return newlist;//��������� �������� �� ��������� ������
}