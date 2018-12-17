#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <graphics.h>
#include <math.h>
#include <vector>
#include <locale.h>

#include "cmenu.h"

#define TYPE_STACK 0
#define TYPE_QUEUE 1


struct CNode
{
    int data;
    CNode* next;
    CNode(int _data) : data(_data) { next = NULL; }
};

class CList
{
    protected:
        int size;
        
    public:
        CList() { size = 0; }
        virtual ~CList(){}
        virtual void  Push(int newdata) = 0;
        virtual void* Pop() = 0;
        virtual void  Print() = 0;
        virtual void  Clean() = 0;
};

class CStack : public CList
{
    protected:
        CNode* head;
        
    public:
        virtual void Clean()
        {
            if (head)
            {
                CNode *temp = head;
                while (temp)
                {
                    temp = temp->next;
                    delete head;
                    head = temp;
                }
            }
            size = 0;
        }
        virtual void Push(int newdata)
        {
            if (head)
            {
                CNode* node = new CNode(newdata);
                node->next = head;
                head = node;                
            }
            else head = new CNode(newdata);
            size++;
        }
        virtual void* Pop()
        {
            if (head)
            {
                int* result = new int;
                *result = head->data;
                CNode* node = head->next;
                delete head;
                head = node;
                size--;
                return result;                
            }
            return NULL;
        }
        void Print()
        {
            printf("List (totally %d elements): ",size);
            CNode *temp = head;
            while (temp)
            {
                printf("%2d ",temp->data);
                temp = temp->next;
            }
        }
        CStack()
        {
            head = NULL;
        }
        virtual ~CStack()
        {
            Clean();
        }
};

class CQueue : public CStack
{
    private:
        CNode* tail;
        
    public:
        CQueue()
        {
            tail = NULL;
        }
        ~CQueue()
        {
            // CStack's destructor will handle it
        }
        void Push(int newdata)
        {
            if (tail)
            {
                tail->next = new CNode(newdata);
                tail = tail->next;
            }
            else
            {
                tail = new CNode(newdata);
                head = tail;
            }
            size++;
        }
        void* Pop()
        {
            int* result = static_cast<int*>(CStack::Pop());
            if (head==NULL) tail = NULL;
            return result;
        }
        void Clean()
        {
            CStack::Clean();
            tail = NULL;
        }
};

struct _ARGS : MENUARGS
{
    byte type; 
    CList* list;
};

CList* CreateListOfType(byte type)
{
    switch(type)
    {
        case TYPE_STACK: return new CStack();
        case TYPE_QUEUE: return new CQueue();
    }
    return NULL;
}

MENUITEM Head(MENUARGS *args)
{
    _ARGS *arg1 = (_ARGS*) args;
    printf("\n  List's type: %s.\n\n  ",arg1->type==TYPE_STACK ? "stack" : "queue");
    arg1->list->Print();
    printf("\n  ");
}

MENUITEM SwitchType(MENUARGS *args)
{
    _ARGS *arg1 = (_ARGS*) args;
    delete arg1->list;
    arg1->type = !arg1->type;
    arg1->list = CreateListOfType(arg1->type);
    return 1;
}

MENUITEM List_Push(MENUARGS *args)
{
    _ARGS *arg1 = (_ARGS*) args;
    int newdata = rand()%21;
    arg1->list->Push(newdata);
    printf("An element was added to the list %d.\n  ",newdata);
    return 0;
}

MENUITEM List_Pop(MENUARGS *args)
{
    _ARGS *arg1 = (_ARGS*) args;
    int* result = static_cast<int*>(arg1->list->Pop());
    if (result)
    {
        printf("An element was taken from the list %d.\n  ",*result);
        delete result;
    }
    else printf("The list is empty. It's impossible to get an element\n  ");
    return 0;
}

MENUITEM List_Clear(MENUARGS *args)
{
    _ARGS *arg1 = (_ARGS*) args;
    arg1->list->Clean();
    return 1;
}

void Lab2Menu()
{
	_ARGS *arg = new _ARGS;
	arg->type = TYPE_STACK;
	arg->list = CreateListOfType(arg->type);
	
    MENU menu("\n  Menu:");
    menu.SetHeadFunc(Head,arg);
    menu.Add(SwitchType, "Change list's type'", arg);
    menu.Add(List_Push, "Add an element", arg);
    menu.Add(List_Pop, "Take an element", arg);
    menu.Add(List_Clear, "clear the list", arg);
    menu.Start();    
}

int main()
{
	setlocale (LC_ALL, "RUS"); 
    system("chcp 1251");
    srand(time(0));
	Lab2Menu();
	return 0;
}
