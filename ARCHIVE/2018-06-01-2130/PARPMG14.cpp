#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int main ()
{
	ll a, b;
	while (scanf ("%lld %lld", &a, &b), a || b) {
		if (a > b) swap (a, b);
		ll _a = sqrtl(a-1);
		ll _b = sqrtl(b);
		// printf ("%lld %lld %lld\n", a-1, _a, _b);
		printf ("%lld\n", b-a+1-(_b-_a));
	}

	return 0;
}
