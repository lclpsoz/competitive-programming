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

const int NM = 210;

int n, m;
int mat[NM][NM];
int mat2[NM][NM];
vector<pii> lin, col;

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf ("%d", &mat[i][j]);
			mat2[i][j] = mat[i][j];
		}
	
	vector<int> vec;
	for (int i = 0; i < n; i++)
		 vec.push_back (mat[i][0]);
	sort (vec.begin(), vec.end());
	for (int i = 0; i < n; i++) {
		if (vec[i] == mat[i][0])
			continue;
		for (int j = i+1; j < n; j++)
			if (vec[i] == mat[j][0]) {
				swap (mat[i][0], mat[j][0]);
				lin.push_back ({i+1, j+1});
				break;
			}
	}
	
	vec.clear();
	
	for (int i = 0; i < m; i++)
		 vec.push_back (mat2[0][i]);
	sort (vec.begin(), vec.end());
	for (int i = 0; i < m; i++) {
		if (vec[i] == mat2[0][i])
			continue;
		for (int j = i+1; j < m; j++)
			if (vec[i] == mat2[0][j]) {
				swap (mat2[0][i], mat2[0][j]);
				col.push_back ({i+1, j+1});
				break;
			}
	}
	
	printf ("%d\n", len (col) + len (lin));
	for (pii p : lin)
		printf ("L %d %d\n", p.x, p.y);
	for (pii p : col)
		printf ("C %d %d\n", p.x, p.y);

	return 0;
}
