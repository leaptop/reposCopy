#include<stdio.h>
#include<clocale>

int f(){
	int i;
	scanf("%d", &i);
	if(i){if(i>0)return printf("%d ", i,f());
	else return f();
	}
}
int main(){
	setlocale(LC_ALL, "Russian");
	printf("������� ����� ������������� � ������������� �����\n");
	f();
}
