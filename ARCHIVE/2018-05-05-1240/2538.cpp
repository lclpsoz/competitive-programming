
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int bit[MAXN];
int pi, m;
int cp, na;

int sum (int k)
{
	k = min (MAXN-1, k);
	int r = 0;
	for (; k >= 1; k -= k&-k)
		r += bit[k];
	return r;
}

void add (int k, int x)
{
	for (;k < MAXN; k+=k&-k)
		bit[k] += x;
}

int main ()
{
	while (scanf ("%d %d", &pi, &m) != EOF) {
		memset (bit, 0, sizeof (bit));
		int ans = 0;
		while (m--) {
			scanf ("%d %d", &cp, &na);
			if (sum (cp+pi) - sum (cp-pi-1) <= na) {
				add (cp, 1);
				ans++;
			}
		}

		printf ("%d\n", ans);
	}

	return 0;
}

