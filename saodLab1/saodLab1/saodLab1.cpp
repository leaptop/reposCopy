#include "stdafx.h"
#include <time.h>
#include<stdlib.h>// for srand
#include <iostream>
#include<conio.h>//for _getch()
#include<clocale>

using namespace std;
int m = 0, c = 0;
void FillInc(int *a, int n) {

	if (n > 0) a[0] = rand() % 100; else return;
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i - 1] + rand() % 100;
	}
}
void FillDec(int *a, int n) {
	if (n > 0) a[0] = rand() % 100; else return;
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i - 1] - rand() % 100;
	}
}
void FillRand(int *a, int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;

	}
}
int CheckSum(int*a, int n) {// подсчёт контрольной суммы
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	printf("Контрольная сумма: %d", sum); return sum;
}

int RunNumber(int*a, int n) {//подсчёт серий
	int x = 0, k = 0;
	if (n > 1) {
		k++;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] <= a[i + 1]) {
				//x = 1;
			}
			else k++;
		}// В конце 
		printf("Количество серий: %d", k); return k;
	}
	else { printf("Количество серий: %d", k); return 1; }
}
void PrintMas(int*a, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}//printf("\n");
}
/*3). Предусмотреть подсчет фактического количества пересылок и сравнений (М и С),
сравнить с теоретическими оценками, полученными по формулам М=3(n-1), С=(n^2-n)\2.*/
void SelectSort(int *a, int n, int &m, int &c) {
	int mf = 3 * (n - 1), cf = (n*n - n) / 2;
	for (int i = 0; i < n - 1; i++)
	{
		for (int q = i + 1; q < n; q++)
		{
			c++;
			if (a[i] > a[q]) {
				
			}
		}
		m += 3;
	}
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int q = i + 1; q < n; q++)
		{
			if (a[i] > a[q]) {
				min = q;
			}
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}


	printf("m = %d, c = %d, m по формулам = %d, c по формулам = %d ", m, c, mf, cf);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int *a, n = 25;
	a = new int[n];
	//FillInc(a, n);
	//PrintMas(a, n);
	//cout << RunNumber(a, n) << endl;// CheckSum(a, n);
	//FillDec(a, n);
	//PrintMas(a, n);
	//cout << RunNumber(a, n) << endl;
	//for (int i = 0; i < 10; i++)
	//{
	//	FillRand(a, n);
	//	PrintMas(a, n);
	//	cout << RunNumber(a, n)<<endl<<endl;
	//}
	for (int i = 0; i < n; i++)
	{

		FillRand(a, n);
		PrintMas(a, n);
		cout << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		SelectSort(a, n, m, c);
		m = 0; c = 0;
		cout << endl;
		PrintMas(a, n);
		cout << endl;
		CheckSum(a, n);
		cout << endl;
		RunNumber(a, n);
		cout << endl;
		cout << endl;
	}
	_getch();
	return 0;
}

/*Лабораторная работа № 1

1). Дан массив А из n целых чисел.
Разработать шесть сервисных процедур, которые будут использованы в следующих лабораторных работах:
a) процедуру FillInc, заполняющую массив А возрастающими числами.
b) процедуру FillDec, заполняющую массив А убывающими числами.
c) процедуру FillRand, заполняющую массив А случайными числами.
d) функцию CheckSum для подсчета контрольной суммы элементов массива А.
e) функцию RunNumber  для подсчета серий в массиве А.
f) процедуру PrintMas для вывода  на  экран  элементов  массива А.

Массив А и кол-во n – параметры процедур !!!
*/
/*2). Экспериментально определить:
• кол-во серий в возрастающем массиве
• кол-во серий в убывающем массиве

Определение.  Серией называется неубывающая последовательность максимальной длины.
Пример:  23145314  23  145  3  14   т.е. 4 серии

3).  Дополнительное задание (на 5+):
Экспериментально определить среднюю длину серии в случайном массиве.*/

//int RunNumber(int*a, int n) {// Здесь сделано не так, как надо. Здесь я считаю только серии из нескольких чисел, а надо считать даже и числа не входящие в цепочку.
//	int x = 0, k = 0;
//	if (a[0] < a[1]) x = 1; else x = 0;
//	for (int i = 1; i < n - 1; i++)
//	{
//		if (a[i] <= a[i + 1]) {
//			x = 1;
//			//continue;
//		}
//		else { k += x; x = 0; }
//		if (a[i] == n - 1)k += x;//Это я пробую исправить ситуацию, когда в конце было 90 70 70 и эта последняя серия не посчиталась
//	}return k;
//}