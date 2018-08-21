#include <iostream>
#include <fstream>

using namespace std;

int** creatArr(int n, int m);
int** distribution(int** arr, int n, int m, int t);//Функція розподілення зв'язків між компаніями

int main()
{
	setlocale(LC_ALL, "ukr");
	int n, m, k, t, ii, jj, i, j;
	ifstream fin("Input.txt");//Відкриваємо файл для зчитуання
	fin >> n;
	fin >> m;
	fin >> k;
	fin >> t;
	int** arr = creatArr(n, m);//Виділяємо пам'ять на матрицю інцидентності
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			arr[i][j] = 0;
	int **coord = creatArr(k, 2);//Виділяємо пам'ять на матрицю паросполучень
	for (i = 0; i < k; i++)
	{
		fin >> ii;
		fin >> jj;
		coord[i][0] = ii;
		coord[i][1] = jj;
		arr[ii-1][jj-1] = 1;//Змповнюємо матрицю інцидентності
	}
	fin.close();
	cout << "Матриця iнцидентностi: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << arr[i][j] << "  ";
		cout << endl;
	}

	int **check = distribution(arr, n, m, t);//Присвоюємо значення функції в маси розприділення ребер
	int *w = new int[n + m];//Виділяємо пам'ять для масиву нерівномірності способу
	int iw = 0;
	int max, min;
	int* company = new int[t + 1];//Виділяємо пам'ть для пудрахунку вершин, що належать компанії
	for (i = 0; i < n; i++)//Проходимо по рядках матриці інцидентності
	{
		for (int r = 0; r < t + 1; r++)
			company[r] = 0;
		for (j = 0; j < m; j++)//Проходимось по стовпцях
			company[check[i][j]]++;//Підраховуємо кількість сполучених ребер в рядку
		max = company[1];//Пошук вершини з максимальною кількістю ребер
		for (int g = 2; g < t + 1; g++)
			if (company[g] > max)
				max = company[g];
		min = company[1];//Пошук вершини з мінімальною кількістю ребер
		for (int g = 2; g < t + 1; g++)
			if (company[g] < max)
				min = company[g];
		w[iw++] = max - min;//Масив нерівномірності способу для кожої з вершин
	}
	for (i = 0; i < m; i++)//Проходимо по стовпцям
	{
		for (int r = 0; r < t + 1; r++)	 
			company[r] = 0;
		for (j = 0; j < n; j++)//Проходимо по рядках
			company[check[j][i]]++;//Підраховуємо кількість сполучених ребер в стовпці
		max = company[1];
		for (int g = 2; g < t + 1; g++)//Пошук вершини з максимальною кількістю ребер
			if (company[g] > max)
				max = company[g];
		min = company[1];
		for (int g = 2; g < t + 1; g++)//Пошук вершини з мінімальною кількістю ребер
			if (company[g] < max)
				min = company[g];
		w[iw++] = max - min;//Масив нерівномірності способу для кожої з вершин
	}
	int wsum = 0;
	for (i = 0; i < n + m; i++)
		wsum += w[i];//Знаходио загальну нерівномірність способу
	cout << "Матриця розподiлення : " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << check[i][j] << "  ";
		cout << endl;
	}
	ofstream fout("Output.txt");
	fout << wsum << endl;//Записуємо отримані дані в файл
	for (i = 0; i < k; i++)
		fout << check[coord[i][0]-1][coord[i][1]-1] << "  ";
	fout.close();
	system("Pause");
	return 0;
}

int** distribution(int** arr, int n, int m, int t)
{
	int* company = new int[t+1];//Виділяємо пам'ять на масив для запсу туди кількості поточнх з'язків відповідним користувачам
	int i, j;
	for(i = 0; i < t+1; i++)
		company[i] = 0;//Початкове значення заповнення рівне 0
	int** check = creatArr(n, m);//Виділяємо пам'ять на масив для запису розприділених вершин
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			check[i][j] = 0;
	for (i = 0; i < n; i++)//Проходимо по рядкам
		for (j = 0; j < m; j++)//проходимо по вершинам
			if (arr[i][j])//Якщо між даними вершинами є зв'язок
			{
				if (!check[i][j])//Якщо даний зв'язок не розпреділений
				{
					for (int ii = 0; ii < m; ii++)
						company[check[i][ii]]++;//Заповнюємо масив розпреділених вершин в даному рядку
					for (int ii = 0; ii < n; ii++)
						company[check[ii][j]]++;//Заповнюємо масив розпреділених вершин в даному стовпці
					int min = company[1];
					int minindex = 1;//Знаходимо індекс компанії, якому раціонально передати зв'язок
					for(int ii=2; ii<t+1; ii++)
						if (company[ii] < min)
						{
							min = company[ii];
							minindex = ii;
						}
					check[i][j] = minindex;//Позначаємо даний зв'язок як відвідуаний
					for (int ii = 0; ii < t + 1; ii++)
						company[ii] = 0;
				}
			}
	return check;//Повертаємо масив розподілених вершин
}

int** creatArr(int n, int m)//Функція для видіення пам'яті на масив nxm
{
	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];
	return arr;
}