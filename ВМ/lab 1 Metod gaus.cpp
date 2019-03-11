#include<iostream>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
 

 
int main()
{
   int stolb=4;
   int str=5;
   double mass[4][5] = {{2,5,4,1,20},{1,3,2,1,11},{2,9,10,7,40},{3,8,9,2,37}};
               

   /*cout << "Kol stolb: ";
   cin >> stolb;
   cout << "Kol str: ";
   cin >> str;
   str+=1;
    double **mass = new double *[stolb];
         for (int i=0; i<stolb; i++)
             mass[i] = new double [str];*/
 /*
 cout<<"\n1-str  2-stolb\n"<<endl;
    for (int i = 0; i<stolb; i++)
    {
        for (int j = 0; j<str; j++)
        {
            cout<<"mass"<<"["<<i<<"]["<<j<<"]: ";
            cin >> mass[i][j];
            cout<<endl;
        }
}*/
      for (int i=0; i<stolb; i++)
       {
          for (int j=0; j<str; j++)
            cout << mass[i][j] << " ";
        cout << endl;
       }
    cout << endl;
 
    double  del;
    double otv[str];
    
    int vibor;
    cout<<"\n1-Gaus  2-Mod Gaus\n\n";
    cout<<"\nVvedi comand: ";
    cin>>vibor;   
    
    switch(vibor)
    {
    case 1:
    cout<<"\n\n";
    cout<<"\nMetod 1\n\n";
    for (int i=0; i<stolb; i++)
     {
       del=mass[i][i];
         for (int j=stolb;j>=i;j--)
         {
             mass[i][j]/=del;
             }
           for (int q=i+1;q<stolb;q++)
          {
             del=mass[q][i];
               for (int k=stolb;k>=i;k--)
             mass[q][k]-=del*mass[i][k];
          }
      }
      
      
    otv[stolb-1] = mass[stolb-1][stolb];
     for (int i=stolb-2; i>=0; i--)
       {
           otv[i] = mass[i][stolb];
           for (int j=i+1;j<stolb;j++) otv[i]-=mass[i][j]*otv[j];
       }
 
       for (int i=0; i<stolb; i++)
       {
           cout <<"X"<<i+1<<"= "<< otv[i] << " "<<endl;
           }
       break;
//---------------------------------------------------------------
       case 2:
    cout<<"\n\n";
    cout<<"\nMetod 2\n\n";
    double obmen;
       for (int i=0; i<stolb-1; i++)
     {
      for(int nug=0; nug<stolb; nug++)
      {
       if(fabs(mass[i][i])<fabs(mass[nug][i]))
       {
       for(int strok=0; strok<str; strok++)
       {
      obmen = mass[i][strok];
      mass[i][strok]=mass[nug][strok];
      mass[nug][strok]=obmen;
      }
      }
      }

 /*    for (int i=0; i<stolb; i++)
       {
          for (int j=0; j<str; j++)
            cout << mass[i][j] << " ";
        cout << endl;
       }
        cout << endl;
        _getch();*/
        
//-----------------------------------------------------
       del=mass[i][i];
         for (int j=stolb;j>=i;j--)
         {
             mass[i][j]/=del;
             }
           for (int q=i+1;q<stolb;q++)
          {
             del=mass[q][i];
               for (int k=stolb;k>=i;k--)
             mass[q][k]-=del*mass[i][k];
          }
      }
      
    otv[stolb-1] = mass[stolb-1][stolb]/mass[stolb-1][stolb-1];
     for (int i=stolb-2; i>=0; i--)
       {
           otv[i] = mass[i][stolb];
           for (int j=i+1;j<stolb;j++) otv[i]-=mass[i][j]*otv[j];
       }
 
       for (int i=0; i<stolb; i++)
       {
           cout <<"X"<<i+1<<"= "<< otv[i] << " "<<endl;
           }
       break;
           }
 
    delete[] mass;
 system("PAUSE");
   return 0;
}
