#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
main()
{ char ch, sl[50];
  char text[]="one two three four";
  FILE *pf, *pr;                      // ��������� �� �����
  pf=fopen("new1.txt","w");  // �������� ������ ����� new1.txt
 // system(�CLS�);
  fprintf(pf,"%s\n",text);        // ������ � ���� ������ text
  fclose(pf);                            // �������� ����� pf  
  pf=fopen("new1.txt","r");   // �������� ����� pf ��� ������
  pr=fopen("new2.txt","w");  // �������� ������ ����� new2.txt
  while (!feof(pf))                  // ���� �� ����� �����
  { ch=getc(pf);                      // ������ ������� ch �� ����� pf
     if (ch != ' ')
         putc(ch,pr);                    // ������ � ���� pr ������� ch
  }
  fclose(pr);                           // �������� ����� pr
  rewind(pf);                          // ������� ��������� �� ������ ����� pf
  fgets(sl,50,pf);                     // ������ �� ����� pf ������ � ���������� sl
  printf("%s\n",sl);                 // ����� ������ sl 
  pr=fopen("new2.txt","r");   // �������� ����� pr ��� ������
  while (!feof(pr))                 // ���� �� ����� ����� pr
  {  ch=getc(pr);                   // ������ ������� �� ����� pr
      putchar(ch);                  // ����� ������� ch 
   }
  fclose(pf);                          // �������� ������
  fclose(pr);
  getch();
}
