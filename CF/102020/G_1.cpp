#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

int n, m;
vector<ld> da, db;

ld dist(pair<ld, ld> a, pair<ld, ld> b) {
    a.x -= b.x;
    a.y -= b.y;
    return sqrtl(a.x*a.x + a.y*a.y);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    cin >> n >> m;
    pair<ld, ld> lst = {0, 0};
    for (int i = 0; i < n; i++) {
        ld x, y;
        cin >> x >> y;
        if(i)
            da.push_back(dist(lst, {x, y}));
        lst = {x, y};
    }
    for (int i = 0; i < m; i++) {
        ld x, y;
        cin >> x >> y;
        if(i)
            db.push_back(dist(lst, {x, y}));
        lst = {x, y};
    }
    // random_shuffle(da.begin(), da.end());
    // random_shuffle(db.begin(), db.end());
    // printf("A: ");
    ld xx, yy;
    xx = yy = 0;
    for(int i = 0; i < LEN(da); i++) {
        // printf("%Lf%c", da[i], " \n"[i==LEN(da)-1]);
        xx += da[i];
    }
    // printf("B: ");
    for(int i = 0; i < LEN(db); i++) {
        // printf("%Lf%c", db[i], " \n"[i==LEN(db)-1]);
        yy += db[i];
    }
    // assert(cmp(xx, yy) == 0);
    int ans = 0;
    while(LEN(da) and LEN(db)) {
        // cout << LEN(da) << ' ' << LEN(db) << '\n';
        // cout << da.back() << ' ' << db.back() << '\n';
        // cout << '\n';
        if(abs(da.back()-db.back()) < EPS)
            da.pop_back(), db.pop_back();
        else {
            if(cmp(da.back(), db.back()) == 1) {
                da.back() -= db.back();
                ans++;
            } else {
                db.back() -= da.back();
                ans++;
            }
        }
    }
    
    ans += LEN(da) + LEN(db);
    // assert(LEN(da) == LEN(db));
    cout << ans  << '\n';

	return 0;
}
