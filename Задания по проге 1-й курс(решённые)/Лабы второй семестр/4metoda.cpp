#include <stdio.h>
#include <stdlib.h>
#include <clocale>
const int n=5; // ���������� ��������� � ������
typedef int rown[n];//rown - ����� ���: ������ (������) �� n ����� �����

main()

{ 


setlocale( LC_ALL, "Russian" );

 int i,j,m;
 rown *a; // ��������� �� ������
 int *b;   // ��������� �� �����
 printf ( "����� �����?  ");
 scanf ( "%d", &m );
 a = new rown[m]; // �������� ������ ��� ������� �� ������ a, m �����
                                // �� n ��������� � ������ 
if ( a == NULL ) 
{   printf("�� ������� �������� ������");
    return 1; // ����� �� ������, ��� ������ 1
}
b=new int[m]; // �������� ������ ��� ������ ���� ����� (m �����)
if ( b == NULL ) 
{   printf("�� ������� �������� ������");
    return 1; // ����� �� ������, ��� ������ 1
}
// ��������� ������� ���������� �������
  for (i=0; i<m; i++)
 {  for (j=0; j<n; j++)
    { a[i][j]=rand()%11;
      printf("%4d",a[i][j]);
    }
    puts("\n");
 } 
// ���������� � ������ b ����� ����� �������
 for (i=0; i<m; i++)
 {   b[i]=0;
     for (j=0; j<n; j++) 
         b[i]+=a[i][j];  
 }
 puts("\n");
  for (j=0; j<m; j++)
     printf("%4d",b[j]);           
 delete a; // ����������� ������, ������� ��� ������� a
 delete b; // ����������� ������, ������� ��� ������ b  
 puts("\n");
 system("PAUSE");
 return 0;
}
