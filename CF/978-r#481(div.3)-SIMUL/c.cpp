#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 2e5+10;

int n, m;
ll sums[MAXN];

int main ()
{
	scanf ("%d %d", &n, &m);
	ll x;
	for (int i = 1; i <= n; i++) {
		scanf ("%lld", &x);
		sums[i] = sums[i-1]+x;
	}

	int pos = 1;
	while (m--) {
		scanf ("%lld", &x);
		while (x > sums[pos]) pos++;
		printf ("%d %lld\n", pos, x-sums[pos-1]);
	}

	return 0;
}
