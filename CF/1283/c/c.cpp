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
	vi vec(n);
	set<int> not_receive;
	for (int i = 1; i <= n; i++)
		not_receive.insert(i);
	for (int &v : vec) {
		cin >> v;
		not_receive.erase(v);
	}
	vi now;
	for (int i = 0; i < n; i++) {
		if (vec[i] == 0 and not_receive.count(i+1)) {
			now.push_back(i+1);
		}
	}
	if (LEN(now) > 1) {
		int p = 1;
		for (int i : now) {
			if (p == LEN(now)) p = 0;
			vec[i-1] = now[p++];
			not_receive.erase(vec[i-1]);
		}
		for (int i = 0; i < n; i++)
			if (vec[i] == 0) {
				vec[i] = *not_receive.begin();
				not_receive.erase(not_receive.begin());
			}
	}
	else {
		vi positions, not_rec;
		for (int i = 0; i < n; i++)
			if (vec[i] == 0)
				positions.push_back(i+1);
		for (int v : not_receive)
			not_rec.push_back(v);
		
		for (int i = 0; i < LEN(not_rec); i++)
			if (not_rec[i] == positions[i]) {
				if (!i)
					swap(not_rec[i], not_rec[i+1]);
				else
					swap(not_rec[i], not_rec[i-1]);
			}

		for (int i = 0; i < LEN(not_rec); i++)
			vec[positions[i]-1] = not_rec[i];
	}
	for (int i = 0; i < n; i++)
		cout << vec[i] << " \n"[i==n-1];

	return 0;
}
