#include <stdio.h>
#include <conio.h>
void MinMax ( int a, int b, int &min, int &max )
{
  if ( a > b ) 
  {    max = a; 
       min = b; 
  }
  else 
  {    max = b; 
       min = a; 
  }
}
#include <clocale>
main(){ setlocale( LC_ALL, "Russian" );

int a, b, min, max;
printf ( "������� 2 ����� ����� ");
scanf ( "%d%d", &a, &b );
         MinMax ( a, b,min, max ); // ����� �������

printf ( " ���������� �� ��� %d, ����������  %d\n", min, max );
getch();
}

