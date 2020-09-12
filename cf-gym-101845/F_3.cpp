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


set<char> teams[110];

int main () {
	 ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    // cout.precision(10);
    int n;
    cin >> n;
    int ans = 0;
    for (int j = 0; j < n; j++) {
        string c;
        map<int, int> mp;
        int big = -1;
        for (int i = 0; i < 3; i++) {
            cin >> c;
            for (int i = 0; i < c.size(); i++) {
                mp[c[i]]++;
            }
        }
        for (int i = 'A'; i <= 'Z'; i++) {
            if (mp[i] == 3)
                teams[j].insert(i);
        }
    }
    int k;
    cin >> k;
    vector<int> qnt(400, k);
    int ans = 0;
    
	return 0;
}
