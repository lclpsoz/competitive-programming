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

const int N = 1e4 + 10;

int link[N], sz[N];

int find (int a) {
	if (a == link[a]) return a;
	return link[a] = find(link[a]);
}

bool same (int a, int b) {
	return find(a) == find(b);
}

void unite (int a, int b) {
	a = find(a), b = find(b);
	if (sz[a] > sz[b]) swap(a, b);
	sz[b] += sz[a];
	link[a] = b;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		sz[i] = 1, link[i] = i;
	vi vec(n);
	for (int &x : vec)
		cin >> x;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (!same(x, y))
			unite(x, y);
	}
	vector<vi> comps(n);
	for (int i = 0; i < n; i++)
		comps[find(i)].push_back(i);
	for (vi &people : comps)
		if (LEN(people)) {
			int now = 0;
			for (int v : people)
				now += vec[v];
			if (now) {
				cout << "IMPOSSIBLE\n";
				exit(0);
			}
		}

	cout << "POSSIBLE\n";

	return 0;
}
