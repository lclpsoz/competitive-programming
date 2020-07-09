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

int ans;
int n, m;
char mat[105][105];

void remCol (int p) {
	++ans;
	for (int i = 0; i < n; i++)
		mat[i][p] = '-';
}

bool cmpLines (int p) {
	for (int i = 0; i < m; i++)
		if (mat[p][i] < mat[p+1][i]) return true;
		else if (mat[p][i] > mat[p+1][i]) {
			remCol (i);
			return false;
		}
		
	return true; // Equals
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf (" %c", &mat[i][j]);
	bool test = false;
	while (!test) {
		test = true;
		for (int i = 0; test and i < n-1; i++)
			test = cmpLines (i);
	}
	
	printf ("%d\n", ans);

	return 0;
}
