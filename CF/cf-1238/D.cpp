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

string s;
int n;
vector<int> vec;

int main () {
	ios::sync_with_stdio (false);
	cin >> n >> s;
	vec.push_back (1);
	for (int i = 1; i < n; i++)
		if (s[i-1] == s[i])
			vec.back()++;
		else
			vec.push_back (1);
	ll ans = (n*1LL*(n+1))/2 - n;
	ll sub = 0;
	if (len (vec) > 1)
		for (int i = 0; i < len (vec); i++) {
			if (i == 0) {
				sub += vec[i+1];
			} else if (i == len(vec)-1) {
				sub += vec[i-1] - 1;
			} else
				sub += vec[i-1] + vec[i+1] - 1;
		}
	// cout << "sub = " << sub << '\n';
	cout << ans - sub << '\n';

	return 0;
}