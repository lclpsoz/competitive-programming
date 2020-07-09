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
char mat[55][55];
int stX, stY, enX, enY;
int link[10000], sz[10000];

int operator- (const pii &l, const pii &r) {
	int rr = l.x - r.x;
	int c = l.y - r.y;
	return rr*rr + c*c;
}

int find (int a) {
	if (link[a] == a) return a;
	return link[a] = find (link[a]);
}

bool same (int a, int b) { return find (a) == find (b); }

void unite (int a, int b) {
	a = find (a), b = find (b);
	if (a == b) return;
	if (sz[a] > sz[b]) swap (a, b);
	sz[b] += a;
	link[a] = b;
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n*n + n; i++)
		link[i] = i, sz[i] = 1;
	scanf ("%d %d", &stX, &stY);
	scanf ("%d %d", &enX, &enY);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			scanf (" %c", &mat[i][j]);
			// putchar (mat[i][j]);
		}
		// putchar ('\n');
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (mat[i][j] == '0')
				for (int k = -1; k <= 1; k++)
					for (int l = -1; l <= 1; l++)
						if (abs(k)+abs(l) == 1 and mat[i+k][j+l] == '0')
							unite (i*n + j, (i+k)*n + (j+l));

	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= n; j++)
	// 		printf ("%d %d -> %d\n", i, j, find (n*i + j));

	int now = find (stX*n + stY);
	int nxt = find (enX*n + enY);
	if (now == nxt)
		printf ("0\n");
	else {
		vector<pii> st, en;
		for (int i = 2; i <= n*n + n; i++)
			if (find (i) == now)
				st.push_back ({(i-1)/n, ((i-1)%n) + 1});
			else if (find (i) == nxt)
				en.push_back ({(i-1)/n, ((i-1)%n) + 1});
		// printf ("here!\n");
		int ans = 1e9;
		for (pii p1 : st)
			for (pii p2 : en) {
				// printf ("(%d, %d) x (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
				ans = min (ans, p1 - p2);
			}
		printf ("%d\n", ans);
	}

	return 0;
}
