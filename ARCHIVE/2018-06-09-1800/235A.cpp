#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

ll mdc(ll a, ll b) {
    if(b == 0) return a;
    return mdc(b, a%b);
}
ll mmc (ll a, ll b) { return (a*b) / mdc(a, b); }

int main ()
{
	int n;
	scanf ("%d", &n);
	if (n < 3)
		printf ("%d\n", n);
	else {
		long long x = n;
		if (n%2 == 0)
			printf ("%lld\n", max (mmc(mmc (x, x-1), x-3), (x-1)*(x-2)*(x-3)));
		else
			printf ("%lld\n", x * (x-1) * (x-2));
	}

	return 0;
}
