#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n, k, l, c, d, p, nl, np;

int main ()
{
	scanf ("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);
	k *= l;
	k /= nl;
	c *= d;
	p /= np;

	printf ("%d\n", min (min(k, c), p)/n);

	return 0;
}
