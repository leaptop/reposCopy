#include "stdafx.h"
//#include <clocale>
//#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//#include <clocale>
//#include <iostream>
//
//int main()
//{
//	int n;
//	setlocale(LC_ALL, "Russian");
//	printf("Введите n\n");
//	scanf_s("%d", &n);
//	int *a;
//	a = new int[n];
//	for (int i = 0; i <= n; i++)
//	{
//		*(a + i) = i;
//		printf("%d\n",i);
//	}
//	printf("After initialization\n");
//	for (int i = 2; i <= n; i++)
//	{
//		printf("%d\n", a[i]);
//	}
//	for (int i = 2; i < n; i++)
//	{
//		if(a[i])
//	}
//	_getch();
//	return 0;
//}

#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "n= ";
	cin >> n;
	int *a = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		a[i] = i;
	for (int p = 2; p < n + 1; p++)
	{
		if (a[p] != 0)
		{
			cout << a[p] << endl;
			for (int j = p * p; j < n + 1; j += p)
				a[j] = 0;
		}
	}
	cin.get(); cin.get();
}