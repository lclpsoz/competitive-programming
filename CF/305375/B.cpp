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

using pvd = pair<int, pair<int, pii>>;

vector<pvd> all_cases[3][201];

int f (int a, int b, int M) {
	return ((a+b)*(a^b))%M;
}

int greedy_get_max (int m, set<pvd> &st) {
	ll ans = 0;
	while (m--) {
		// cerr << "options: ";
		// for (auto _pp : st)
		// 	cerr << _pp.x << ' ';
		// cerr << '\n';
		auto _pp = *st.rbegin();
		auto [val, idxs] = _pp;
		auto [a, bc] = idxs;
		auto [b, c] = bc;
		st.erase(_pp);
		for (auto pp : all_cases[0][a])
			st.erase(pp);
		for (auto pp : all_cases[1][b])
			st.erase(pp);
		for (auto pp : all_cases[2][c])
			st.erase(pp);
		cerr << "  max_now = " << val << ", a = " << a << ", b = " << b << ", c = " << c << '\n';
		ans += val;
	}
	return ans;
}

bool next_val (vi &base, int sz) {
	int p = LEN(base)-1;
	base[p]++;
	while (base[p] == sz-(LEN(base)-1-p)) {
		--p;
		if (p < 0)
			return false;
		base[p]++;
		for (int i = p+1; i < LEN(base); i++)
			base[i] = base[i-1]+1;
	}
}

int brute (int n, int m, set<pvd> &st) {
	vector<pvd> all_data;
	for (pvd val : st)
		all_data.push_back(val);
	int ans = 0;
	vector<vector<bool>> used(3, vector<bool>(n+1));
	vi base;
	for (int i = 0; i < m; i++)
		base.push_back(i);
	do {
		int now = 0;
		for (int i = 0; i < m; i++) {
			auto [val, members] = all_data[base[i]];
			auto [a, bc] = members;
			auto [b, c] = bc;
			// cerr << "\t\ta = " << a << ", b = " << b << ", c = " << c << '\n';
			if (used[0][a] or used[1][b] or used[2][c])
				now = -INF<int>;
			used[0][a] = used[1][b] = used[2][c] = 1;
			now += val;
		}
		if (now == 98) {
			// cerr << "base: ";
			// for (int i = 0; i < LEN(base); i++)
			// 	cerr << base[i] << " \n"[i==LEN(base)-1];
			cerr << '\n';
			for (int i = 0; i < LEN(base); i++) {
				auto [val, abc] = all_data[base[i]];
				auto [a, bc] = abc;
				auto [b, c] = bc;
				cerr << "base[" << i << "] = " << base[i] << ", all_data[base[" << i << "]].x = " << val << ", a = " << a << ", b = " << b << ", c = " << c << '\n';
			}
			cerr << "\tnow = " << now << "\n";
		}
		ans = max(ans, now);
		used = vector<vector<bool>>(3, vector<bool>(n+1));
	} while (next_val(base, LEN(st)));
	return ans;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		for (auto &v : all_cases)
			for (auto &vv : v)
				vv.clear();
		set<pvd> st;
		int n, m, M;
		cin >> n >> m >> M;
		vector<vi> vec(3, vi(n));
		for (int i = 0; i < 3; i++)
			for (int &v : vec[i]) cin >> v;
		// vec[0].swap(vec[1]);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++) {
					int val = f(vec[0][i], vec[1][j], M) + f(vec[0][i], vec[2][k], M);
					pvd pp = {val, {i, {j, k}}};
					all_cases[0][i].push_back(pp);
					all_cases[1][j].push_back(pp);
					all_cases[2][k].push_back(pp);
					st.insert(pp);
				}
		cout << "brute = " << brute(n, m, st) << '\n';
		cout << "greedy_get_max = " << greedy_get_max(m, st) << '\n';
	}

	return 0;
}
