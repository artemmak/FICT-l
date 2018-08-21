#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

using namespace std;

const int STR_SIZE = 255;

int metod;

struct ListElement
{
	int x;
	ListElement
		*next,
		*prev;
};

ListElement* createListElement(int x)
{
	ListElement *element = new ListElement;

	element->next = 0;
	element->prev = 0;
	element->x = x;

	return element;
}

struct List
{
	ListElement *head;
	int length;
};

List* createList()
{
	List *list = new List;

	list->head = 0;
	list->length = 0;

	return list;
}


void addLast(List *list, ListElement *listElement)
{
	ListElement *el = list->head;

	if (!el)
	{
		list->head = listElement;
		return;
	}	

	while (el->next)
	{
		el = el->next;
	}

	el->next = listElement;
	++list->length;
}

struct HashTable
{
	List **arr;
	int n,
		kol;
};

HashTable* createHashTable(int n)
{
	HashTable *t = new HashTable;

	t->n = n;
	t->kol = 0;
	t->arr = new List*[n];

	for (int i = 0; i < n; ++i)
	{
		t->arr[i] = createList();
	}

	return t;
}

int divHF(int k, int m)
{
	return k % m;
}

int HFMN(int k, int m)
{
	long double A = (sqrt(5) - 1) / 2;
	return m * fmod(k * A, 1);
}



void insertDiv(HashTable *table, int k)
{
	int key;
	if (metod == 1)
		key = divHF(k, table->n);
	else
		key = HFMN(k, table->n);

	if (table->arr[key]->head)
	{
		++table->kol;
	}

	addLast(table->arr[key], createListElement(k));
}

struct Data
{
	int *a;
	int *s;
	int n;
	int	m;
};

Data* readFile(const char *fileName)
{
	ifstream file(fileName);

	if (!file.good())
		return 0;

	Data *d = new Data;

	file >> d->n >> d->m;

	d->a = new int[d->n];
	d->s = new int[d->m];

	for (int i = 0; i < d->n; ++i)
		file >> d->a[i];

	for (int i = 0; i < d->m; ++i)
		file >> d->s[i];

	file.close();

	return d;
}

void addElemHashTable(HashTable *table, int *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		insertDiv(table, a[i]);
	}
}

struct REZ
{
	int x, y;
};

REZ* serchElemSum(HashTable *t, int *a, int n, int s)
{
	REZ *rez = new REZ;
	int c;
	ListElement *el;

	for (int i = 0; i < n; ++i)
	{
		c = s - a[i];

		if (c < 0)
			continue;

		int key;
		if (metod == 1)
			key = divHF(c, t->n);
		else
			key = HFMN(c, t->n);
		if (!t->arr[key])
			continue;

		el = t->arr[key]->head;

		if (!el)
			continue;

		do
		{
			if (el->x == c)
			{
				rez->x = s - c;
				rez->y = c;
				return rez;
			}
			el = el->next;
		} while (el);

	}

	rez->x = 0;
	rez->y = 0;

	return rez;
}

void writeFile(int kol, REZ **rez, int n)
{
	ofstream file("maksakov_is-71.txt");

	if (!file.good())
		return;

	file << kol << "\n";

	for (int i = 0; i < n; ++i)
	{
		file << rez[i]->x << " " << rez[i]->y << "\n";
	}

	file.close();
}

int main()
{
	setlocale(LC_ALL, "ukr");
	cout << "Введіть ім'я файлу: ";
	char *fileName = new char[STR_SIZE];
	int n, m, *a = 0, *s = 0;
	cin >> fileName;
	cout << endl;
	Data *inp = readFile(fileName);

	delete[]fileName;

	cout << "1. Метод діленя." << endl;
	cout << "2. Метод множення" << endl;

	cin >> metod;

	if (!inp)
		return 0;

	a = inp->a;
	s = inp->s;
	n = inp->n;
	m = inp->m;

	REZ **rez = new REZ*[m];

	HashTable * t = createHashTable(n * 3);
	addElemHashTable(t, a, n);

	for (int i = 0; i < m; ++i)
	{
		rez[i] = serchElemSum(t, a, n, s[i]);
	}


	int kol = t->kol;

	writeFile(kol, rez, m);

	delete[]inp->a;
	delete[]inp->s;
	delete inp;

	system("pause");

	return 0;
}