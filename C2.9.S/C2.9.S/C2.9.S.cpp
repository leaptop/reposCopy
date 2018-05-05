// C2.9.S.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>//  for cout(for C++ only)
#include<conio.h>// for _getch()
using namespace std;// for cout(for C++ only)

/*
Здесь будет реализован стек, отсортированный так, что Head указывает
на наименьший элемент(элемент, чьё поле name наименьшее).
*/

typedef struct Node {
	Node *next;
	char name[20];
	int m1, m2, m3, m4;

};
typedef Node *PNode;



//CreateNode(PNode Head) {//работает без сортировки
//	PNode NewNode = new Node;
//	cout << "Введите фамилию студента ";	
//	cin >> NewNode->name;
//	NewNode-> next = Head;//добавил в next значение внешней ссылки Head
//	Head = NewNode;//добавил во внешнюю ссылку Head адрес текущей структуры
//	return NewNode;
//}
//по идее мне надо более тяжёлые переставлять в начало списка

/*Эту функцию(findTheLastSmaller) уже попроще протестить. Лучше не гадать долго,
а начать уже тестировать. Моя задача - найти последний наименьший элемент списка
по отношению к новой структуре New(признак сравнения - поле name).
Т.о. я буду иметь ссылки на последний наименьший (возвращаемое значение) и на следующий,
(тот, который больше искомого(на него можно сослаться так: возвращаемое значение -> next)).
*/

PNode findTheLastSmaller(PNode &st, PNode &New) {// 
	PNode temp;//
	int count = 0;//
	
	while (st->next != NULL) {
		if (strcmp(st->name, New->name) >= 0) {/*Уже известно, что Head меньше, чем New*/
			return st;
		}
		st = st->next;
	}
	return st;
}

PNode CreateNode(PNode &Head, PNode &NewNode, PNode &prohod, PNode &prohodPrev) {//так и не смог сделать сортировку одновременно с построением
	NewNode = new Node;
	PNode tls;
	cout << "Введите фамилию студента ";
	cin >> NewNode->name;
	if (Head == NULL) { Head = NewNode; NewNode->next = NULL;  return Head; }
	if (strcmp(Head->name, NewNode->name) >= 0) {/* Если нейм головы уже больше,
												 то тупо ставим в начало списка(перед Head)*/
		NewNode->next = Head; Head = NewNode; return NULL;
	}
	/*Иначе находим последний наименьший.
	Head остаётся на месте.
	*/
	prohod = Head;
	tls = findTheLastSmaller(prohod, NewNode);

	NewNode->next = tls->next;
	tls->next = NewNode;


	//	prohodPrev = NewNode;
	//while (true) {

	//	if (strcmp(prohod->name, prohodPrev->name) <= 0) {//больше нуля указывает на то, что строка string1 больше строки string2

	//		NewNode->next = prohod;
	//		prohod->next = NewNode;
	//		//Head = prohod;
	//		if (prohodPrev != NULL)prohodPrev->next = NewNode;
	//		else Head = NewNode;
	//		break;
	//	}
	//	else {
	//		prohodPrev = prohod;


	//		if (prohod->next
	//			== NULL) {
	//			prohod->next = NewNode;
	//			NewNode->next = NULL;
	//			break;
	//		}
	//		prohod = prohod->next;
	//		continue;
	//	}
	//}


	return NewNode;
}


//void CreateNode(PNode &Head, PNode &NewNode, PNode &prohod, PNode &prohodPrev) {
//	NewNode = new Node;
//	cout << "Введите фамилию студента ";
//	cin >> NewNode->name;
//	if (Head == NULL) { Head = NewNode; NewNode->next = NULL; }
//	NewNode->next = Head;
//	Head = NewNode;
//}
//void sort(PNode *a, int n) {
//	for (int gap = n / 2; gap > 0; gap /= 2)	{
//
//		for (int i = gap; i < n; i += 1)
//		{
//			char *temp = a[i]->next;
//
//			int j;
//			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
//				arr[j] = arr[j - gap];
//
//			arr[j] = temp;
//		}
//	}
//	return 0;
//
//}

int main()
{
	PNode Head = NULL, prohod = NULL, NewNode = NULL, prohodPrev = NULL;
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите число студентов ";
	cin >> n;
	//PNode* a;
	//a = new PNode[n];
	for (int i = 0; i < n; i++) {
		CreateNode(Head, NewNode, prohod, prohodPrev);
		//a[i] = Head->next;
	}
	prohod = Head;//prohod - временная переменная для прохода по списку
	for (int i = 0; i < n; i++) {
		cout << prohod->name << endl;
		prohod = prohod->next;

	}

	_getch();
	return 0;
}

