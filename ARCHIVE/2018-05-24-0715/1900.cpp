#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int n, x;
long long acu;
map<ll, ll> mp;

int main ()
{
	scanf ("%d", &n);
	while (n--) {
		scanf ("%d", &x);
		acu += x;
		mp[acu]++;
	}
	ll ans = 0;
	ans += mp[0];
	for (auto &pp : mp)
		if (pp.y > 1) {
			pp.y--;
			ans += ((pp.y+1)*pp.y)/2;
			pp.y = 0;
		}

	printf ("%lld\n", ans);

	return 0;
}
