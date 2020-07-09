#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;

const int tam = 1e5 + 5;
llu fat[tam];
const int cte = 1e9 + 7;

llu f(int n)
{
    if (n == 1) return 1;
    fat[n] = (n * f(n-1)) % cte;
    return fat[n] % cte;
}

int main()
{
    FILE *arq;
    arq = fopen("out-memo.txt", "w+");
    if (arq == NULL){ printf("Deu ruim\n"); exit(1);}
    else printf("boaaa\n");
    fat[0] = fat[1] = 1;
    fat[tam-5] = f(100000);
    for(int i = 0; i <= tam-5; ++i){
        printf("%llu\n", fat[i]);
        fprintf(arq ,"%llu\n", fat[i]);
    }
    
    return 0;
}
