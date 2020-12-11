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



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string a, b;
        cin >> a >> b;
        vector<int> pos[26]; 
        vector<vector<int>> cnt(m, vector<int>(26, 0));
        for (int i = 0; i < m; i++) {
            int c = b[i] - 'a';
            pos[c].push_back(i);
            for (int j = 0; j < 26; j++)
                if (i > 0) cnt[i][j] = cnt[i - 1][j];
            cnt[i][c]++;
        }
        // O(n + m)
        long long ans = 0;
        if (k != 1) {
            map<pair<int, int>, bool> rep;
            for (int i = 0; i + k <= n; i++) {
                cout << "i: " << i << endl;
                int c, f;
                c = a[i] - 'a';
                f = a[i + k - 1] - 'a';
                if (rep[{c, f}]) continue;
                rep[{c, f}] = true;
                for (int ind : pos[c]) {
                    cout << ind << endl;
                    ans += cnt[m - 1][f] - cnt[ind][f];
                }
            }
        } else {
            map<int, int> rep;
            for (int i = 0; i < n; i++) {
                int c = a[i] - 'a';
                if (rep[c])
                    continue;
                rep[c]++;
                for (int ind : pos[c]) {
                    cout << m << " " << ind << endl;
                    ans += m - ind;
                }
            }
        }
        cout << "resp: " << ans << endl;
    }

	return 0;
}
