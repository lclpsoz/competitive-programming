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

// Interval [st, en]
void mov_fwd (int base, int delta, int st, int en, vi &vec) {
	int pos = en-delta;
	// cerr << "In mov_fwd, pos = " << pos << "\n";
	for (int i = pos; i <= en; i++)
		vec[i] = base++;
	for (int i = pos-1; i >= st; i--)
		vec[i] = base++;
}

void mov_back (int base, int delta, int st, int en, vi &vec) {
	// cerr << "In mov_back\n";
	int pos = st+delta;
	for (int i = pos; i >= st; i--)
		vec[i] = base++;
	for (int i = pos+1; i <= en; i++)
		vec[i] = base++;
}

void brute () {
	int n;
	cin >> n;
	set<int> st;
	vi base;
	for (int i = 0; i < n; i++) base.push_back(i);
	do {
		vi vec = base;
		int ans = 0;
		cerr << "vec =";
		for (int i = 0; i < LEN(vec); i++)
			cerr << ' ' << vec[i];
		cerr << " | ";
		for (int i = 0; i < LEN(vec)-1; i++) {
			int mn = n+1;
			int j = i;
			for (int _j = i; _j < LEN(vec); _j++)
				if (vec[_j] < mn) {
					mn = vec[_j];
					j = _j;
				}
			ans += j-i+1;
			reverse(vec.begin()+i, vec.begin()+j+1);
		}
		cerr << ans << '\n';
		st.insert(ans);
	} while (next_permutation(ALL(base)));
	cerr << "LEN(st) = " << LEN(st) << '\n';
	for (int v : st)
		cerr << v << " ";
	cerr << '\n';
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// vi vec(10);
	// mov_back(1, 2, 0, 9, vec);
	// for (int i = 0; i < LEN(vec); i++)
	// 	cerr << vec[i] << " \n"[i==LEN(vec)-1];

	// brute();


	int tests;
	cin >> tests;
	for (int t = 1; t <= tests; t++) {
		cout << "Case #" << t << ": ";
		int n, cost;
		cin >> n >> cost;
		vi vec(n);
		int mn = n-1;
		int mx = mn + ((n-1)*n)/2;
		if (cost >= n-1 and cost <= mx) {
			cost -= n-1;
			if (cost == 0)
				for (int i = 0; i < n; i++)
					vec[i] = i+1;
			else {
				int st = 0, en = n-1;
				for (int i = 0; cost and i <= n-1; i++) {
					int delta = min(cost, n-i-1);
					// cerr << "i = " << i << ", cost = " << cost << ", delta = " << delta << '\n';
					if (i%2 == 0) {
						mov_back(i+1, delta, st, en, vec);
						en--;
					}
					else {
						mov_fwd(i+1, delta, st, en, vec);
						st++;
					}
					cost -= delta;
				}
			}
			for (int i = 0; i < LEN(vec); i++)
				cout << vec[i] << " \n"[i==LEN(vec)-1];
		}
		else
			cout << "IMPOSSIBLE\n";
	}

	return 0;
}
