#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

struct List//структура списку
{
	char *str;//елемент списку
	List *next;//покажчик на насупний елемент
};

void push(List*, char*);//Функція додавання елементів в список
List* readFile();//функція зчитування елементів з файлу
void OutputList(List*);//Функія введення списку
List* makeList();//функція ствоеня елементів з клавіатури
List* NewList(List *list, int n, int k);//Фукція ствоення додакового списку

int main()
{
	setlocale(LC_ALL, "ukr");

	List *list = NULL;//створюємо основиний список

	List *newlist = NULL;//створюємо допоміний список

	cout << "1.Побудувати однозв'язний список зчитавши данi з текстового файлу." << endl;
	cout << "2. Побудувати однозв'язний список ввiвши данi з клавiатури." << endl;
	int a = _getch();
	while (true)
	{
		if (a == 49)
		{
			list = readFile();//Сворення з файлу
			break;
		}
		if (a == 50)
		{
			list = makeList();//Створення з клавіатури
			break;
		}
		cout << "Некоректнй вибiр! Повторiть сробу.";//захист від помилкового введння
		a = _getch();
	}
	cout << endl;
	OutputList(list);//вивести основний список
	cout << "Введiть зачення номерів елементiв для нового списку: ";
	int n, k;//номери елементів для додаткового списку
	cin >> n;//вводимо номери елеметів додатовго списку
	cin >> k;

	newlist = NewList(list, n, k);//створємо додатковий список
	OutputList(newlist);//виводимо додатковий список
	system("Pause");
	return 0;
}

void push(List *list_, char *str)
{
	list_->next = new List;//Вділяємо пам'ять на елемент  
	list_->next->str = new char[100];
	strcpy_s(list_->next->str, 100, str);//Заповнєо його
	list_->next->next = NULL;//ініціалізуємо наступний елемент після створеного як пустим
}

void OutputList(List *list_)
{
	List *templist = list_;//сторюємо додаткоий покажчик типу спикау
	cout << templist->str << endl;//виводимо  улемент списку
	do {
		templist = templist->next;//Переходимо до наступного елементу
		cout << templist->str << endl;//Вводимо його
	} while (templist->next != NULL);//поки не дійдемо до кінця
}

List* readFile()
{
	char *str = new char[100];
	List *list = new List;//Виділяємо пам'ять на список 
	list->str = new char[100];
	strcpy_s(list->str, 100, "List:");
	List *list_ = list;
	list_->next = new List;
	//list_ = list_->next;
	ifstream fin("Input.txt");//Відкривамо файл
	while (fin.good())
	{
		fin.getline(str, 100);//Зчитуємо строку з файла
		push(list_, str);//Записуємо її в список
		list_ = list_->next;//Переміщуємо покажчик на насупний елемент
	}
	fin.close();//Закриваємо файл
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
		cout << "Введiть значння елемента списку: ";
		gets_s(str, 100);//Ввдимо з клавіатури елемен списку
		push(list_, str);//записуємо елемент в список
		cout << "Кiнець-ESC\n" << "Далi-Enter\n";
		int a = _getch();
		list_ = list_->next;
		if (a == 27) break;//виоимо з циклу ведення, якщо коисувач це захотів
	}
	return list;//повертаємо покажчик на список
}

List* NewList(List *list, int n, int k)
{
	List *newlist = new List;//Виділяємо пам'ять на елемент срписку
	newlist->str = new char[100];
	strcpy_s(newlist->str, 100, "New List:");
	List *list_ = newlist;
	list_->next = new List;
	int i = 0;
	char *str = new char[100];
	while (list->next != NULL)//проходимось по елементам основного списку
	{
		if (i >= n && i <= k)//яко цей еемент лежить між вказаними номерами
		{
			strcpy_s(str, 100, list->str);
			push(list_, str);//Додаємо даний елемент в новий список
			list_ = list_->next;//Переміщуємо покажчик допоміжг списку на насупний елемент
		}
		i++;
		list = list->next;//Переміщуємо покажчик головного списку на насупний елемент
	}
	return newlist;//повертаємо покажчик на допоміжний список
}