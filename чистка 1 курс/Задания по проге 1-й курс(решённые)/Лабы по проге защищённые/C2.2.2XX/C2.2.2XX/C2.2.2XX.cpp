#include "stdafx.h"
#include<string>

int func(int a[], int n) {
	if (n == 1)return a[0]; else
		if (n > 0 && a[n - 1] > 0) {
			printf("%d\n", func(a, n - 1)); return a[n - 1];
		}
		else if (n > 0 && a[n - 1] < 0) { printf("%d\n", a[n - 1]); func(a, n - 1); }

}
//help please//done. 
int main()
{
	//          0  1  2  3  4  5  6  7  8  9
	int a[] = {-1,-3, 5,-2,-456,90,-34, 7, 4, 9,-4 };
	int n = 11;
	printf("%d\n", func(a, n));
	std::getchar();
	return 0;
}

