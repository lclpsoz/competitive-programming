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
	return (int)(((x%   m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10;

int n;
int h[N], lef[N], rig[N];
ll dp[N];
vpii q, sorted_h;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        sorted_h.push_back({h[i], i});
    }
    sort(ALL(sorted_h));

    // Left
    for(int i = 1; i <= n; i++) {
        if(q.empty())
            q.push_back({h[i], i});
        else{
            while(LEN(q) and q.back().x < h[i])
                q.pop_back();
            if(LEN(q) and (q.back().x != h[i]))
                lef[i] = q.back().y;
            else if(LEN(q) > 1)
                lef[i] = q[LEN(q)-2].y;
            if(q.empty() or q.back().x > h[i])
                q.push_back({h[i], i});
        }
    }

    q.clear();
    // Right
    for(int i = n; i >= 1; i--) {
        if(q.empty())
            q.push_back({h[i], i});
        else{
            while(LEN(q) and q.back().x < h[i])
                q.pop_back();
            if(LEN(q) and (q.back().x != h[i]))
                rig[i] = q.back().y;
            else if(LEN(q) > 1)
                rig[i] = q[LEN(q)-2].y;
            if(q.empty() or q.back().x > h[i])
                q.push_back({h[i], i});
        }
    }

    // cout << "Left:\n";
    // for(int i = 1; i <= n; i++)
    //     cout << lef[i] << " \n"[i==n];
    // cout << "Right:\n";
    // for(int i = 1; i <= n; i++)
    //     cout << rig[i] << " \n"[i==n];

    while(LEN(sorted_h)) {
        int pos = sorted_h.back().y;
        sorted_h.pop_back();
        ll vl = dp[lef[pos]];
        if(lef[pos])
            vl += pos-lef[pos];

        ll vr = dp[rig[pos]];
        if(rig[pos])
            vr += rig[pos]-pos;
        dp[pos] = max(vl, vr);
    }
    for(int i = 1; i <= n; i++)
        cout << dp[i] << " \n"[i==n];

	return 0;
}
