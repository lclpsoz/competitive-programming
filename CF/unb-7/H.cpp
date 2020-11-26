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

int n, l;
vector<string> vec;
int base[10];
string conv = "ACGT";

int main () {
	cin >> n >> l;
	string s;
	while (n--) {
		cin >> s;
		vec.push_back (s);
	}

	int ans = 1234;
	string sAns = s;
	while (base[l] == 0) {
		// for (int i = 0; i < l; i++)
		// 	printf ("%d", base[i]);
		// 	putchar ('\n');
		int maxi = -1;
		for (string s : vec) {
			int now = 0;
			for (int i = 0; i < l; i++)
				if (conv[base[i]] != s[i]) ++now;
			maxi = max (maxi, now);
		}
		if (maxi < ans) {
			ans = maxi;
			for (int i = 0; i < l; i++)
				sAns[i] = conv[base[i]];
		}
		
		base[0]++;
		int p = 0;
		while (base[p] == 4) {
			base[p] = 0;
			++p;
			base[p]++;
		}

	}

	cout << sAns << '\n' << ans << '\n';

	return 0;
}
