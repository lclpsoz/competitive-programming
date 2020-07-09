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

int n, k;
string s;
set<char> d;

int main () {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	cin >> s;
	for(int i = 0; i < k; i++) {
		char c;
		cin >> c;
		d.insert(c);
	}
	
	int lst = 0;
	ll ans = 0;
	for(int i = 0; i < len(s); i++)
		if(d.count(s[i]) == 0) {
			ans += ((i-lst)*1LL*(i-lst+1))/2LL;
			lst = i+1;
		}
	int i = len(s);
	ans += ((i-lst)*1LL*(i-lst+1))/2LL;
	cout << ans << '\n';

	return 0;
}
