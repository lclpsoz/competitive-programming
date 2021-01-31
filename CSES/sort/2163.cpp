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

const int N = 2e5 + 10;
int bit[N];

void add (int p, int v) {
	while (p < N) {
		bit[p] += v;
		p += p&-p;
	}
}

int sum (int p) {
	int ret = 0;
	while (p) {
		ret += bit[p];
		p -= p&-p;
	}
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, k;
	cin >> n >> k;

	int cur_n = n;

	for (int i = 1; i <= n; i++)
		add(i, 1);

	vi ans;
	int p = 1;
	for (int i = 1; i <= n; i++) {
		int j = k%cur_n;
		// cerr << "i = " << i << ", p = " << p << ", j = " << j << '\n';
		if (j == 0 and sum(p)-sum(p-1)) {
			add(p, -1);
			ans.push_back(p);
		}
		else if (sum(n) - sum(p-1) > j) {
			int l = p, r = n;
			while (l < r) {
				// cerr << "l, r = " << l << ", " << r << '\n';
				int md = (l+r+1)/2;
				if (sum(md)-sum(p-1) > j)
					r = md-1;
				else
					l = md;
			}
			p = l+1;
			add(p, -1);
			ans.push_back(p);
		}
		else {
			j -= sum(n) - sum(p-1);
			int l = 0, r = n;
			while (l < r) {
				int md = (l+r+1)/2;
				if (sum(md) > j)
					r = md-1;
				else
					l = md;
			}
			p = l+1;
			add(p, -1);
			ans.push_back(p);
		}
		cur_n--;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << " \n"[i==n-1];


	return 0;
}
