#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<conio.h>

using namespace std;
int **mass, *massc, a, b, s, c, d, e;
void f(int** mass, int s) {//creation of the second array and summation
						   //int a, b, d;

	for (int i = 0; i < s; i++)
	{

		//massc[i] = (int *)malloc(s * sizeof(int));
		massc[i] = 0;

		for (int q = 1; q < mass[i][0]; q++)
		{
			massc[i] += mass[i][q];
		}
	}
}
int main()
{
	srand(time(0));

	cout << "insert a number of strings ";
	cin >> s;
	massc = new int[s];
	mass = new  int*[s];
	cout << "the original array\n";
	for (int i = 0; i < s; i++)//array initiation
	{
		c = (rand() % 9) + 1;
		mass[i] = new int[c];
		mass[i][0] = c;
		cout.width(3);
		cout << mass[i][0] - 1 << " ";

		for (int q = 1; q < c; q++)
		{
			mass[i][q] = rand() % 100;
			cout.width(3);
			cout << mass[i][q] << " ";
		}cout << endl;
	}
	cout << endl << "counted\n";
	f(mass, s);
	for (int i = 0; i < s; i++)
	{
		cout.width(3);
		cout << mass[i][0] - 1 << " ";

		for (int q = 1; q < mass[i][0]; q++)
		{
			cout.width(4);
			cout << mass[i][q] << " ";
		}
		cout.width(4); cout << massc[i];
		cout << endl;
	}
	_getch();
	return 0;
}

