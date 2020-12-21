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

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10;

int lft[N], rig[N];

void solve (int l, int r) {
	if (l >= r)
		return;
	// cerr << l << ' ' << r << '\n';
	for (int sz = 0; l+sz <= r-sz; sz++) {
		if (lft[l+sz] < l and rig[l+sz] > r) {
			solve(l, l+sz-1);
			solve(l+sz+1, r);
			return;
		}
		else if (lft[r-sz] < l and rig[r-sz] > r) {
			solve(l, r-sz-1);
			solve(r-sz+1, r);
			return;
		}
	}
	cout << "N\n";
	exit(0);
}


int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	vi vec(n+1);
	map<int, int> lst;
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
		lft[i] = lst[vec[i]];
		lst[vec[i]] = i;
	}
	lst.clear();
	for (int i = n; i >= 1; i--) {
		if (lst.count(vec[i]))
			rig[i] = lst[vec[i]];
		else
			rig[i] = n+1;
		lst[vec[i]] = i;
	}

	solve(1, n);
	cout << "Y\n";

	return 0;
}
