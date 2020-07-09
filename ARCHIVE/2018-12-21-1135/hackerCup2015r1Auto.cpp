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

const int N = 1e6+100, MK = 29;

int tests, n;
int trie[N][30], lst;
int ans;
string str;

void qry (int p, int pos, bool notIn) {
	if (pos == len (str)) {
		if (notIn) ans += len (str);
		trie[p][MK] = true;
		return;
	}
	int v = str[pos]-'a';
	if (trie[p][v] == 0) {
		if (notIn) ans += pos+1;
		notIn = false;
		trie[p][v] = ++lst;
	}
	
	qry (trie[p][v], pos+1, notIn);
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
    cin >> tests;
	for (int t = 1; t <= tests; t++) {
		memset (trie, 0, sizeof trie);
		lst = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> str;
			qry (0, 0, true);
		}
		cout << "Case #" << t << ": " << ans << '\n';
		ans = 0;
    }

	return 0;
}
