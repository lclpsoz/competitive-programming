#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt_t, qnt_s, sheep;
set<int> sheeps;

int main (){

	scanf("%d", &qnt_t);
	for (i = 0; i < qnt_t; i++){

		scanf("%d", &qnt_s);
		for (j = 0; j < qnt_s; j++){

			scanf("%d", &sheep);
			sheeps.insert(sheep);

		}

		printf("%lu\n", sheeps.size());
		sheeps.clear();

	}

	return 0;
}
