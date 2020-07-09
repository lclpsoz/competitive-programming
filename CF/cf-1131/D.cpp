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

const int N = 2010;

int n, n1, m1;
int link[N], sz[N];
bool matAdj[2010][2010];
vector<int> adj[N], adjInv[N];
char mat[N][N];
int ans[N];
int qq[N];
int mini;

inline int find (int x) {
	if (x == link[x]) return x;
	return link[x] = find (link[x]);
}

bool same (int x, int y) { return find (x) == find (y); }

void unite (int x, int y) {
	x = find (x);
	y = find (y);
	if (sz[x] > sz[y]) swap (x, y);
	sz[y] += sz[x];
	link[x] = y;
}

int col[N];

bool hasLoop (int v) {
	if (col[v] == 1)
		return true;
	if (col[v] == 2)
		return false;
	col[v] = 1;
	for (int u : adj[v])
		if (hasLoop (u))
			return true;
	col[v] = 2;

	return false;
}

int solve (int v) {
	if (ans[v] != 0) return ans[v];
	for (int u : adjInv[v])
		ans[v] = max (solve (u) + 1, ans[v]);
	return ans[v];
}

int main () {
	scanf ("%d %d", &n1, &m1);
	n = n1 + m1;
	for (int i = 1; i <= n; i++)
		sz[i] = 1, link[i] = i;
	for (int i = 1; i <= n1; i++)
		for (int j = n1+1; j <= n1+m1; j++) {
			scanf (" %c", &mat[i][j]);
			if (mat[i][j] == '=' and !same (i, j))
				unite (i, j);
		}


	for (int i = 1; i <= n1; i++)
		for (int j = n1 + 1; j <= n1+m1; j++)
			if (mat[i][j] != '=' and same (i, j)) {
				printf ("No\n");
				exit (0);
			}
	for (int i = 1; i <= n1; i++)
		for (int j = n1 + 1; j <= n1+m1; j++) {
			int x = find (i), y = find (j);
			if (mat[i][j] == '>') {
				bool &b = matAdj[y][x];
				if (!b) {
					adj[y].push_back (x);
					adjInv[x].push_back (y);
					b = true;
				}
				qq[x]++;
			} else if (mat[i][j] == '<') {
				bool &b = matAdj[x][y];
				if (!b) {
					adj[x].push_back (y);
					adjInv[y].push_back (x);
					b = true;
				}
				qq[y]++;
			}
		}
	
	for (int i = 1; i <= n; i++)
		if (find (i) == i and col[i] == 0)
			if (hasLoop (i)) {
				printf ("No\n");
				exit (0);
			}
	
	for (int i = 1; i <= n; i++)
		if (find(i) == i and qq[i] == 0)
			ans[i] = 1;
	for (int i = 1; i <= n; i++)
		if (find (i) == i and adj[i].empty())
			solve (i);
	printf ("Yes\n");
	for (int i = 1; i <= n1; i++)
		printf ("%d ", ans[find (i)]);
	putchar ('\n');
	for (int j = n1+1; j <= n1+m1; j++)
		printf ("%d ", ans[find(j)]);
	putchar ('\n');

	return 0;
}