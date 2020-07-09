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

const int N = 1e6+10;
const ll INF = - 1e18;

vector<ll> ans;
vector<int> ansPos;
int bef[N];
ll val[N];

int main () {
	ll x;
	int pos = 0;
	while (scanf ("%lld", &x) != EOF) {
		val[pos] = x;
		if (len (ans) == 0) {
			ans.push_back (x);
			ansPos.push_back (pos);
			bef[pos] = -1;
		} else {
			auto it = lower_bound (ans.begin(), ans.end(), x);
			if (it != ans.end()) {
				int p = it - ans.begin();
				ansPos[p] = pos;
				ans[p] = x;
				if (p == 0)
					bef[pos] = -1;
				else
					bef[pos] = ansPos[p-1];
			} else {
				bef[pos] = ansPos.back();
				ansPos.push_back (pos);
				ans.push_back (x);
			}
		}
		
		++pos;
	}
	
	printf ("%d\n-\n", len (ans));
	pos = ansPos.back();
	ans.clear();
	while (pos != -1) {
		ans.push_back (val[pos]);
		pos = bef[pos];
	}
	reverse (ans.begin(), ans.end());
	for (ll v : ans)
		printf ("%lld\n", v);
	
	return 0;
}
