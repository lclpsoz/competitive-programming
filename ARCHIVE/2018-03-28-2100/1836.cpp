#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e4;

int i;
int qnt, lvl, base, ind, effort, ans;
char str[MAXS];

int main ()
{
	scanf ("%d", &qnt);
	for (i = 0; i < qnt; i++) {
		scanf ("%s %d", str, &lvl);
		printf("Caso #%d: %s nivel %d\n", i+1, str, lvl);
		scanf("%d %d %d", &base, &ind, &effort);
		ans = (((ind + base + (sqrt (effort)/8.0) + 50)*lvl) / 50.0) + 10;
		printf("HP: %d\n", ans);
		scanf("%d %d %d", &base, &ind, &effort);
		ans = (((ind + base + (sqrt (effort)/8.0))*lvl) / 50.0) + 5;
		printf("AT: %d\n", ans);
		scanf("%d %d %d", &base, &ind, &effort);
		ans = (((ind + base + (sqrt (effort)/8.0))*lvl) / 50.0) + 5;
		printf("DF: %d\n", ans);
		scanf("%d %d %d", &base, &ind, &effort);
		ans = (((ind + base + (sqrt (effort)/8.0))*lvl) / 50.0) + 5;
		printf("SP: %d\n", ans);

	}

	return 0;
}
