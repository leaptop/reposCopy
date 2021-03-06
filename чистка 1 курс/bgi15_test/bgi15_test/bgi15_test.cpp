#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "graphics.h"
#include <math.h>
#define ESC 27

namespace asset
{
	int Maximum(int a, int b)
	{
		if (a>b) return a;
		return b;
	}

	void swap(int *a, int *b)
	{
		int c = *a; *a = *b; *b = c;
	}

	void SelectSort(int *a, int n)
	{
		int i, j, tmp, nmax;
		for (i = 0; i<n - 1; i++)
		{
			nmax = 0;
			for (j = 1; j<n - i; j++)
				if (a[j]>a[nmax]) nmax = j;
			if ((n - i - 1) != nmax) swap(&a[n - i - 1], &a[nmax]); // не меняет одинаковые элементы местами
																	//swap (&a[n-i-1],&a[nmax]); строчка нужна, если убрать верхние 2
		}
	}

	void Shift(int *a, int start, int end)
	{
		int i;
		for (i = start; i<end; i++)
			a[i] = a[i + 1];
	}

	int Finding_repeats(int *a, int n)
	{
		int i = 1, count = 0;
		while (i<n - count)
		{
			if (a[i] == a[i - 1])
			{
				Shift(a, i, n - count - 1);
				count++;
			}
			else i++;
		}
		return count;
	}

	void RandomizeArray(int *a, int n)
	{
		for (int i = 0; i<n; i++) a[i] = rand() % n;
	}

	int* CreateArray(int n)
	{
		return new int[n];
	}
};

struct TREE
{
	int data;
	TREE *l, *r;
};

class CTree
{
private:
	TREE * root;
	int size;
	int sum;
	int height;
	int avglen;

	void _Print(TREE *p)
	{
		if (p != NULL)
		{
			_Print(p->l);
			printf("%d  ", p->data);
			_Print(p->r);
		}
	}
	int _GetSize(TREE *p)
	{
		int size;
		if (p == NULL) return 0;
		else size = 1 + _GetSize(p->l) + _GetSize(p->r);
		return size;
	}
	int _GetSum(TREE *p)
	{
		int sum;
		if (p == NULL) return 0;
		else sum = p->data + _GetSum(p->l) + _GetSum(p->r);
		return sum;
	}
	int _GetHeight(TREE *p)
	{
		int height;
		if (p == NULL) return 0;
		else height = 1 + asset::Maximum(_GetHeight(p->l), _GetHeight(p->r));
		return height;
	}
	int _GetAvgLen(TREE *p, int L)
	{
		int ALoW;
		if (p == NULL) return 0;
		else ALoW = L + _GetAvgLen(p->l, L + 1) + _GetAvgLen(p->r, L + 1);
		return ALoW;
	}
	void _BuildStats()
	{
		size = _GetSize(root);
		sum = _GetSum(root);
		height = _GetHeight(root);
		avglen = _GetAvgLen(root, 1);
	}
	void _Clean(TREE *p)
	{
		if (p == NULL) return;
		_Clean(p->l); delete p->l;
		_Clean(p->r); delete p->r;
	}
	TREE* _Build_ISDP(int *a, int L, int R)
	{
		int m;
		TREE *p;
		if (L>R) return NULL;
		else m = (L + R) / 2;
		p = new TREE;
		p->data = a[m];
		p->l = _Build_ISDP(a, L, m - 1);
		p->r = _Build_ISDP(a, m + 1, R);
		return p;
	}
	TREE* __Build_SDP_Recursive(int D, TREE *p)
	{
		//printf("Building something.\n"); _getch();
		if (p == NULL)
		{
			p = new TREE;
			p->data = D;
			p->l = p->r = NULL;
			return p;
		}
		//_Print(this->root); printf("\n"); _getch();
		if (p->data>D) p->l = __Build_SDP_Recursive(D, p->l);
		else if (p->data<D) p->r = __Build_SDP_Recursive(D, p->r);
		return p;
	}
	void _Build_SDP_Recursive(int D)
	{
		this->root = __Build_SDP_Recursive(D, root);
	}
	TREE *_Build_SDP_DoubleInd(int D)
	{
		TREE **p;
		p = &root;
		while (*p)
		{
			if (D < (*p)->data) p = &((*p)->l);
			else if (D >(*p)->data) p = &((*p)->r);
			else break;
		}
		if (*p == NULL)
		{
			*p = new TREE;
			(*p)->data = D;
			(*p)->l = NULL;
			(*p)->r = NULL;
		}
	}

public:
	TREE * GetRoot()
	{
		return root;
	}
	void Print()
	{
		_Print(this->root);
	}
	int GetSize()
	{
		return size;
	}
	int GetSum()
	{
		return sum;
	}
	int GetHeight()
	{
		return height;
	}
	int GetAvgLen()
	{
		return avglen;
	}
	int GetWidth()
	{
		return ((int)pow(2, height - 1));
	}
	float GetAvgHeight()
	{
		return ((float)avglen / size);
	}
	void Clean()
	{
		root = NULL;
		size = 0;
		sum = 0;
		height = 0;
		avglen = 0;
		_Clean(root);
	}
	void Build_ISDP(int *a, int n)
	{
		Clean();
		asset::SelectSort(a, n);
		int end = asset::Finding_repeats(a, n);
		this->root = _Build_ISDP(a, 0, n - end - 1);
		_BuildStats();
	}
	void Build_SDP_Recursive(int *a, int n)
	{
		Clean();
		for (int i = 0; i<n; i++)
		{
			_Build_SDP_Recursive(a[i]);
		}
		_BuildStats();
	}
	void Build_SDP_DoubleInd(int *a, int n)
	{
		Clean();
		TREE *temp;
		for (int i = 0; i<n; i++)
		{
			temp = _Build_SDP_DoubleInd(a[i]);
			if (!root) root = temp;
		}
		_BuildStats();
	}
	CTree()
	{
		Clean();
	}
	~CTree()
	{
		_Clean(root);
	}
};

namespace gfx
{
#define RAD         14
#define YSTEP       64

#define LINEWIDTH    2
#define OPTIMIZE     0

#define BIGTEXT      0
#define TEXTSHIFTX  -7
#define TEXTSHIFTY  -7




#define RESX 1600
#define RESY  900    
#define GRAY0 COLOR(16,16,16)
#define GRAY1 COLOR(32,32,32)
#define GRAY2 COLOR(160,160,160)
#define GRAY3 COLOR(200,200,200)
#define GRAY4 COLOR(232,232,232)

	struct DOT
	{
		int x;
		int y;
	};
	DOT window;
	float scale;

	void Stop()
	{
		closegraph();
	}
	void Start()
	{
		//float l = 0.8;
		int l = 1;
		int cl[9];
		memset(cl, 0, sizeof(int) * 9);
		cl[0] = COLOR(215 * l, 215 * l, 0 * l);  // желтый
		cl[1] = COLOR(160 * l, 90 * l, 0 * l);  // ?
		cl[2] = COLOR(50 * l, 205 * l, 50 * l);  // темно-зеленый
		cl[3] = COLOR(186 * l, 85 * l, 211 * l);  // фиолетовый
		cl[4] = COLOR(255 * l, 0 * l, 0 * l);  // красный
		cl[5] = COLOR(30 * l, 144 * l, 255 * l);  // голубой
		cl[6] = COLOR(32 * l, 255 * l, 208 * l);  // бирюзовый 
		cl[7] = COLOR(255 * l, 140 * l, 0 * l);  // оранжевый
		cl[8] = COLOR(255 * l, 160 * l, 225 * l);  // розовый

		window.x = GetSystemMetrics(SM_CXSCREEN) - 6;
		window.y = GetSystemMetrics(SM_CYSCREEN) - 64;
		initwindow(window.x, window.y);

		float SX = (float)window.x / RESX;
		float SY = (float)window.y / RESY;
		if (SX < SY) scale = SX;
		else         scale = SY;

		setlinestyle(SOLID_LINE, 0, LINEWIDTH);

		setbkcolor(GRAY1);
		setcolor(BLUE);
		cleardevice();
		if (BIGTEXT)
		{
			settextstyle(DEFAULT_FONT, HORIZ_DIR, 0);
			settextjustify(CENTER_TEXT, CENTER_TEXT);
		}
	}

	void DrawEdge(int x1, int y1, int x2, int y2)
	{
		setcolor(GREEN);
		line(x1*scale, y1*scale, x2*scale, y2*scale);
	}
	void DrawNumber(int num, int x, int y)
	{
		char msg[4];
		sprintf(msg, "%d", num);
		setcolor(YELLOW);
		outtextxy(x*scale + TEXTSHIFTX, y*scale + TEXTSHIFTY, msg);
	}
	void DrawCircle(int x, int y)
	{
		if (!OPTIMIZE)
		{
			setcolor(GRAY1);
			setlinestyle(SOLID_LINE, 0, RAD * 2);
			circle(x*scale, y*scale, 1);
			setlinestyle(SOLID_LINE, 0, LINEWIDTH);
		}
		setcolor(LIGHTBLUE);
		circle(x*scale, y*scale, RAD*scale);
	}
	void DrawTree_Edges(TREE *p, int xl, int xr, int y)
	{
		if (p->l)
		{
			DrawEdge((xl + xr) / 2, y, (xl + xr) / 2 - (xr - xl) / 4, y + YSTEP);
			DrawTree_Edges(p->l, xl, (xl + xr) / 2, y + YSTEP);
		}
		if (p->r)
		{
			DrawEdge((xl + xr) / 2, y, (xl + xr) / 2 + (xr - xl) / 4, y + YSTEP);
			DrawTree_Edges(p->r, (xl + xr) / 2, xr, y + YSTEP);
		}
	}
	void DrawTree_Circles(TREE *p, int xl, int xr, int y)
	{
		if (p != NULL)
		{
			DrawTree_Circles(p->l, xl, (xl + xr) / 2, y + YSTEP);
			DrawCircle((xl + xr) / 2, y);
			DrawTree_Circles(p->r, (xl + xr) / 2, xr, y + YSTEP);
		}
	}
	void DrawTree_Numbers(TREE *p, int xl, int xr, int y)
	{
		if (p != NULL)
		{
			DrawTree_Numbers(p->l, xl, (xl + xr) / 2, y + YSTEP);
			DrawNumber(p->data, (xl + xr) / 2, y);
			DrawTree_Numbers(p->r, (xl + xr) / 2, xr, y + YSTEP);
		}
	}
	void DrawTree(CTree tree)
	{
		cleardevice();
		TREE *temp = tree.GetRoot();
		if (!temp) return;
		int startx1 = 0;
		int startx2 = RESX;
		int starty = RAD * scale * 4;

		DrawTree_Edges(tree.GetRoot(), startx1, startx2, starty);
		DrawTree_Circles(tree.GetRoot(), startx1, startx2, starty);
		DrawTree_Numbers(tree.GetRoot(), startx1, startx2, starty);
	}
};

void BuildTable(int size)
{
	int *a;
	CTree tree;
	printf("\nВывод таблицы сравнения:\n\n");
	printf("   ||=======================================================================||\n");
	printf("   ||     N=%3d    ||  Размер  ||  Контр. сум.  ||  Высота  ||  Ср. Высота  ||\n", size);
	printf("   ||--------------||----------||---------------||----------||--------------||\n");

	a = asset::CreateArray(size);
	asset::RandomizeArray(a, size);
	tree.Build_ISDP(a, size);
	printf("   ||     ИСДП     ||   %3d    ||    %6d     ||   %3d    ||    %5.2f     ||\n", tree.GetSize(), tree.GetSum(), tree.GetHeight(), tree.GetAvgHeight());
	printf("   ||--------------||----------||---------------||----------||--------------||\n");
	tree.Clean();
	delete a;

	a = asset::CreateArray(size);
	asset::RandomizeArray(a, size);
	tree.Build_SDP_Recursive(a, size);
	printf("   ||   СДП рек.   ||   %3d    ||    %6d     ||   %3d    ||    %5.2f     ||\n", tree.GetSize(), tree.GetSum(), tree.GetHeight(), tree.GetAvgHeight());
	printf("   ||--------------||----------||---------------||----------||--------------||\n");
	tree.Clean();
	delete a;

	a = asset::CreateArray(size);
	asset::RandomizeArray(a, size);
	tree.Build_SDP_DoubleInd(a, size);
	printf("   ||   СДП д. к.  ||   %3d    ||    %6d     ||   %3d    ||    %5.2f     ||\n", tree.GetSize(), tree.GetSum(), tree.GetHeight(), tree.GetAvgHeight());
	printf("   ||=======================================================================||\n");
	tree.Clean();
	delete a;
}

void menu()
{
	int b = RESX;
	srand(time(0));
	int *a;
	int size = 30;

	CTree tree;

	gfx::Start();

	bool skip = false;
	bool exit = false;
	bool validkey = false;
	char cKey, cKey2;
	while (!exit)
	{
		skip = false;
		system("cls");
		printf("Главное меню, введите команду:\n");
		printf("1. Изменить размер массива (сейчас: %d)\n", size);
		printf("2. Построить дерево\n");
		printf("3. Таблица сравнения\n");
		cKey = _getch();
		switch (cKey)
		{
		case '1':
		{
			printf("\nНовый размер: "); scanf("%d", &size);
			if (size<0) size = -size;
			else if (size == 0) size = 10;
			skip = true;
			break;
		}
		case '2':
		{
			a = asset::CreateArray(size);
			asset::RandomizeArray(a, size);
			printf("\nТип дерева:\n");
			printf("1. ИСДП\n");
			printf("2. СДП (рекурсивно)\n");
			printf("3. СДП (двойная косвенность)\n");
			validkey = true;
			cKey2 = _getch();
			switch (cKey2)
			{
			case '1':
			{
				tree.Build_ISDP(a, size);
				break;
			}
			case '2':
			{
				tree.Build_SDP_Recursive(a, size);
				break;
			}
			case '3':
			{
				tree.Build_SDP_DoubleInd(a, size);
				break;
			}
			case ESC:
			{
				exit = true;
				skip = true;
				break;
			}
			default:
			{
				validkey = false;
				printf("\nНеизвестный выбор.\n");
				break;
			}
			}
			if (validkey)
			{
				printf("\nОбход дерева: "); tree.Print(); printf("\n\n");
				printf("Размер дерева: %d\n", tree.GetSize());
				printf("Контрольная сумма дерева: %d\n", tree.GetSum());
				printf("Высота дерева: %d\n", tree.GetHeight());
				printf("Средняя высота дерева: %5.2f\n", tree.GetAvgHeight());
				gfx::DrawTree(tree);
				tree.Clean();
			}
			delete a;
			break;
		}

		case '3':
		{
			BuildTable(size);
			break;
		}

		case '4':
		{
			a = asset::CreateArray(size);
			asset::RandomizeArray(a, size);
			tree.Build_SDP_Recursive(a, size);
			printf("\nОбход дерева: "); tree.Print(); printf("\n\n");
			printf("Размер дерева: %d\n", tree.GetSize());
			printf("Контрольная сумма дерева: %d\n", tree.GetSum());
			printf("Высота дерева: %d\n", tree.GetHeight());
			printf("Средняя высота дерева: %5.2f\n", tree.GetAvgHeight());
			gfx::DrawTree(tree);
			_getch();

			tree.Build_SDP_DoubleInd(a, size);
			printf("\nОбход дерева: "); tree.Print(); printf("\n\n");
			printf("Размер дерева: %d\n", tree.GetSize());
			printf("Контрольная сумма дерева: %d\n", tree.GetSum());
			printf("Высота дерева: %d\n", tree.GetHeight());
			printf("Средняя высота дерева: %5.2f\n", tree.GetAvgHeight());
			gfx::DrawTree(tree);
			break;
		}

		case ESC:
		{
			exit = true;
			skip = true;
			break;
		}

		default:
		{
			printf("\nНеизвестная команда\n");
			break;
		}
		}
		if (!exit && !skip)
		{
			printf("\n");
			printf("Для продолжения нажмите любую клавишу...\n");
			_getch();
		}
	}
	gfx::Stop();
}

int main()
{
	system("chcp 1251");
	menu();
	return 0;
}
