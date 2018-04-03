#include "pch.h"
#include<windows.h>
#include<string.h>

#include <windows.h>
#include <conio.h>
void main()
{
	HWND hwnd;
	char Title[1024];
	GetConsoleTitle(Title, 1024); // Узнаем имя окна
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
	HDC hdc = GetDC(hwnd);    // Получаем контекст для рисования
	HPEN p1, p2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); // Создаем красное перо
	HBRUSH b1, b2 = CreateSolidBrush(RGB(0, 255, 0)); // Создаем зеленую кисть
	p1 = (HPEN)SelectObject(hdc, p2);  // Заносим красное перо в контекст рисования
	b1 = (HBRUSH)SelectObject(hdc, b2);    // Заносим кисть в контекст рисования
	Ellipse(hdc.0.0.100, 100); // Рисуем круг
	LineTo(hdc, 100, 100);    // Проводим линию
	SelectObject(hdc, p1);   // Возвращаем старое перо
	SelectObject(hdc, b1);   // Возвращаем старую кисть
	ReleaseDC(hwnd, hdc);    // Освобождаем контекст рисования
	DeleteObject(p2);       // Удаляем созданное перо
	DeleteObject(b2);       // Удаляем созданную кисть
	_getch();

}