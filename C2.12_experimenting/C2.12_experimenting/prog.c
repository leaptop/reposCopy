#include "func.h" или  void sort(int *x);
int m[] = { 8,2,4,1,6,5 };
int N = sizeof(m) / sizeof(int);
int main() {
	sort(m);
	for (int i = 0; i<N; i++) cout << m[i] << " ";
	cout << endl << N << endl;
	getch();
}