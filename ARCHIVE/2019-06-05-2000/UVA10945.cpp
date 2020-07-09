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

bool isPal (string &s) {
	for (int i = 0, j = len (s)-1; i < j;) {
// 		cout << i << ' ' << j << '\n';
		if (s[i] == ' ' or s[i] == '.' or s[i] == ',' or s[i] == '!' or s[i] == '?')
			++i;
		else if (s[j] == ' ' or s[j] == '.' or s[j] == ',' or s[j] == '!' or s[j] == '?')
			--j;
		else if (tolower (s[i]) == tolower (s[j]))
			++i, --j;
		else
			return false;
	}
	
	return true;
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	
	string s;
	while (getline (cin, s), s != "DONE")
		cout << (isPal (s) ? "You won't be eaten!" : "Uh oh..") << '\n';

	return 0;
}
