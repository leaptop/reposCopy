#include <iostream>
 #include "math.h"
using namespace std;
 
int n, i, j, k;
 
double d, s;
void matrixShow(double ** a){
 	for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%0.1f \t", a[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("\n");
 }
 
void moveLine(double ** a,short int i, short int j, int n)
{
	double temp;
	for (int t = 1; t <= n; t++)
    			{
    				temp=a[i][t];
    				a[i][t]=a[j][t];
    				a[j][t]=temp;
    				
				}
}
 
int main()
{
    cout << "Kol-vo: " << endl;
    cin >> n;
   
    double **a = new double *[n];
   double **E = new double *[n];
    for (i = 0; i <= n; i++) {
    a[i] = new double [n];	
    E[i] = new double [n];	
	}
 
   for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
        	if(i==j)
        	E[i][j]=1;
        	else
        	E[i][j]=0;
        }
	}
   
    double *b = new double [n];
    double *x = new double [n];
   
    cout << "Vvedite koefficienty i svobodnye chleny " << endl;
   
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "a[ " << i << "," << j << "]= ";
            cin >> a[i][j];
        }
       // cout << "b[ " << i << "]= ";
        //cin >> b[i];
    }
   
    matrixShow(a);
    
   double temp;
   int max;
    for (k = 1; k <= n; k++) // прямой ход
    {
    	printf("Zanulen %d stolbec\n", k );
    	max=k;
    	for (int t = k ; t <= n; t++)
        {
        	//cout<<a[t][k]<<",";
        	if(fabs(a[t][k])>fabs(a[max][k])){
        		max=t;
			}
        		
		}
		cout<<max;
		if(max!=k){
				moveLine( a,k,max,n);
				moveLine( E,k,max,n);
		}
        for (j = k + 1; j <= n; j++)
        {
            d = a[j][k] / a[k][k];
            for (i = k; i <= n; i++)
            {
                a[j][i] = a[j][i] - d * a[k][i];
                 E[j][i] = E[j][i] - d * E[k][i];
            }
           // b[j] = b[j] - d * b[k];
        }
        printf("\n");
   
//    matrixShow(a);
//    matrixShow(E);
    }  
   
	 matrixShow(a);
   //matrixShow(E);
   
   for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
        	a[i][j]/=a[i][i];
        	E[i][j]/=a[i][i];
		}
	}
   matrixShow(a);
   //matrixShow(E); 
   //////////////////////////////////////////
   
    for (k = n; k >=1; k--) // прямой ход
    {
    	printf("Zanulen %d stolbec\n", k );
    	
        for (j = k - 1; j >=1; j--)
        {
            d = a[j][k] / a[k][k];
            for (i = k; i >=1; i--)
            {
                a[j][i] = a[j][i] - d * a[k][i];
                 E[j][i] = E[j][i] - d * E[k][i];
                 
            }
           // b[j] = b[j] - d * b[k];
        }
        printf("\n");
   cout<<"!";
    matrixShow(a);
		   matrixShow(E);
    }  
    
}
