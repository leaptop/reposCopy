#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <clocale>
main(){ 

setlocale( LC_ALL, "Russian" );int m,n,j,i;
  float  **matr; float *mass; // ��������� matr � ��������� �� ������ ����������                        
  system("CLS");         
  printf("������� ������ ������ n: "); scanf("%d",&n);
  printf("������� ���������� ����� m: "); scanf("%d",&m);
  mass=new  float[m]; // �������� ������ ��� ������ ���� �����
  if (mass==NULL)
  {  puts("�� ������ ������������ ������!");
     return 1;
  }
  matr=new  float *[m]; // �������� ������ ��� ������ ����������
  if (matr==NULL)
   {  puts("�� ������ ������������ ������!");
      return 1;
   } 
  for (i=0; i<m; i++)
  {  matr[i]=new  float[n]; // �������� ������ ��� i-� ������ 
     if (matr[i]==NULL)
     { puts("�� ������ ������������ ������ ");
       return 1;
     }
     for (j=0; j<n; j++)   
        matr[i][j]=rand()%100;// ��������� ������
  }
  for (i=0; i<m; i++)
  { mass[i]=0;
    for (j=0; j<n; j++)
       mass[i]+=matr[i][j]; //�������� ����� i-� ������ � ���������� ������
  }
  for (i=0; i<m; i++)
  {  for (j=0; j<n; j++)
         printf("\t%6.2f",matr[i][j]);
     printf("\n");
  }
  for (i=0; i<m; i++)
     printf("\n  ����� %d ������ %8.2f",i,mass[i]);
  for (i=0;i<m;i++)
   {  delete  matr[i]; //����������� ������ i-� ������
         matr[i]=NULL;
    }
  delete  matr; // ����������� ������ ������� ����������
  matr=NULL;
  delete  mass; // ����������� ������ ������� ����
  mass=NULL;
  getch();
 }
