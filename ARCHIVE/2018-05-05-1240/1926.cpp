#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+100;

int q, x, y;
bool not_prime[MAXN];
int ans[MAXN];

int main ()
{
	not_prime[0] = true;
	not_prime[1] = true;
	for (int i = 2; i*i < MAXN; i++)
		if (!not_prime[i])
			for (int j = i*i; j < MAXN; j+=i)
				not_prime[j] = true;

	for (int i = 2; i < MAXN; i++) {
		ans[i] = ans[i-1];
		if (!not_prime[i] && (!not_prime[i-2] || !not_prime[i+2]))
			ans[i]++;
	}



	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d", &x, &y);
		if (x > y)
			swap (x, y);
		printf ("%d\n", ans[y]-ans[x-1]);
	}

	return 0;
}
