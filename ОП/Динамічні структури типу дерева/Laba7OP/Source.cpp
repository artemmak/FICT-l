
#include <iostream>
#include <fstream>

using namespace std;

struct Node //��������� ����� ������
{
	int data;//��� ����� ������
	Node *left;//�������� �� ��� ����
	Node *right;//�������� �� ����� ����
};

void creatTree(Node* &t);//������� ��������� ������, �� ����� ����� � �����
void add(Node* &t, int a);//������� ������ ����� ������
void print(Node *&t, int u);//������� ��������� ������
void modify(Node* &t);//������� ����������� ������

int main()
{
	Node* tree = NULL;//��������� �������� �� ������
	creatTree(tree);//���������� ������
	print(tree, 0);//�������� ������
	modify(tree);//������� ������
	cout << endl << endl << endl << endl;
	print(tree, 0);//�������� ������������ ������
	system("Pause");
	return 0;
}

void print(Node *&t, int u)
{
	if (t == NULL) return;//���� �����-NULL-��������
	print(t->left, ++u);//���������� ������� ��� ���� ������
	for (int i = 0; i < u; i++)
		cout << "          ";
	cout << t->data << endl;//�������� ��� �����
	u--;
	print(t->right, ++u);//���������� ������� ����� ���� ������
}

void add(Node* &t, int a)
{
	if (t == NULL)//���� ����� ������
	{
		t = new Node;//�������� ���'��� �� �����
		t->data = a;//�������� ���
		t->left = t->right = NULL;//��������� ������� �������
		return;
	}
	if (a > t->data)//���� ������� ������ �� ��� �����
		if (t->right)//���� ���� �������� ����� ���������
			add(t->right, a);//���������� ���������� �� ��� ���� �����
		else//������
		{
			t->right = new Node;//�������� ���'��� �� �����
			t->right->left = t->right->right = NULL;//��������� ������� �������
			t->right->data = a;//�������� ���
		}
	else//���� ������� ������ �� ��� �����
		if (t->left)//���� ������ �������� ����� ���������
			add(t->left, a);//���������� ���������� �� ����� ���� �����
		else//������
		{
			t->left = new Node;//�������� ���'��� �� �����
			t->left->left = t->left->right = NULL;//��������� ������� �������
			t->left->data = a;//�������� ���
		}
}

void creatTree(Node* &t)
{
	ifstream file("Input.txt");//³�������� ���� ��� ����������
	int a;
	while (file.good())//���� ���� �� ������
	{
		file >> a;//������� ���
		add(t, a);//��������� ������� ��������� ����� � ����� ��� �������� �����
	}
	file.close();//������� ����
}

void modify(Node* &t)
{
	if (t->left || t->right)//���� �� ������ ������
	{
		if (t->left && t->right)//���� ���� � ������ ����� ���������
		{
			swap(t->left->data, t->right->data);//̳����� �� ��� ������
			modify(t->left);//���������� ������� ��� ����
			modify(t->right);//���������� ������� ����� ����
		}
		else//������
		{
			if (t->left)//���� ���� ����� �� ������
				modify(t->left);//���������� ������� ����
			else//������
				add(t->left, rand() % 10);//�������� � ����� ��������������� �����
			if (t->right)//���� ������ ����� �� ������
				modify(t->right);//���������� ������� ����
			else//������
				add(t->right, rand() % 10);//�������� � ����� ��������������� �����
		}
	}
}