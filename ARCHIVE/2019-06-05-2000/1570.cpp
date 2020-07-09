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

set<int> st;
bool arr[3000000];

int main () {
	for (int i = 1; i <= 1000; i++) {
		st.insert (i*i);
		for (int j = 1; j <= 1000; j++)
			st.insert (i*i + j*j);
	}
	for (int v : st)
		arr[v] = true;

	for (int i = 1; i <= 100; i++)
		printf ("%d:\t%d\n", i, arr[i]);
	
	return 0;
}
