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

int main () {
	ios::sync_with_stdio (false); cin.tie (0);
	cin >> s;
	int q = 0;
	int ans = 0;
	for (char c : s) {
		if (c == '(')
			++q;
		else {
			if (q == 0) ++ans;
			else --q;
		}
	}
	if (q == 0) cout << "Partiu RU!\n";
	else cout << "Ainda temos " << q << " assunto(s) pendente(s)!\n";

	return 0;
}
