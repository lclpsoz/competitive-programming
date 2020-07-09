#include <bits/stdc++.h>
using namespace std;

int i;
int numb;
long long unsigned int arr[101];

int main (){

	for (i = 1; i < 101; i++)
		arr[i] = arr[i-1] + pow(i,2);

	scanf("%d", &numb);
	while (numb){

		printf("%llu\n", arr[numb]);
		scanf("%d", &numb);

	}

	return 0;
}
