#include "stdafx.h"
#include<conio.h>
#include<iostream>
using namespace std;
int recu(int i) {
	int x;
	scanf_s("%d", &x);
	if (x > 0) {

		printf("%d\n", recu(x));
	}
	else if (x < 0) {

		recu(x);
	}
	else if (i == 0) {
		printf("the end\n"); //return 0;
	}
	return i;
}

int main()
{
	cout << "Insert numbers, hitting enter each time\n";
	int h;
	scanf_s("%d", &h);
	printf("%d\n", recu(h));

	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	getchar();
	return 0;
}

