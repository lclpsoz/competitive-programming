#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6+100;

int i, j;
int qnt, pos, bit;
int lst1[2500], lst2[2500], pairs;
bool arr[MAXN];

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%d", &pos);
		lst1[i] = pos;
		arr[pos] = true;

	}
	for (i = 0; i < qnt; i++){

		scanf("%d", &pos);
		lst2[i] = pos;
		arr[pos] = true;

	}

	for (i = 0; i < qnt; i++)
		for (j = 0; j < qnt; j++){

			bit = lst1[i] ^ lst2[j];
			if (bit < MAXN && arr[bit]) pairs++;

		}

	if (pairs % 2) printf("Koyomi\n");
	else printf("Karen\n");
	return 0;
}
