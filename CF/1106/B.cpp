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
int a[N], c[N];

map<int, vector<int>> mp;

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &c[i]);
        mp[c[i]].push_back (i);
    }
    
    vector<ll> ans;
    for (int i = 1; i <= m; i++) {
        if (mp.empty()) {
            ans.push_back (0);
            continue;
        }
        ll now = 0;
        ll t, d;
        scanf ("%lld %lld", &t, &d);
        if (a[t] >= d) {
            a[t] -= d;
            now += c[t] * d;
            d = 0;
        } else {
            now += c[t]*1LL*a[t];
            d -= a[t];
            a[t] = 0;
            while (d and !mp.empty()) {
//                 printf ("d: %lld\n", d);
                int ax = (*mp.begin()).x;
//                 printf (" ax = %d\n", ax);
                if (mp[ax].empty()) {
                    mp.erase (ax);
//                     printf (" EMPTY!\n");
                } else {
                    int di = mp[ax].back();
                    int use = min (d, (ll)a[di]);
                    now += use * 1LL * c[di];
                    a[di] -= use;
                    d -= use;
                    if (a[di] == 0)
                        mp[ax].pop_back();
                }
            }
        }
        if (d)
            ans.push_back (0);
        else
            ans.push_back (now);
    }
    for (ll v : ans)
        printf ("%lld\n", v);
        

	return 0;
}
