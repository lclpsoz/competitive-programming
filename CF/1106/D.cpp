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
set<int> st;
vector<int> ans;
bool ax[N];

int main () {
    scanf ("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf ("%d %d", &u, &v);
        adj[u].push_back (v);
        adj[v].push_back (u);
    }
    st.insert (1);
    while (!st.empty()) {
        int u = *st.begin(); st.erase (st.begin());
        ans.push_back (u);
        ax[u] = true;
        for (int v : adj[u])
            if (!ax[v])
                st.insert (v);
    }
    for (int v : ans)
        printf ("%d ", v);
    putchar ('\n');

	return 0;
}
