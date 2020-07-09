#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

int i;
int go, back, id;
bool divers[MAXN], test;

int main (){

	while (scanf("%d %d", &go, &back) != EOF){

		for (i = 0; i < back; i++){

			scanf("%d", &id);
			divers[id] = true;

		}

		if (go == back) puts("*");
		else{

			for (i = 1;i <= go; i++)
				if (!divers[i]) printf("%d ", i);

			printf("\n");

		}
		for (i = 0; i < MAXN; i++) divers[i] = false;

	}

	return 0;
}
