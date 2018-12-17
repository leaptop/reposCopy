
#pragma once

#include <vector>
#include <string>

#define ESC      27
#define MAXMENU   9

struct MENUARGS { };

typedef bool (*FItem_ptr) (MENUARGS *args);
typedef bool MENUITEM;

class MENU
{
    private:
        struct ITEM
        {
            FItem_ptr func;
            std::string name;
            MENUARGS *args;
            //ITEM(FUNC_PTR newfunc, std::string newname) : func(newfunc), name(newname) {}
        };
        std::vector<ITEM> item;
        
        ITEM head;
                      
    public:
        void PrintMenu()
        {
            for (int i=0; i<item.size(); i++)
            {
                printf("\n    %d   - %s",i+1,item[i].name.c_str());
            }
            //printf("\n  [ESC] - Quit.");
            printf("\n   ESC  - Выход.");
            printf("\n\n  ");
        }
        void Add(FItem_ptr newfunc, std::string newname, MENUARGS *newargs = NULL)
        {
            if (item.size() < MAXMENU)
            {
                ITEM newitem;
                newitem.func = newfunc;
                newitem.name = newname;
                newitem.args = newargs;
                //ITEM newitem(newfunc,newname);
                item.push_back(newitem);
            }
            //else { system("cls"); printf("\n  ERROR: This menu already contains %d/%d items!",MAXMENU,MAXMENU); _getch(); abort();}
        }
        void Initialize()
        {
            head.func = NULL;
            head.args = NULL;
            item.reserve(MAXMENU);            
        }
        MENU(std::string newheadname)
        {
            head.name = newheadname;
            Initialize();
        }
        MENU()
        {
            Initialize();
        }
        void SetHeadFunc(FItem_ptr newheadfunc, MENUARGS *newargs = NULL)
        {
            head.func = newheadfunc;
            head.args = newargs;
        }
        void Start()
        {
            char cKey;
            bool bSkip;
            int index;
            while (true)
            {
                bSkip = false;
                system("cls");
                if (head.func) head.func(head.args);
                printf("%s",head.name.c_str());
                PrintMenu();
                cKey = _getch();
                index = ((int)cKey) - ((int)'1');
                if (index>=0 && index <item.size())
                {
                    bSkip = item[index].func(item[index].args);
                }
                else if (cKey==ESC) break;
                //else printf("Unknown command.\n  ");
                else printf("Неверный выбор команды.\n  ");
                if (!bSkip)
                {
                    //printf("\n  Press any key to continue...\n  ");
                    printf("\n  Нажмите любую клавишу для продолжения...\n  ");
                    _getch();
                }
            }
        }
};




