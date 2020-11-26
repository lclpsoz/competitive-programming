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

const ll INF = 1e18;
const int N = 1e5 + 10;

int n, m, k;
vector<pii> vec;
pii segInt[N];
int segD[N], segW[N];
int coins[N], jmp[N];
set<pair<pii, int>> st;
ll dp[N][202];

ll solve (int p, int q) {
    //printf ("p: %d, q: %d\n", p, q);
    if (q < 0)
        return INF;
    if (p > n)
        return 0;
    
    ll &ret = dp[p][q];
    if (ret != -1) return ret;
    dp[p][q] = min (solve (p+1, q-1), solve (jmp[p], q) + coins[p]);
        
    return ret;
}

int main () {
    scanf ("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        int s, t, d, w;
        scanf ("%d %d %d %d", &s, &t, &d, &w);
        segInt[i] = {s, t};
        segD[i] = d;
        segW[i] = w;
        vec.push_back ({s, i});
    }
    
    sort (vec.begin(), vec.end(), greater<pii>());
//     printf ("Vec:\n");
//     for (auto p : vec)
//         printf ("%d %d\n", p.x, p.y);
//     putchar ('\n');
    for (int i = 1; i <= n; i++) {
        jmp[i] = i+1;
        while (!vec.empty() and vec.back().x == i) {
            int p = vec.back().y;
            vec.pop_back();
//             printf ("((%d, %d), %d | %d\n", -segW[p], -segD[p], p, segInt[p].y);
            st.insert ({{-segW[p], -segD[p]}, p});
        }
        if (!st.empty())
//         printf ("st.begin()->y: %d\n", (*st.begin()).y);
        while (!st.empty() and segInt[(*st.begin()).y].y < i) st.erase (st.begin());
//         printf ("len(st)[%d] = %d\n", i, len (st));
        
        if (!st.empty()) {
            int p = st.begin()->y;
            coins[i] = segW[p];
            jmp[i] = segD[p] + 1;
        }
    }
//     putchar ('\n');
//     for (int i = 1; i <= n; i++)
//         printf ("%2d: (jmp: %d, c: %d)\n", i, jmp[i], coins[i]);
    
    memset (dp, -1, sizeof dp);
    printf ("%lld\n", solve (1, m));
    

	return 0;
}
