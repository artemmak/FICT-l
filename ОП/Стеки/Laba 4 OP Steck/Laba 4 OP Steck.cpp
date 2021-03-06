// Laba 4 OP Steck.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <conio.h>

using namespace std;

struct Element
{
	char *str;
	int left;
	int rights;
	Element *next;
};
struct Stack
{
	Element *elem;
	int leght;
};

void push(Stack*, char*, int, int);//Додати елемент в стек
void OutputStack(Stack*);//Вивести стек
char* readFile();//Прочитати файл
void creatStack(Stack*);//Створити стек
int menu();//Меню
void inputFile();//Ввести дані в файл
void pop(Stack *stack);//Видалити елемент стеку

int main()
{
	setlocale(LC_ALL, "ukr");
	Stack *stack = new Stack;//ВИділяємо динамічну пам'ять на стек
	stack->elem = NULL;
	stack->leght = 0;
	int a = 0;
	while (a != 53)
	{
		a = menu();
		switch (a)
		{
		case 49://Вводимо дані в файл
		{
			inputFile();
			stack->elem = NULL;
			stack->leght = 0;
			break;
		}
		case 50://створюємо стек
		{
			creatStack(stack);
			break;
		}
		case 51://Вивести стек
		{
			OutputStack(stack);
			pop(stack);
			break;
		}
		case 52://створити і вивести стек
		{
			creatStack(stack);
			OutputStack(stack);
			break;
		}
		case 53://вихід з програми
			break;
		default:
		{
			printf("Некоректре введення.");
			cout << endl;
		}
		case 54:
		{
			pop(stack);
		}
		}
	}
	system("Pause");
	return 0;
}


void push(Stack* stack, char* str, int left, int rights)
{
	Element *tempElement = new Element;
	tempElement->next = stack->elem; 
	tempElement->str = new char[100];	
	int n = strlen(str);
	for (int i = 0; i < n; i++)//запис масиву даних стеку
		tempElement->str[i] = str[i];
	tempElement->str[n] = '\0';
	tempElement->left = left;//запис координат в стек
	tempElement->rights = rights;
	stack->elem = tempElement;
	stack->leght++;//збільшити дкількість елементів стеку
}	


void OutputStack(Stack *stack)
{
	Element *element = stack->elem;
	for (int i = 0; i < stack->leght; i++)
	{
		cout << "Частина тексту: " << element->str;//вивести лексему
		cout << endl;
		cout << "Позицiї тексту: " << element->left << ' ' << element->rights << endl;//вивести координати дужок
		element = element->next;
	}
}

void pop(Stack *stack)
{
	Element *stackElem = stack->elem;
	stack->elem = stackElem->next;
	stack->leght--;//Зменшити кількість елементів стеку
	delete[] stackElem->str;//видалення пам'яті під масив символів
	delete stackElem;//видалення пам'яті під елемент стеку
}


char* readFile()
{
	ifstream file("Text.txt");
	char*str = new char[100];
	file.getline(str, 100);//зчитати строку з файлу
	file.close();
	return str;//Повернути значення зчитаної строки функції
}

void creatStack(Stack* stack)
{
	char* str = readFile();//прочитати файл
	int n = strlen(str);

	for (int i = 0; i < n; i++)
	{
		int left = 0;//Координата лівої душки
		int rights = 0;//Координата правої душки
		if (str[i] == '(')
		{
			left = i+1;
			int counter = 1;//Підрахунок кількості відкритих дужок
			char *temp = new char[100];
			int k = 0;
			for (int j = i + 1; j < n; j++)
			{
				if (str[j] == '(')
					counter++;	
				if (str[j] == ')')
				{
					counter--;
					rights = j+1;
				}
				if (!counter)
					break;
				temp[k] = str[j];
				k++;
			}
			temp[k]='\0';
			push(stack, temp, left, rights);//Запис даних в стек
			delete[] temp;
		}
	}
}

void inputFile()
{
	ofstream finput("Text.txt");
	char *str = new char[100];
	cout << "Введiть данi в файл: ";
	gets_s(str, 100);
	finput << str;//Запис даних в файл
	finput.close();
}

int menu()
{
	int n;
	cout << endl;
	cout << "Виберiть потрiбний пункт з меню." << endl;
	cout << "1. Ввести новi данi в файл." << endl;
	cout << "2. Побудувати стек." << endl;
	cout << "3. Надрукувати значення елементiв стеку та номери позицiй в текстi кожної пари дужок." << endl;
	cout << "4. Побудувати стек та надрукувати значення елементiв стеку та номери позицiй в текстi кожної пари дужок." << endl;
	cout << "5. Завершити програму." << endl;
	n = _getch();
	cout << endl;
	return n;//Повертаємо значення вибору користувача
}