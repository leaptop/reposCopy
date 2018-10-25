// saod_L3_ch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//---------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
//#include<vcl.h>
//#include <alloc.h>
#include<iostream>
using namespace std;
//---------------------------------------------------------------------------
const int N = 15;
struct vertex {
	int data;
	vertex *left;
	vertex *right;
}*root, *root2;

int random(int N) { return rand() % N; }

void FillRand(int B[], int k)
{
	int i;
	for (i = 0; i<k; i++)
		//B[i]=i;
		B[i] = random(500);
}

void Vivod(int B[], int k)
{
	int i;
	for (i = 0; i<k; i++)
	{
		printf("%d ", B[i]);
		if (i == k) printf("\n");
	}
	printf("\n");
}

void vderevo(vertex *tr, int l)
{
	int i;
	if (tr != NULL) {
		vderevo(tr->right, l + 1);
		for (i = 0; i<l; i++)
			cout << "     ";
		cout << tr->data << endl;
		vderevo(tr->left, l + 1);
	}
}

void obhod_dereva(vertex *rt)
{
	if (rt != NULL) {
		obhod_dereva(rt->left);
		cout << rt->data << " ";
		obhod_dereva(rt->right);
	}
}

int razmer(vertex *df)
{
	int raz, rl, rr;
	if (df == NULL) raz = 0;
	else {
		rl = razmer(df->left);
		rr = razmer(df->right);
		raz = 1 + rl + rr;
	}
	return(raz);
}

int high_dereva(vertex *hj)
{
	int high, hl, hr, max;
	if (hj == NULL) high = 0;
	else {
		hl = razmer(hj->left);
		hr = razmer(hj->right);
		if (hl>hr) max = hl;
		if (hl<hr) max = hr;
		high = 0 + max;
	}
	return(high);
}

int contr_summa(vertex *cs)
{
	int summa, s1, s2, s3;
	if (cs == NULL) summa = 0;
	else {
		s1 = cs->data;
		s2 = contr_summa(cs->left);
		s3 = contr_summa(cs->right);
		summa = s1 + s2 + s3;
	}
	return(summa);
}

int s_dlina(vertex *sd, int L)
{
	int sdpp, cl, cr;
	if (sd == NULL) sdpp = 0;
	else {
		cl = s_dlina(sd->left, L + 1);
		cr = s_dlina(sd->right, L + 1);
		sdpp = L + cl + cr;
	}
	return(sdpp);
}

vertex *SDP(int D, vertex *&r)
{
	vertex **p;
	p = &r;
	while (*p != NULL)
	{
		if (D<(*p)->data) p = &((*p)->left);
		else if (D>(*p)->data) p = &((*p)->right);
		else printf("*");
	}
	if (*p == NULL) {
		(*p) = new vertex;
		(*p)->data = D;
		(*p)->right = NULL;
		(*p)->left = NULL;
	}
	return(*p);
}

void inserttree(int D, vertex *&p)
{
	if (p == NULL) {
		p = new vertex;
		p->data = D;
		p->right = NULL;
		p->left = NULL;
	}
	else if (D<p->data) inserttree(D, p->left);
	else if (D>p->data) inserttree(D, p->right);
	else printf("*");
}

vertex *DEL(int X, vertex *&r2)
{
	vertex **p, *q, *r, *s;
	p = &r2;
	while (*p != NULL)
	{
		if ((*p)->data<X) p = &((*p)->right);
		else if ((*p)->data>X) p = &((*p)->left);
		else break;
	}
	if (*p != NULL) {
		q = *p;
		if (q->left == NULL) *p = q->right;
		else if (q->right == NULL) *p = q->left;
		else {
			r = q->left;
			s = q;
			while ((r->right) != NULL)
			{
				s = r;
				r = r->right;
			}
			s->right = r->left;
			r->left = q->left;
			r->right = q->right;
			*p = r;
		}
	}
	return NULL;
}

int main()
{
	int a, r, h, sum, sdp, hsd, i, RT;
	int A[N], D[10];
	//FillRand(A,N);
	A[0] = 25;
	A[1] = 6;
	A[2] = 3;
	A[3] = 56;
	A[4] = 15;
	A[5] = 30;
	A[6] = 50;
	A[7] = 5;
	A[8] = 46;
	A[9] = 13;
	A[10] = 40;
	A[11] = 32;
	A[12] = 20;
	A[13] = 12;
	A[14] = 7;
	printf("Massiv A:\n");
	Vivod(A, N);
	for (i = 0; i<N; i++)
	{
		a = A[i];
		SDP(a, root);
	}
	//printf("\nSDP:\n");
	//vderevo(root, 0);
	//printf("\nDetour of a tree: ");
	//obhod_dereva(root);
	//r = razmer(root);
	//printf("\nThe size = %d", r);
	//h = high_dereva(root);
	//printf("\nHigh = %d ", h);
	//sum = contr_summa(root);
	//printf("\nThe control sum = %d \n", sum);
	//sdp = s_dlina(root, 1);


	/*printf("\nTo remove top: ");
	cin>>RT;
	DEL(RT,root);
	printf("\nSDP:\n");
	vderevo(root,0);
	printf("\nDetour of a tree:\n");
	obhod_dereva(root);*/


	printf("\nDelete: ");
	D[0] = 25;
	D[1] = 3;
	D[2] = 15;
	D[3] = 30;
	D[4] = 50;
	D[5] = 46;
	D[6] = 5;
	D[7] = 32;
	D[8] = 12;
	D[9] = 7;
	//printf("Massiv D:\n");
	Vivod(D, 10);
	for (i = 0; i<10; i++)
	{
		DEL(D[i], root);
		printf("\nObhod from left to right without %d: ", D[i]);
		obhod_dereva(root);
	}
	printf("\n\n");
	//vderevo(root, 0);
	getchar();
	return 0;
}
//---------------------------------------------------------------------------