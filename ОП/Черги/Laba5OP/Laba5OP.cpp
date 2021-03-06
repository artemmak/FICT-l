// Laba5OP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

struct ElementQueue //структура даних черги
{
	ElementQueue *next;
	int priotitet;
	char *str;
};

struct Queue // структура черги
{
	ElementQueue *head;
	ElementQueue *last;
	int length;
};

struct File // структура даних файлу
{
	char **str;
	int *arr;
	int n;
};

void createQueue();//функція сортування даних і виклику функції додавання даних в чергу
void pop(Queue*queue);//функція видалення даних з черги
File* readFile();//функція зчитування даних з файлу
void push(Queue *queue, char* str, int prioritet);//функція додавання даних в чергу
void OutputFile(); //функція виведення даних з файлу
void OutputQueue(Queue *queue);//функція виведення черги


int main()
{
	setlocale(LC_ALL, "ukr");
	OutputFile();//вивести файл
	createQueue();//створити чергу
	system("Pause");
	return 0;
}

void push(Queue *queue, char* str, int prioritet)
{
	ElementQueue *tempElement = new ElementQueue;
	tempElement->str = new char[100];//виділити динамічну пам'ять на масив символів
	tempElement->next = 0;
	strcpy_s(tempElement->str, 100, str);//записати масив символів в чергу
	tempElement->priotitet = prioritet;//записати пріоретет операції в чергу
	queue->length++;

	if (queue->last)
	{
		queue->last->next = tempElement;
		queue->last = queue->last->next;
		return;
	}
	if (!queue->head)
	{
		queue->head = tempElement;
		queue->last = queue->head;
	}
}

void pop(Queue*queue)
{
	ElementQueue* tempElement = queue->head;//створити покажчик на голову списку
	queue->head = tempElement->next;//переініціалізувати покажчик голови на покажчик наступного елементу
	queue->length--;//зменшити кількість елементів
	delete[] tempElement->str;//видалити динамічну пам'ять, виділену на масив символів
	delete tempElement;//видалити динамічну пам'ять  виділену на елемент черги
}

void OutputQueue(Queue *queue)
{
	ElementQueue *element = queue->head;
	if (queue->length == 0)//перевірки чи не являється черга пустою
	{
		cout << "Черга є пустою!!!" << endl;
		return;
	}
	cout << "Вмiст черги: " << endl;
	for (int i = 0; i < queue->length; i++)//вивести поелементно дані з черги
	{
		cout << element->priotitet << " " << element->str << endl;
		element = element->next;
	}
}

File* readFile()
{
	File *data = new File;
	ifstream fin("Input.txt");//Зчитати дані з файлу і записати їх в структуру даних файлу
	char *line = new char[5];
	fin.getline(line, 4);
	int n = atoi(line);
	data->n = n;
	data->arr = new int[data->n];
	data->str = new char*[n];
	for (int i = 0; i < n; i++)
		data->str[i] = new char[100];
	int i = 0;
	while (fin.good())
	{
		fin.getline(line, 5);
		data->arr[i] = atoi(line);
		fin.getline(data->str[i++], 100);
	}
	fin.close();
	return data;
}

void OutputFile()
{
	File *data = readFile();
	if (data->n)
	{
		cout << "Вмiст файлу: " << endl;
		for (int i = 0; i < data->n; i++)//вивести дані файлу
		{
			cout << data->arr[i] << "  " << data->str[i] << endl;
		}
	}
}

void createQueue()
{
	File *data = readFile();
	Queue *queue = new Queue;
	queue->head = NULL;
	queue->last = NULL;
	queue->length = 0;
	for (int i = 1; i < data->n; i++)//сортування вставками
	{
		int j = i - 1;
		while (data->arr[j] > data->arr[j + 1] && j >= 0)
		{
			swap(data->arr[j], data->arr[j + 1]);
			swap(data->str[j], data->str[j + 1]);
			j--;
		}
	}
	for (int i = 0; i < data->n; i++)
		push(queue, data->str[i], data->arr[i]);
	OutputQueue(queue);//вивести чергу
	pop(queue);
	OutputQueue(queue);//вивести чергу
}


