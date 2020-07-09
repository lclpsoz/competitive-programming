#include <bits/stdc++.h>
using namespace std;

// --
#define x first
#define y second
#define len(x) ((int)x.size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-6;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
    return (int)(((x%m) + m)%m);
}
// --

const int  N = 1e3 + 10;
int qnt[N], vals[N];
multiset<pair<ld, int>> mt;

int main() {
    ld t;
    int n;
    scanf("%Lf %d", &t, &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        // printf("%d\n", x);
        vals[i] = x, qnt[i] = 1;
        mt.insert({-x, i});
    }

    for(int i = 0; i < 505; i++) {
        // for(auto v : mt)
        //     printf("%Lf ", v.first);
        // putchar ('\n');
        pii now = *mt.begin();
        if(cmp((-mt.rbegin()->first)/(-now.first), t) == 1) {
            printf("%d\n", i);
            exit(0);
        }
        mt.erase(mt.find(now));
        ++qnt[now.y];
        now = {-vals[now.y]/qnt[now.y], now.y};
        mt.insert(now);
    }

    return 0;
}