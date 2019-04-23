/* ������� ������� �������� ��������� ������� ������ */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define N 3

float matr[N][N+1]={{0.667, 0.167, 0, -2},{0.167, 0.667, 0.167, 0},
							{0, 0.167, 0.667, 2}};
void show();		/* ������� �� ����� ������� */
void gauss(float []);   /* ������������ ������� */

void main()
{
	int i, j;
	float out[N];
	/*randomize();
	for(i=0;i<N;i++)
		for(j=0;j<=N;j++)
			matr[i][j]=rand()%100;*/
	printf(" --- �������� ������� --- \n\n");
	show();
	gauss(out);
	printf("\n ---- ������ ������� ---- \n\n");
	for(i=0;i<N;i++)                              
		printf(" x%d = %5.3f", i+1, out[i]);
   getch();
}

/* ������� �� ����� ������� */
void show()
{
	int i, j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<=N;j++)
			printf("%8.3f  ",matr[i][j]);
		printf("\n");
	}
}

/* ������������ ������� */
void gauss(float out[])
{
	int i, j, k;
	float tmp;
	/* ������ ��� */
	for(i=0;i<N;i++)  
		for(j=i+1;j<N;j++)
		{
			tmp=-matr[i][i]/matr[j][i]; /* ���������� �������� �������� */
			for(k=i;k<=N;k++) 
				matr[j][k]=matr[j][k]*tmp+matr[i][k]; /* ��������� ������� */
		}
        /* �������� ��� */
	for(i=N, k=N-1;k>=0;k--)
	{
		i--;
		out[k]=matr[k][N]/matr[k][i];
		for(j=0;j<k+1;j++)
			matr[k-j][N]-=matr[k-j][i]*out[k];
	}
}
