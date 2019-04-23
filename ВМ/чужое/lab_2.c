/* ������� ������ �������� ��������� ������� ������ */
#include<stdio.h>
#include<stdlib.h>
#define N 3

float matr[N][N+1];
void show();		/* ������� �� ����� ������� */
int gauss(float []);   /* ������������ ������� */

void main()
{
	int i, j;
	float *out=new float;
	randomize();
	for(i=0;i<N;i++)
		for(j=0;j<=N;j++)
			matr[i][j]=rand()%100;
	printf(" --- �������� ������� --- \n\n");
	show();
	gauss(out);
	printf("\n ---- ������ ������� ---- \n\n");
	for(i=0;i<N;i++)                              
		printf(" x%d = %5.3f", i+1, out[i]);   
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
int gauss(float out[])
{
	int i, j, k, l;
	float tmp, buf[N];
	/* ������ ��� */
	for(i=0;i<N;i++)  
		for(j=i+1;j<N;j++)
		{
			for(l=0;l<N;l++)
				if(matr[i][i]<matr[l][i])
				{
					for(k=0;k<N;k++)
					{
						buf[k]=matr[i][i];
						matr[i][i]=matr[l][i];
						matr[l][i]=buf[k];
					}
				}
			tmp=-matr[i][i]/matr[j][i]; /* ���������� �������� �������� */
			for(k=i;k<=N;k++) 
				matr[j][k]=matr[j][k]*tmp+matr[i][k]; /* ��������� ������� */
		}
        printf("\n");
        show();
        /* �������� ��� */
	for(i=N, k=N-1;k>=0;k--)
	{
		i--;
		out[k]=matr[k][N]/matr[k][i];
		for(j=0;j<k+1;j++)
			matr[k-j][N]-=matr[k-j][i]*out[k];
	}
}