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

const int N = 1e5+10;

int n;
char str[N];
vector<char> vec;

int main () {
	scanf ("%s", str);
	n = strlen (str);
	int qnt = 0;
	for (int i = 0; i < n; i++) {
		if (vec.empty() or vec.back() != str[i]) vec.push_back (str[i]);
		else if (!vec.empty() and vec.back () == str[i]) {
			++qnt;
			vec.pop_back ();
		}
	}
	printf ("%s\n", qnt&1 ? "Yes" : "No");
	
	return 0;
}
