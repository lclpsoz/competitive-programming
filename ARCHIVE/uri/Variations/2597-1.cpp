#include <bits/stdc++.h>
using namespace std;

int find_perf_sqrt (const int n){

	int i;
	for (i = 1; i*i <= n; i++);
	return i-1;


}

int main (){

	int i;
	int qnt, val;
	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%d", &val);
		printf("%d\n", val - (int)sqrt(val));

	}


	return 0;
}
