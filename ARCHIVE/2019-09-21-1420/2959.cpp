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

const int N = 410;
int n, m, p;

vector<int> adj[N];
bool mat[N][N];

int main () {
    scanf ("%d %d %d", &n, &m, &p);
    while (m--) {
        int a, b;
        scanf ("%d %d", &a, &b);
        adj[a].push_back (b);
        adj[b].push_back (a);
        mat[a][b] = mat[b][a] = true;
    }
    
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (mat[i][k] and mat[k][j]) mat[i][j] = mat[j][i] = true;
                
    while (p--) {
        int a, b;
        scanf ("%d %d", &a, &b);
        printf ("%s\n", mat[a][b] ? "Lets que lets" : "Deu ruim");
    }

	return 0;
}
