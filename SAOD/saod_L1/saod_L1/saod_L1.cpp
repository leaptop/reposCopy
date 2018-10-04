// saod_L1.cpp : Defines the entry point for the console application.
//
/*Лабораторная работа №1

1). Разработать процедуру построения идеально сбалансированного дерева поиска (ИСДП).
2). Построить ИСДП из 100 вершин, распечатать обход дерева слева направо.
3). Для построенного дерева вычислить размер, контрольную сумму, высоту и среднюю высоту.

4). Дополнительное задание (на 5+):
Реализовать графическую процедуру изображения дерева на экране.*/

#include "stdafx.h"
#include <math.h>
struct Vertex
{
	int data;
	Vertex* left;
	Vertex* right;
};

Vertex* ISDP(int L, int R, int *a) {
	int m = 0;
	if (L > R)return NULL;
	else m = ceil((L + R)/ (double) 2);
	Vertex *p = new Vertex;
	printf("a vot i chislo m = %d\n", m);
	p->data = a[m];
	p->left = ISDP(L, m-1, a);
	p->right = ISDP(m + 1, R, a);
	printf("p->data = %d\n", p->data);
	return p;

}

int main()
{
	int a[] = { 100, 3, 23, 15,39, 70 };
	/*int m = ceil((5 + 8) / (double)3);
	printf("%d", m);
	getchar();*/
	ISDP(2, 5, a);
	getchar();
    return 0;
}

