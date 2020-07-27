#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b, c = 0;
	cin >> n >> a >> b;

	int ans = 0;

	while(n--)
	{
		int t; cin >> t;

		if(t == 1)
		{
			if(a) a--;
			else if(b) b--, c++;
			else if(c) c--;
			else ans++;
		}
		else
		{
			if(b) b--;
			else ans += 2;
		}
	}

	cout << ans << endl;

	return 0;
}
