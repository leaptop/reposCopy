#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <clocale>


main()
{setlocale( LC_ALL, "Russian" ); 
float *p; // ��������� �� ������������ ����� 
  int i,n; // ������ ������� n ������� ����������, �.�. n � �� ���������
  printf("\n ������ �������: ");
  scanf("%d",&n);
  p=(float *) malloc(n*sizeof(float));// ��������  ������ ��� n    ������������ �����; ������� sizeof(<���>) ���������� ������ ���� � ������.
  printf("n*sizeof(float) = %d\n", n*sizeof(float));
  if ( p == NULL ) // ���� �� ������� �������� ������ 
 {  
     printf(" �� ������� �������� ������ ");
    return 1; // ����� �� ������, ��� ������ 1
 }
  for (i=0;i<n;i++)
  {  printf("p[%d]=",i);
     scanf("%f",&p[i]);
  }
  for (i=0;i<n;i++)  
     printf("\t p[%d]=%8.2f",i,p[i]);
  free(p);
  p=NULL;
  getch();
  return 0;
}

