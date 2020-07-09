#include <bits/stdc++.h>
using namespace std;

int adj[110], n;

int mdc(int a, int b){
    int r ;
    while(b){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
   
    int aux, dist, min, mult;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &aux);
        adj[i] = aux;
    }
    
    dist = 1;
	mult = 1;
    for(int i = 1; i <= n; ++i){
        for(int k = adj[i]; k != i; k = adj[k]) {
			printf ("%d\n", k);
            ++dist;
		}
		printf (">>%d\n", dist);
		putchar ('\n');
		mult = (mult * dist)/mdc(mult, dist);
        dist = 1;
    }
    printf("%d\n", mult);
    return 0;
}
