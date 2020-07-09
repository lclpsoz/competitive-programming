#include <bits/stdc++.h>
using namespace std;
void bu (int a[], int n) {
    int k, j, aux;
    for (k = 1; k < n; k++) {
        for (j = 0; j < n - k; j++) 
        {
            if (a[j] < a[j + 1]) 
            {
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}
 
int main()
{
	int qgrd, psc, grd[100], d;
 
	scanf ("%d %d", &qgrd, &psc);
 
	for (int i = 0; i < qgrd; i++)
	{
			scanf("%d", &grd[i]);			
	}
 
	bu(grd, qgrd);
 
	for ( int j = 0; j < psc; j++)
	{	
			scanf ("%d", &d);
			printf ("%d\n", grd[d-1]);
	}
 
	return 0;
 
}
