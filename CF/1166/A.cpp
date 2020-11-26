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
vector<char> vec;

int main () {
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		vec.push_back (str[0]);
	}
	sort (vec.begin(),vec.end());
	char c = vec[0];
	int q = 1;
	ll ans = 0;
	for (int i = 1; i < len (vec); i++) {
		char now = vec[i];
		if (c == now){
			++q;
		} else {
			if (q%2 == 0) {
				q/=2;
				ans += 2*(q*(q-1))/2;
			} else {
				q/=2;
				ans += (q*(q-1))/2 + ((q+1)*(q))/2;
			}
			q = 1;
		}
		c = now;
	}
	if (q) {
		if (q%2 == 0) {
			q/=2;
			ans += 2*(q*(q-1))/2;
		} else {
			q/=2;
			ans += (q*(q-1))/2 + ((q+1)*(q))/2;
		}
	}
	cout << ans << '\n';

	return 0;
}
