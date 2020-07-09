#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7+100;

long long dif[MAXN];
int n, m;
int a, b, k;

int main ()
{
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf ("%d %d %d", &a, &b, &k);
		dif[a-1]+=k;
		dif[b]-=k;
	}

	long long ans = 0, aux = 0;;
	for (int i = 0; i < n; i++) {
		// printf ("%d: %d\n", i, dif[i]);
		aux += dif[i];
		ans = max (ans, aux);
	}
	printf ("%lld\n", ans);

	return 0;
}
