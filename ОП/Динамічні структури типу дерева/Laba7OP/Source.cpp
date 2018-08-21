
#include <iostream>
#include <fstream>

using namespace std;

struct Node //Структура вузла дерева
{
	int data;//Дані вузла дерева
	Node *left;//Покажчик на ліву гілку
	Node *right;//Покажчик на праву гілку
};

void creatTree(Node* &t);//Функція створення дерева, на основі даних з файлу
void add(Node* &t, int a);//Функція запису вузла дерева
void print(Node *&t, int u);//Функція виведення дерева
void modify(Node* &t);//Функція модифікації дерева

int main()
{
	Node* tree = NULL;//Оголошуємо покажчик на дерево
	creatTree(tree);//Заповнюємо дерево
	print(tree, 0);//Виводимо дерево
	modify(tree);//Змінюємо дерево
	cout << endl << endl << endl << endl;
	print(tree, 0);//Виводимо модифіковане дерево
	system("Pause");
	return 0;
}

void print(Node *&t, int u)
{
	if (t == NULL) return;//Якщо вузол-NULL-виходимо
	print(t->left, ++u);//Рекурсивно відвідуємо ліву гілку дерева
	for (int i = 0; i < u; i++)
		cout << "          ";
	cout << t->data << endl;//Виводимо дані вузла
	u--;
	print(t->right, ++u);//Рекурсивно відвідуємо праву гілку дерева
}

void add(Node* &t, int a)
{
	if (t == NULL)//Якщо корінь пустий
	{
		t = new Node;//Виділяємо пам'ять на вузол
		t->data = a;//Записуємо дані
		t->left = t->right = NULL;//Оголошуємо потомків пустими
		return;
	}
	if (a > t->data)//Якщо елемент менший за дані вузла
		if (t->right)//якщо лівий похідний вузол заповнено
			add(t->right, a);//Рекурсивно переходимо на ліву гілку вузла
		else//інакше
		{
			t->right = new Node;//Виділяємо пам'ять на вузол
			t->right->left = t->right->right = NULL;//Оголошуємо потомків пустими
			t->right->data = a;//Записуємо дані
		}
	else//Якщо елемент більший за дані вузла
		if (t->left)//якщо правий похідний вузол заповнено
			add(t->left, a);//Рекурсивно переходимо на праву гілку вузла
		else//інакше
		{
			t->left = new Node;//Виділяємо пам'ять на вузол
			t->left->left = t->left->right = NULL;//Оголошуємо потомків пустими
			t->left->data = a;//Записуємо дані
		}
}

void creatTree(Node* &t)
{
	ifstream file("Input.txt");//Відкриваємо файл для зчитування
	int a;
	while (file.good())//Поки файл не пустий
	{
		file >> a;//Зчитуємо дані
		add(t, a);//Викликаємо функцію додавання даних в вузли для зчитаних даних
	}
	file.close();//Закрити файл
}

void modify(Node* &t)
{
	if (t->left || t->right)//Якщо не листок дерева
	{
		if (t->left && t->right)//Якщо лівий і правий вузол запевнено
		{
			swap(t->left->data, t->right->data);//Міняємо їх дані місцями
			modify(t->left);//Рекурсивно відвідуємо ліву гілку
			modify(t->right);//Рекурсивно відвідуємо праву гілку
		}
		else//інакше
		{
			if (t->left)//Якщо лівий вузол не пустий
				modify(t->left);//Рекурсивно відвідуємо його
			else//інакше
				add(t->left, rand() % 10);//Записуємо в нього псевдовипадкове число
			if (t->right)//Якщо правий вузол не пустий
				modify(t->right);//Рекурсивно відвідуємо його
			else//інакше
				add(t->right, rand() % 10);//Записуємо в нього псевдовипадкове число
		}
	}
}