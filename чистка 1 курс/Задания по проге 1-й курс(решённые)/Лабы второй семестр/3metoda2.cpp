#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <clocale>


main()
{setlocale( LC_ALL, "Russian" ); 
  int i,n;  // ������ ������� n ������� ����������, �.�. n � �� ���������
  int *p; // ��������� �� ����� �����
  printf (" ������ ������� -> "); 
  scanf ("%d", &n);
  p = new int [n]; // ��������� ������ ��� n ����� �����
  if ( p == NULL ) // ���� �� ������� �������� ������ 
 {  
     printf(" �� ������� �������� ������ ");
    return 1; // ����� �� ������, ��� ������ 1
 }
 for (i = 0; i < n; i ++ ) 
 { 
   printf ("\n p[%d] = ", i);
   scanf ("%d", &p[i]);
 }
 for (i = 0; i < n; i ++ ) 
    printf ("\n p[%d] = %d", i,p[i]);
 puts("\n");   
 delete p; // ������������ ������
 p=NULL;
 getch();
 return 0;
}
