#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

int arr[MAXN];
int cont;

void shellSort(int tam){

    int gap = (tam+1)/2;
    int it = 0;

    while(gap > 0){
        while(it+gap < tam){
            if(arr[it] > arr[it+gap]){
                swap(arr[it], arr[it+gap]);
                it++;
                cont++;
            }else{
                it += gap; //CONSEGUI
            }
        }
        gap /= 2;
        it = 0;
    }

}

int main(){

    int n;
    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        shellSort(n);
        if(cont%2 == 0) printf("Carlos\n");
        else printf("Marcelo\n");
        cont = 0;
    }

    return 0;
}
