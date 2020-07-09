#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

int i, j;
int qnt, n, height[MAXN], state[MAXN], ans;

int main ()
{
	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++) {
		ans = 0;
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			getchar ();
			height[j] = getchar ();
		}
		getchar ();
		for (j = 0; j < n; j++)
			state[j] = getchar ();
		for (j = 0; j < n; j++)
			if (height[j] < '3' && state[j] == 'S' || height[j] > '2' && state[j] == 'J')
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}
