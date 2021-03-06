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

string a;
vector<pii> vec;

int main () {
	for (int i = 0; i < 4; i++) {
		cin >> a;
		vec.push_back ({len (a)-2, i});
	}
	sort (vec.begin(), vec.end());
	
	if (2*vec[0].x <= vec[1].x and vec[3].x < 2*vec[2].x)
		putchar ('A' + vec[0].y);
	else if (2*vec[0].x > vec[1].x and vec[3].x >= 2*vec[2].x)
		putchar ('A' + vec[3].y);
	else
		putchar ('C');
	putchar ('\n');
	
	return 0;
}
