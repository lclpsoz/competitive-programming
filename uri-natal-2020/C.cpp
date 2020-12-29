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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	vector<pair<string, int>> workers;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int age;
		cin >> age;
		workers.push_back({str, age});
	}
	sort(ALL(workers), [&] (auto a, auto b) {
		if (a.y != b.y) return a.y > b.y;
		return a.x < b.x;
	});

	vector<vector<pair<string, int>>> ans;
	for (int i = 0; i < n/3; i++) {
		vector<pair<string, int>> cur;
		for (int j = i; LEN(cur) < 3; j+=n/3)
			cur.push_back(workers[j]);
		ans.push_back(cur);
		// cout << LEN(ans) << '\n';
	}

	for (int i = 0; i < LEN(ans); i++) {
		cout << "Time " << i+1 << '\n';
		for (auto [name, age] : ans[i])
			cout << name << ' ' << age << '\n';
		cout << '\n';
	}

	return 0;
}
