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

const int N = 5005;

int n;
bool dp[2*N][N];
string sClown, sAcr;

bool isClown (int p) {
	return sClown[p-1] == '1';
}

bool isAcr (int p) {
	return sAcr[p-1] == '1';
}


int main () {
	cin >> n >> sClown >> sAcr;
	
	for (int p = 1; i <)

	return 0;
}
