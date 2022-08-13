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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

template<typename T>
class SegmentTree {
    public:
    int n;
    vector<T> t;

    SegmentTree(const vector<int> &a) {
        n = a.size();
        t = vector<T>(4 * n, 0); 
        build(a, 1, 0, n - 1);
    }
    ~SegmentTree() {

    }

    void build(const vector<int> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    T sum(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            t[v] = new_val;        
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
};

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<int>> pos(26, vector<int>());
	vector<int> pos_ptr(26, -1);
	for (int i = 0; i < n; i++) {
		int c = s[i] - 'a';
		pos[c].push_back(i);
		pos_ptr[c]++;
	}

	vector<int> desloc = vector<int>(n, 0);
	SegmentTree<int> seg = SegmentTree<int>(desloc);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int c = s[i] - 'a';
		int desloc_rel = seg.sum(1, 0, n - 1, pos[c][pos_ptr[c]], n - 1);
		ans += n - 1 - (pos[c][pos_ptr[c]] + desloc_rel);
		seg.update(1, 0, n - 1, pos[c][pos_ptr[c]], 1);
		pos_ptr[c]--;
	}
	cout << ans << endl;

	return 0;
}
