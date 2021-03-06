#include <iostream>
#include <ctime>
#include <algorithm> 
#include <stdlib.h>
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

/*
Нулевая лаба по саоду 3-й семестр
Тема: Построение двоичного дерева. Вычисление характеристик дерева.

Цель работы: Освоить понятие двоичного дерева.

Порядок выполнения работы:
1.Разместить в памяти компьютера данное двоичное дерево (см. ниже, номер задания соответствует последней цифре шифра), данные в вершинах заполнить случайными числами. 
2.Написать процедуры для вычисления размера дерева, высоты дерева, средней высоты дерева, контрольной суммы для дерева и проверить их работу на конкретном примере. 
3.Запрограммировать обход двоичного дерева слева направо и вывести на экран получившуюся последовательность данных.


картинка в файле на директорию выше
*/
using namespace std;

struct Vertex
{
	int data;
	Vertex* left;
	Vertex* right;
};

Vertex *NewNode(int data)
{
	
	data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void tree5(Vertex* &p)
{
	p = NewNode(rand() % 50);
	p->left = NewNode(rand() % 50);
	p->left->left = NewNode(rand() % 50);
	p->left->right = NewNode(rand() % 50);

	p->right = NewNode(rand() % 50);
	p->right->right = NewNode(rand() % 50);

}

int sizeoftree(Vertex* p, int &count)
{
	if (p == NULL) count = 0;
	else count = 1 + sizeoftree(p->left, count) + sizeoftree(p->right, count);
	return count;
}

int max(int a, int b) {
	if (a > b)return a;
	else return b;
}

int htree(Vertex* p, int &count)
{
	if (p == NULL) count = 0;
	else count = 1 + max(htree(p->left, count), htree(p->right, count));
	return count;
}

int medsizetree(Vertex* p, int L, int &count)
{
	if (p == NULL) count = 0;
	else count = L + medsizetree(p->left, L + 1, count) + 
		medsizetree(p->right, L + 1, count);
	return count;
}

void leftright(Vertex *p)
{
	if (p)
	{
		leftright(p->left);
		printf("%d ", p->data);
		leftright(p->right);
	}
}
int sum(Vertex *p, int &count)
{
	if (p == NULL) count = 0;
	else count = p->data + sum(p->left, count) + sum(p->right, count);
	return count;
}

int main()
{
	srand(time(NULL));
	int count = 0;
	Vertex *root = new Vertex;
	tree5(root);
	cout << "sizeoftree = " << sizeoftree(root, count) << endl;
	cout << "htree = " << htree(root, count) << endl;
	count = sizeoftree(root, count);
	float med = (float)medsizetree(root, 1, count) / (float)sizeoftree(root, count);
	cout << "medsizetree = " << med << endl;
	cout << "sum = " << sum(root, count) << endl;
	leftright(root);
	system("pause");
	return 0;
}
