#include <stdio.h>


  
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h> 
#pragma warning(disable : 4996)


struct tov { char name[10]; int nLuggage; int weight; float c; int kol; }t1;
void input(FILE *); // �������� ������ �����// �� ��, ��� � app, ������ ����� ������ ������� ���������
void print(FILE *); // �������� �����
void app(FILE *); // ���������� � ����
void find(FILE *); // ����� � ��������� 
void NAddition(FILE*);//�������� N �������
void del(FILE *);//�������� ������� � ����������, ����� ��� ����� ������� ������, ��� 10 ��.
int main(int argc, char *argv[])
{

	setlocale(LC_ALL, "RUS");
	char c;
	int n;
	FILE *tf = NULL;
	while (1)
	{
		system("CLS");
		puts("  1 � ����� ����");
		puts("  2 � �������� �����");
		puts("  3 � ���������� � ����");
		//puts("  4 � ����� ");
		puts("  5 - �������� ���������� � ����� ������ ������ 10");
		puts("  6 - ���������� n �������");
		puts("  0 - �����");
		c = getch();
		switch (c)
		{
		case '1':input(tf); break;
		case '2':print(tf); break;
		case '3':app(tf); break;
			//case '4':find(tf); break;
		case '5':del(tf); break;
		case '6':NAddition(tf); break;
		case '0':return 0;
		default: puts(" �������� �����");
		}
	}
}
void find(FILE *tf)
{
	char c, tov[10];
	tf = fopen("file1.dat", "rb+"); // �������� ��������� ����� ��� ������ � ������
	system("CLS");
	puts(" �������� �������� ������: ");
	gets(tov);
	fread(&t1, sizeof(t1), 1, tf);
	while (!feof(tf))
	{
		if (strcmp(t1.name, tov) == 0)
		{
			printf(" tovar %10s cena %6.2f kolic %d", t1.name, t1.c, t1.kol);
			_getch();
		}
		fread(&t1, sizeof(t1), 1, tf);
	}
	fclose(tf);
}
void del(FILE* tf) {
	FILE *tf2;
	tf = fopen("file1.dat", "rb+"); // �������� ��������� ����� ��� ������ � ������
	tf2 = fopen("file2.dat", "wb");
	fread(&t1, sizeof(t1), 1, tf);
	while (!feof(tf)) {
		if (t1.weight >= 10) {
			fwrite(&t1, sizeof(t1), 1, tf2);
		}
		fread(&t1, sizeof(t1), 1, tf);
	}
	fclose(tf);
	fclose(tf2);
	remove("file1.dat");
	rename("file2.dat", "file1.dat");
}
void NAddition(FILE *tf) {
	int n = 0;
	system("CLS");
	printf("������� ������� �������? ");
	scanf("%d", &n);

	char ch;
	tf = fopen("file1.dat", "ab"); // �������� ��������� ����� ��� ����������
	system("CLS");
	printf("\n  ���� ����������\n");
	do
	{
		printf("\n name: "); scanf("%s", &t1.name);
		printf(" ��� ������: "); scanf("%d", &t1.weight);
		printf(" ���������� ���� ������: "); scanf("%d", &t1.nLuggage);
		fwrite(&t1, sizeof(t1), 1, tf);
		//printf(" ���������?  y/n ");
		//ch = getch();
		n--;
	} while (//ch != 'y'&& 
		n > 0);
	fclose(tf);
}
void app(FILE *tf)
{
	char ch;
	tf = fopen("file1.dat", "ab"); // �������� ��������� ����� ��� ����������
	system("CLS");
	printf("\n  ���� ����������\n");
	do
	{
		printf("\n name: "); scanf("%s", &t1.name);
		printf(" ��� ������: "); scanf("%d", &t1.weight);
		printf(" ���������� ���� ������: "); scanf("%d", &t1.nLuggage);
		fwrite(&t1, sizeof(t1), 1, tf);
		printf(" ���������?  y/n ");
		ch = getch();
	} while (ch != 'y');
	fclose(tf);
}
void input(FILE *tf)
{
	char ch;
	tf = fopen("file1.dat", "wb"); // �������� ��������� ����� ��� ������
	system("CLS");
	printf("\n ���� ���\n");
	do
	{
		printf("\n ������� ��� ���������: "); scanf("%s", &t1.name);
		printf(" ��� ������: "); scanf("%d", &t1.weight);
		printf(" ���������� ���� ���������� �������: "); scanf("%d", &t1.nLuggage);
		fwrite(&t1, sizeof(t1), 1, tf); // ������ � ���� ����� ��������� t1
		printf("\n ���������?  y/n  ");
		ch = getch();
	} while (ch != 'y');
	fclose(tf);
}

void print(FILE *tf)
{
	int i;
	system("CLS");
	tf = fopen("file1.dat", "rb"); // �������� ��������� ����� ��� ������
	i = 1;
	fread(&t1, sizeof(t1), 1, tf); // ������ �� ����� ����� ��������� t1
	while (!feof(tf))
	{
		printf("\n Name: %10s   weight: %3d   Kolichestvo mest: %d", t1.name, t1.weight, t1.nLuggage);
		fread(&t1, sizeof(t1), 1, tf);
		i++;
	}
	getch();
}




