// saod_L2a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cstdio>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

const int n = 100;
int A[n];

struct Vertex
{
	int data;
	Vertex *left;
	Vertex *right;
} *root, *rootS, *rootS1;

Vertex *NewNode(int data)
{
	Vertex *p = new Vertex;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

Vertex *ISDP(int l, int r)
{
	if (l > r)
		return NULL;
	int m = (l + r) / 2;
	Vertex *p = NewNode(A[m]);
	p->left = ISDP(l, m - 1);
	p->right = ISDP(m + 1, r);
	return p;
}

void SDPAdd(int D, Vertex*& root)
{
	Vertex** p = &root;
	while ((*p) != NULL)
	{
		if (D < (*p)->data) p = &((*p)->left);
		else if (D >(*p)->data) p = &((*p)->right);
		else break;
	}
	if ((*p) == NULL)
	{
		(*p) = new Vertex;
		(*p)->data = D;
		(*p)->left = NULL;
		(*p)->right = NULL;
	}
}

void SDPREC(int D, Vertex *&p)
{
	if (!p)
	{
		p = new Vertex;
		p->data = D;
		p->left = NULL;
		p->right = NULL;
	}
	else if (D < p->data) SDPREC(D, p->left);
	else if (D > p->data) SDPREC(D, p->right);

}



void Print(Vertex *p)
{
	if (p)
	{
		Print(p->left);
		printf("%d ", p->data);
		Print(p->right);
	}
}

void FillInc()
{
	for (int i = 0; i < n; i++)
		A[i] = rand() % n;
}

void PrintMas() {
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
}

int sizeoftree(Vertex* p, int &count)
{
	if (p == NULL) count = 0;
	else count = 1 + sizeoftree(p->left, count) + sizeoftree(p->right, count);
	return count;
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
	else count = L + medsizetree(p->left, L + 1, count) + medsizetree(p->right, L + 1, count);
	return count;
}
int sum(Vertex *p, int &count)
{
	if (p == NULL) count = 0;
	else count = p->data + sum(p->left, count) + sum(p->right, count);
	return count;
}

void print_Tree(Vertex *p, int level)
{
	if (p)
	{
		print_Tree(p->left, level + 1);
		for (int i = 0; i< level; i++) cout << "   ";
		cout << p->data << endl;
		print_Tree(p->right, level + 1);
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	cout << "ISDP";
	root = NULL;
	FillInc();
	root = ISDP(0, n - 1);
	cout << "\nОбход дерева ->:  \n" << endl;
	Print(root);
	cout << " \n" << endl;
	int count = 0;

	cout << "SDP\n";
	rootS = new Vertex;
	rootS->data = A[0];
	rootS->left = NULL;
	rootS->right = NULL;

	PrintMas();
	cout << "\n";
	for (int i = 1; i < n; i++)
		SDPREC(A[i], rootS);
	cout << "\nSDPREC Обход дерева -> :  \n" << endl;
	Print(rootS);

	rootS1 = new Vertex;
	rootS1 = NULL;

	for (int i = 0; i < n; i++)
		SDPAdd(A[i], rootS1);
	cout << "\nSDPAdd Обход дерева -> :  \n" << endl;
	Print(rootS1);
	cout << " \n" << endl;

	printf("n=100  | Размер | Контр.сумма | Высота | Средн.высота |\n");
	printf("-------|--------|-------------|--------|--------------|\n");
	printf("  ИСДП |%8d|%13d|%8d|%14.2f|\n", sizeoftree(root, count), sum(root, count), htree(root, count), (float)medsizetree(root, 1, count) / (float)sizeoftree(root, count));
	count = 0;
	printf("  СДП  |%8d|%13d|%8d|%14.2f|\n", sizeoftree(rootS, count), sum(rootS, count), htree(rootS, count), (float)medsizetree(rootS, 1, count) / (float)sizeoftree(rootS, count));
	printf("  СДП  |%8d|%13d|%8d|%14.2f|\n", sizeoftree(rootS1, count), sum(rootS1, count), htree(rootS1, count), (float)medsizetree(rootS1, 1, count) / (float)sizeoftree(rootS1, count));


	system("pause");
	return 0;
}
