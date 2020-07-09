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

int n;
string s;

int main () {
	cin >> n >> s;
	int ans = 0;
	for(int i = 0; i < n; i+=2) {
		if(s[i] == 'a' and s[i+1] == 'a') {
			++ans;
			s[i] = 'b';
		} else if(s[i] == 'b' and s[i+1] == 'b'){
			++ans;
			s[i] = 'a';
		}
	}
	cout << ans << '\n' << s << '\n';

	return 0;
}
