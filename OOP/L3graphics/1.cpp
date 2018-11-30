#include <stdlib.h>
#include <graphics.h>
#include <iostream>
#include <ctime>
#include "2.cpp"

using namespace std;




int main()
{
	srand(time(NULL));
	tPoint arr[100];
	initwindow(600,600);
	for (int i=0;i<100;i++)
	{
		arr[i].rand_point(600,600);
		arr[i].draw_point();
	}
	arr[0].line_move();
	getch();
	
}

