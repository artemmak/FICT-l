#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

struct list_of_elements
{
	int x;
	list_of_elements *next, *previous;
};

struct List
{
	list_of_elements *head;
	int size;
};

struct hash_
{
	List **arr;
	int n, kol;
};

struct findpair
{
	int el1, el2;
};

List* create_list()
{
	List *list = new List;
	list->head = 0;
	list->size = 0;
	return list;
}

list_of_elements* create(int x)
{
	list_of_elements *element = new list_of_elements;
	element->next = 0;
	element->previous = 0;
	element->x = x;
	return element;
}

int mod1(int k, int m)
{
	return k % m;
}

int mult1(int k, int m)
{
	long double A = (sqrt(5) - 1) / 2;
	return m * fmod(k * A, 1);
}

void add_last(List *list, list_of_elements *listofel)
{
	list_of_elements *element = list->head;
	if (!element)
	{
		list->head = listofel;
		return;
	}
	while (element->next)
	{
		element = element->next;
	}
	element->next = listofel;
	++list->size;
}

hash_* create_hash_table(int n, int m)
{
	hash_ *t = new hash_;
	t->n = n;
	t->kol = 0;
	t->arr = new List*[n];
	for (int i = 0; i < n; ++i)
		t->arr[i] = create_list();
	return t;
}

void insert_mod(hash_ *table, int k)
{
	int key = mod1(k, table->n);
	if (table->arr[key]->head)
		++table->kol;
	add_last(table->arr[key], create(k));
}

void insert_mult(hash_ *table, int k)
{
	int key = mult1(k, table->n);
	if (table->arr[key]->head)
		++table->kol;
	add_last(table->arr[key], create(k));
}

void fill_table(hash_ *table, int *a, int n, void(*func)(hash_*, int))
{
	for (int i = 0; i < n; ++i)
		func(table, a[i]);
}

findpair* search(hash_ *t, int *a, int n, int s, int(*func)(int, int))
{
	findpair *el12 = new findpair;
	int w;
	list_of_elements *el;
	for (int i = 0; i < n; ++i)
	{
		w = s - a[i];
		if (w < 0)
			continue;
		int key = func(w, t->n);
		if (!t->arr[key])
			continue;
		el = t->arr[key]->head;
		if (!el)
			continue;
		do
		{
			if (el->x == w)
			{
				el12->el1 = s - w;
				el12->el2 = w;
				return el12;
			}
			el = el->next;
		} while (el);
	}
	el12->el1 = 0;
	el12->el2 = 0;
	return el12;
}

void output(int kol, findpair **el12, int n)
{
	ofstream f("output.txt");
	f << kol << "\n";
	for (int i = 0; i < n; ++i)
		f << el12[i]->el1 << " " << el12[i]->el2 << "\n";
	f.close();
}
