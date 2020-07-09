#include <bits/stdc++.h>
using namespace std;

int i;
int qnt_nums, qnt_x, x;
int aux, val;

int main (){

	scanf("%d %d %d", &qnt_nums, &qnt_x, &x);

	for (i = 0; i < qnt_nums; i++){

		scanf("%d", &aux);

		if (i < qnt_nums - qnt_x) val += aux;

	}
	val += qnt_x * x;

	printf("%d\n", val);

	return 0;
}
