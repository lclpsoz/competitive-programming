#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt, members, val, mid;

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%d", &members);

		for (j = 0; j < members; j++){

			scanf("%d", &val);

			if (members / 2 == j) mid = val;

		}

		printf("Case %d: %d\n", i+1, mid);

	}

	return 0;
}
