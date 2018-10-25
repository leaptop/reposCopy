// saod_L3.cpp : Defines the entry point for the console application.
//
/*
Лабораторная работа №3

1). Разработать процедуру удаления из случайного дерева поиска (СДП) вершины с заданным ключом.
2). Реализовать удаление из СДП  10 вершин, задаваемых с клавиатуры, 
распечатывать обход дерева слева направо после каждой удаленной вершины.

4). Дополнительное задание (на 5+):
На базе СДП построить  словарь частот встречаемости ключевых слов в тексте программы на Си.

*/
#include "stdafx.h"


int random(int N);
struct Vertex
{
	int data;
	Vertex* left;
	Vertex* right;
};
//p - adres adresa udalyaemoi vershini
//q - adres udalyaemoi vershini
Vertex **p;
Vertex *q;
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

void Obhod2(Vertex *p) {//to the left
	if (p != NULL) {
		Obhod2(p->left);
		printf("p-data = %d; ", p->data);
		Obhod2(p->right);

	}
	
}

void deletion(int d, Vertex *root) {
	p = &root;
	while (*p != NULL) {
		if (d < (*p)->data) p = &((*p)->left);
		else if (d > (*p)->data) p = &((*p)->right);
		else break;//the data is already in the tree

	}
	if (*p != NULL)
		 q = *p;
	if (q->left == NULL) *p = q->right;
	else if (q->right == NULL) *p = q->left;
	else /*2 poddereva*/
		r = q->left; s = q;
}

int main()
{
	
	setlocale(LC_ALL, "RUS");
	srand(NULL);
	int aa = 0, bb = 100, cnt = 0, i = 1;
	const int number = 10;
	int a[number];
	for (int i = 0; i < number; i++)
	{
		a[i] = random(bb - aa + 1) + aa;
	}
	for (int i = 0; i < number; i++)
	{
		printf("a[%d] = %d; ", i, a[i]);
	}
	printf("\n");
	Vertex* root = NULL;
	for (int i = 0; i < number; i++)
	{
		SDPAdd(a[i], root);
	}
	Obhod2(root);
	printf("\n");
	getchar();
    return 0;
}

int random(int N) { return rand() % N; }