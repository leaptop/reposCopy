#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>//  struct tov {char name[10]; float c; int kol;} t; здесь tov - тип структуры, 
//а t - название переменной?
#include <conio.h>
#include <clocale>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <cstdio>
/*    2. Дана информация о комнатах в общежитии.
Запись имеет вид: номер комнаты, площадь комнаты, факультет,
количество проживающих. Вывести данные по факультетам
о  количестве комнат, количестве студентов и средней
площади на одного студента. Названия и количество факультетов заранее
не известны  (их можно занести в отдельный массив по введенным данным).*/
//int main()
//{
//	struct infa { int roomN; int space; char facul[10]; int lodgersN; } a;
//	struct infa arr[]
//    return 0;
//}


using namespace std;
struct Obs {
	int n; float S; char Fakult[5]; int Man;
} Home;
struct Fac { char F[5]; int Rooms; int Students; float Sr; float su; }
hh;
int main() {
	struct Obs Obshezh[100];
	struct Fac Result[10];
	int i = 0, j, m, k; char Dictionary[10][5]; char bufer[40];
	SetConsoleCP(1251);				
	SetConsoleOutputCP(1251);
	printf("Вводите названия факультетов \n");
	gets_s(bufer);
	printf("Номер  Площадь  Факультет Жители \n");
	for (i = 0, j = 0, k = 0; bufer[i]; i++) {
		if (bufer[i] == ' ' && bufer[i + 1] != ' ') {
			Dictionary[k][j] = '\0';
			k++;
			j = 0;
		}
		else Dictionary[k][j++] = bufer[i];
	}
	Dictionary[k++][j] = '\0';
	for (i = 0; i < k; i++) {
		Result[i].Rooms = 0;
		Result[i].Sr = 0;
		Result[i].Students = 0;
		Result[i].su = 0;
	}
	for (i = 0; i < 100; i++) {
		m = rand() % k;
		strcpy_s(Obshezh[i].Fakult, Dictionary[m]); Obshezh[i].S = rand() % 10 + 3;
		Obshezh[i].n = rand() % 102 + 1; Obshezh[i].Man = rand() % 5 + 1;
		printf(" %4d %4.0f      %s      %4d \n", Obshezh[i].n, Obshezh[i].S, Obshezh[i].Fakult, Obshezh[i].Man);
		strcpy_s(Result[m].F, Dictionary[m]); Result[m].Rooms += Obshezh[i].n; Result[m].Students += Obshezh[i].Man;
		Result[m].su += Obshezh[i].S;
	}
	puts("Факультет Комнаты Жители Ср. Площадь");
	for (i = 0; i < k; i++) {
		Result[i].Sr = Result[i].Students / Result[i].su;
		printf(" %s      %4d      %4d      %6f \n", Result[i].F, Result[i].Rooms, Result[i].Students, Result[i].Sr);
	}
	_getch();
}


//#define n 10
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	int i, k; float sum; //k-количество искомых товаров, sum- их общая стоимость.
//	struct tov { char name[10]; float c; int kol; } t;  //Объявление структуры t
//	struct tov mag[n];  //объявление массива структур mag[n]
//	char nazv[10]; //Наименование искомого товара
//	printf("\n Введите информацию о товарах \n");
//	for (i = 0; i < n; i++)
//	{
//		printf("\n  наименование , цена, количество :  ");
//		scanf_s("%s%f%d", &t.name, &t.c, &t.kol);//Заполнение информацией структуры t
//		mag[i] = t; //Присвоение i-му элементу массива структуры t целиком
//	}
//	printf("\n введите искомый товар:  ");
//	scanf_s("%s", &nazv);
//	for (i = 0, sum = 0, k = 0; i < n; i++)
//		if (strcmp(mag[i].name, nazv) == 0)
//		{
//			sum += mag[i].c*mag[i].kol;
//			k++;
//		}
//	printf("Товаров  %s   %d,  их стоимость  %5.2f ", nazv, k, sum);
//	_getch();
//	return 0;
//}