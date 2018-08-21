#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int n = 10000;



struct Data
{
	string key;
	string translation;
};

struct Element
{
	Data data;
	Element *next;
};

struct List
{
	Element* head;
	int k;
};

struct HashTable
{
	List** table;
	int kol;
};

HashTable* hashTable();
List* list();
void readFile(HashTable* English, HashTable* Ukraine);
void addList(List* list, string original, string translation);
int HashFunc(string word);

int main()
{
	setlocale(LC_ALL, "ukr");
	HashTable* English = hashTable();
	HashTable* Ukraine = hashTable();
	readFile(English, Ukraine);
	string str = "Hello";
	int key = HashFunc(str);
	cout << "TOP PROVERKA(VAZNO)" << endl;
	cout << English->table[key]->head->data.key << "    0    " << English->table[key]->head->data.translation << endl;
	str = "Îáëè÷÷ÿ";
	key = HashFunc(str);
	cout << "TOP PROVERKA(VAZNO)2" << endl;
	cout << Ukraine->table[key]->head->data.key << "    0    " << Ukraine->table[key]->head->data.translation << endl;
	system("Pause");
	return 0;
}

HashTable* hashTable()
{
	HashTable* Table = new HashTable;
	Table->table = new List*[n];
	for (int i = 0; i < n; i++)
		Table->table[i] = list();
	Table->kol = 0;
	return Table;
}

List* list()
{
	List* list = new List;
	list->k = 0;
	list->head = 0;

	return list;
}

int HashFunc(string word)
{
	int number = 0;
	int leg = word.length();
	const char* str = word.c_str();
	for (int i = 0; i < leg; i++)
		number += (int)str[i];
	return abs(number % n);
}

void addList(List* list, string original, string translation)
{
	Element* elem = list->head;
	Element* newelem = new Element;
	newelem->data.key = original;
	newelem->data.translation = translation;
	newelem->next = 0;

	if (!elem)
	{
		list->head = newelem;	
		list->k++;
		return;
	}

	while (elem->next)
		elem = elem->next;
	elem->next = newelem;
	list->k++;
}

void readFile(HashTable* English, HashTable* Ukraine)
{
	ifstream fin("Vocabulary.txt");
	string word1, word2;
	while (fin.good())
	{
		fin >> word1;
		fin >> word2;
		cout << word1 << "    =    " << word2 << endl;
		int key1 = HashFunc(word1);
		int key2 = HashFunc(word2);
		addList(English->table[key1], word1, word2);
		addList(Ukraine->table[key2], word2, word1);
	}
}