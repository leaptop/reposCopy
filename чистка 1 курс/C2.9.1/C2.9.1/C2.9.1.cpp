#include "stdafx.h"
#include <stdio.h>
#include <iostream>//  for cout
using namespace std;// for cout
#include<conio.h>// for _getch()
#include<stdlib.h>// for srand
#include<conio.h>//for _getch()

//typedef struct st {
//	char fam[80];
//	int m1, m2, m3, m4;
//	struct st *next;
//}list;
//int main() {
//	list *pred, *head, *p;
//	for (int i = 0; i < 4; i++)
//	{
//		p = (list*)malloc(sizeof(list));
//		pred = (list*)malloc(sizeof(list));//Если не выделять так память, а создать просто
//		//массив, то в его структуры можно через точку вводить значения полей
//		printf("  fam: "); 
//		scanf_s("%s", pred->fam);
//		pred->m1 = _getch() - '0';// чтобы это работало геч должен выдавать от 0 до 9
//		pred->m2 = _getch() - '0';
//		pred->m3 = _getch() - '0';
//		pred->m4 = _getch() - '0';
//		pred->next = p; //ссылка из предыдущей на текущую. Поле next предыдущей теперь хранит адрес текущей структуры.
//		pred = p; // сохранение адреса текущей 
//	}
//}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;
struct da
{
	char	fam[20];
	int 	a, b, c, d;
} data;
typedef struct stud
{
	struct da data;
	struct stud *next;
} list;
list *creat(void);
void freeList(list *);
void getList(list *);
void insertList(list *&, list *&, list  *&);
void pousk(list *&);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	list *head;

	head = creat();
	getList(head);

	pousk(head);
	getList(head);

	freeList(head);

	_getch();
}

void freeList(list *head)
{
	list *p, *q;
	q = head;
	p = q;
	cout << "\n";
	if (head) {
		while (p) {
			q = p;
			p = p->next;
			delete q;
		}
		head = NULL;
		return;
	}
	else return;
}

void getList(list *head)
{
	list *p;
	p = head;
	cout << "\n";
	printf("Name     1  2  3  4 \n");
	while (p) {
		printf("%9s%3d%3d%3d%3d\n", p->data.fam, p->data.a, p->data.b, p->data.c, p->data.d);
		p = p->next;
	}
}

list *creat(void)
{
	list *h, *j, *i;
	int l = -1, r = 10;
	h = NULL; cout << "\nИмя(нажать s и enter для окончания): ";
	do {
		i = new list;
		gets(i->data.fam);
		i->data.a = rand() % 5 + 1;
		i->data.b = rand() % 5 + 1;
		i->data.c = rand() % 5 + 1;
		i->data.d = rand() % 5 + 1;
		insertList(h, j, i);
	} while (_getch() != 's');
	puts("\n");
	return h;
}
/* */

void insertList(list *&h, list *&j, list *&i)
{
	list *p, *old;
	p = h;
	if (!h) {
		h = i;
		j = i;
		i->next = NULL;
	}
	old = NULL;
	while (p) {
		if (strcmp(p->data.fam, i->data.fam)<0) {
			old = p;
			p = p->next;
		}
		else {
			/*ВСТАВКА В СЕРЕДИНУ*/
			if (old) {
				old->next = i;
				i->next = p;
				return;
			}

			i->next = p;
			h = i;
			return;
		}
	}
	j->next = i;
	i->next = NULL;
	j = i;
}

void pousk(list *&head)
{
	list *p, *old;
	p = head;
	old = NULL;
	/*ПОКА НЕ КОНЕЦ СПИСКА*/
	while (p) {
		/*ЕСЛИ ГУД ИДЕМ ДАЛЬШЕ*/
		if (p->data.a >= 2 && p->data.b >= 2 && p->data.c >= 2 && p->data.d >= 2) {
			old = p;
			p = p->next;
		}
		else {
			/*УДАЛЕНИЕ В СЕРЕДИНЕ*/
			if (old) {
				old->next = p->next;
				delete p;
				p = old->next;
			}
			/*УДАЛЕНИЕ В НАЧАЛЕ*/
			else {
				old = p;
				p = p->next;
				delete old;
				old = NULL;
				head = p;
			}
		}
	}
}





