#include "stdafx.h"




#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
/*Создать текстовый файл из  N строк. Все слова, начинающиеся с гласных,
переписать в один новый файл, а с согласных – в другой новый файл.*/



int main()
{
	int N = 2;
	char ch, sl[50];
	char text[] = "one two three four six seven eight nine ten eleven twelve thirteen";
	char text2[] = "a human being is incredible";

	FILE *txtF, *gl;                      // Указатели на файлы
	txtF = fopen("текст.txt", "w");  // Создание нового файла текст.txt
	system("CLS");

	fprintf(txtF, "%s\n", text);
	fprintf(txtF, "%s\n", text2);
	fclose(txtF);

	gl = fopen("гласные.txt", "w");
	txtF = fopen("текс.txt", "r");

	while (!feof(txtF))                  // Пока не конец файла
	{
		ch = getc(txtF);                      // Чтение символа ch из файла pf
		if (ch == 'a' || ch = 'e' || ch == 'i' || ch != 'o' || ch != 'u' || ch != 'y')
			while (ch != ' '&&ch != '\n')
				putc(ch, gl);                    // Запись в файл pr символа ch
	}

	char ch, sl[50];
	char text[] = "one two three four";
	FILE *pf, *pr;                      // Указатели на файлы
	txtF = fopen("new1.txt", "w");  // Создание нового файла new1.txt
	system("CLS");
	fprintf(txtF, "%s\n", text);        // Запись в файл строки text
	fclose(txtF);                            // Закрытие файла pf  
	txtF = fopen("new1.txt", "r");   // Открытие файла pf для чтения
	gl = fopen("new2.txt", "w");  // Создание нового файла new2.txt
	while (!feof(txtF))                  // Пока не конец файла
	{
		ch = getc(txtF);                      // Чтение символа ch из файла pf
		if (ch != ' ')
			putc(ch, gl);                    // Запись в файл pr символа ch
	}
	fclose(gl);                           // Закрытие файла pr
	rewind(txtF);                          // Возврат указателя на начало файла pf
	fgets(sl, 50, txtF);                     // Чтение из файла pf строки в переменную sl
	printf("%s\n", sl);                 // Вывод строки sl 
	gl = fopen("new2.txt", "r");   // Открытие файла pr для чтения
	while (!feof(gl))                 // Пока не конец файла pr
	{
		ch = getc(gl);                   // Чтение символа из файла pr
		putchar(ch);                  // Вывод символа ch 
	}
	fclose(txtF);                          // Закрытие файлов
	fclose(gl);
	getch();
	return 0;
}