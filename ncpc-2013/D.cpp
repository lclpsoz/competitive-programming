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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
    return (int)(((x%m) + m)%m);
}
// --

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(10);

    int n; cin >> n;
    vector<pii> pts;
    vector<vector<int>> x(2010);

    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        a += 1000;
        x[a].emplace_back(b);
        if(len(x[a]) > 2)
            x[a] = {min({x[a][0], x[a][1], x[a][2]}), max({x[a][0], x[a][1], x[a][2]})};
        pts.emplace_back(a, b);
    }

    ll ans = 0;

    for(pii p : pts)
    {
        ll a = p.first, b = p.second;
        for(int i = 0; i < 2010; i++)
            if(!x[i].empty())
            {
                ans = max(ans, (a - i) * (a - i) + (b - x[i][0]) * (b - x[i][0]));
                ans = max(ans, (a - i) * (a - i) + (b - x[i].back()) * (b - x[i].back()));
            }
    }

    cout << fixed << sqrt(ans) << '\n';

    return 0;
}