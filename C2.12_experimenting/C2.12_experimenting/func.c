extern int N;
void swap(int &x, int &y) {
	int t = x; x = y; y = t;
}
void sort(int *x) {
	int i, k;

	do {
		k = 0;
		for (i = 1; i<N; i++)
			if (x[i]<x[i - 1]) { swap(x[i], x[i - 1]); k = 1; }
	} while (k);
	cout << N << endl;
}