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

const int N = 1e5 + 10;

int n, m;
vector<int> adj[N];

bool operator== (vector<int> &v1, vector<int> &v2) {
	if (len (v1) != len (v2)) return false;
	for (int i = 0; i < len (v1); i++)
		if(v1[i] != v2[i]) return false;
	return true;
}

bool comp (int a, int b) {
	vector<int> &v1 = adj[a];
	vector<int> &v2 = adj[b];
	if (len (v1) != len (v2)) return false;
	for (int i = 0; i < len (v1); i++)
		if(v1[i] != v2[i]) return false;
	return true;
}

vector<int> z_function(vector<int> s) {
    int n = (int) len (s);
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && comp (s[z[i]], s[i + z[i]]))
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main () {
	vector<int> inp;
	scanf ("%d %d", &n, &m);
	while (m--) {
		int u, v;
		scanf ("%d %d", &u, &v);
		adj[u].push_back ((v - u + n)%n);
		adj[v].push_back ((u - v + n)%n);
	}
	for (int i = 1; i <= n; i++) {
		sort (adj[i].begin(), adj[i].end());
		// printf ("i = %d\n", i);
		// for (int v : adj[i])
		// 	printf ("  %d\n", v);
		inp.push_back (i);
	}
	for (int i = 1; i <= n; i++) inp.push_back (i);
	for (int i = 1; i <= n; i++) inp.push_back (i);
	vector<int> z = z_function (inp);
	// for (int i = 0; i < len (z); i++)
	// 	printf("z[%d] = %d\n", i, z[i]);
	for (int i = 0; i < len (z); i++)
		if (i%n != 0 and z[i] >= n) {
			printf ("Yes\n");
			exit (0);
		}
	printf ("No\n");

	return 0;
}
