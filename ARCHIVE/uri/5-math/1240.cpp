#include <bits/stdc++.h>

const int MAXN = 1e3;

int i, j;
int qnt;
char a[MAXN], b[MAXN];
bool test;

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf("%s %s", a, b);

		test = true;
		j = 1;
		if (strlen(b) > strlen(a))
			test = false;
		else
			while (strlen(b) - j + 1)
				if (b[strlen(b) - j] != a[strlen(a) - j++])
					test = false;

		if (test)
			printf("encaixa\n");
		else
			printf("nao encaixa\n");

	}

	return 0;
}
