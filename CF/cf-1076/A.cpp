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
vector<char> ans;

int main () {
	string str;
	cin >> n;
	cin >> str;
	bool already = false;
	for (int i = 0; i < n; i++) {
		if (!already and ((i < n-1 and str[i] > str[i+1]) or (i == n-1))) {
			n+=0;
			already = true;
		}
		else
			ans.push_back (str[i]);
	}
	for (char c : ans)
		putchar (c);
	putchar ('\n');

	return 0;
}
