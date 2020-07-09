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
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

string str;
ll a[5];
ll n[5], p[5], r;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	
	cin >> str;
	cin >> n[0] >> n[1] >> n[2];
	cin >> p[0] >> p[1] >> p[2];
	cin >> r;
	for (int i = 0; i < len (str); i++)
		if (str[i] == 'B')
			++a[0];
		else if (str[i] == 'S')
			++a[1];
		else
			++a[2];

	ll ans = 0;
	for (int i = 0; i < 100; i++) {
		if (n[0] >= a[0] and 
			n[1] >= a[1] and
			n[2] >= a[2]) {
			++ans;
			for (int j = 0; j < 3; j++)
				n[j] -= a[j];
		} else {
			ll cost = 0;
			for (int j = 0; j < 3; j++)
				cost += max (0LL, (a[j]-n[j])*p[j]);
			if (cost <= r) {
				for (int j = 0; j < 3; j++)
					n[j] = max (0LL, n[j]-a[j]);
				r -= cost;
				++ans;
			} else
				break;
		}
		if (!n[0] and !n[1] and !n[2])
			break;
	}
	ll cost = 0;
	for (int i = 0; i < 3; i++)
		cost += p[i]*a[i];
	ans += r/cost;
	
	cout << ans << '\n';
	

	return 0;
}
