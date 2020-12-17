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

	int t;
	cin >> t;
	while (t--) {
		// cerr << "\n t = " << t << '\n';
		int n;
		cin >> n;
		vector<bool> positions(2*n+1);
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			positions[p] = 1;
		}
		vi vec_raw;
		for (int i = 1; i <= 2*n; i++) {
			if (!positions[i]) {
				if (LEN(vec_raw) == 0 or vec_raw.back() > 0)
					vec_raw.push_back(0);
				vec_raw.back()--;
			}
			else {
				if (LEN(vec_raw) == 0 or vec_raw.back() < 0)
					vec_raw.push_back(0);
				vec_raw.back()++;
			}
		}
		set<int> pos_raw, neg_raw;
		for (int i = 0; i < LEN(vec_raw); i++)
			if (vec_raw[i] > 0)
				pos_raw.insert(i);
			else
				neg_raw.insert(i);
		int x_max, x_min;
		
		// cerr << "vec_raw = ";
		// for (int i = 0; i < LEN(vec_raw); i++)
		// 	cerr << vec_raw[i] << " \n"[i==LEN(vec_raw)-1];
		

		vi vec = vec_raw;
		set<int> pos = pos_raw, neg = neg_raw;
		x_min = n; // Getting all MAX first
		for (int i = 0; i < LEN(vec); i++)
			while (vec[i] > 0) {
				auto it = neg.lower_bound(i);
				if (it == neg.end())
					break;
				int delta = min(vec[i], -vec[*it]);
				// cerr << "  i = " << i << ", delta = " << delta << '\n';
				vec[*it] += delta;
				vec[i] -= delta;
				x_min -= delta;
				if (vec[*it] == 0)
					neg.erase(it);
			}

		vec = vec_raw;
		pos = pos_raw, neg = neg_raw;
		x_max = 0; // Getting all MIN first
		for (int i = LEN(vec)-1; i; i--)
			while (vec[i] > 0) {
				auto it = neg.lower_bound(i);
				if (it == neg.begin())
					break;
				it--;
				int delta = min(vec[i], -vec[*it]);
				vec[*it] += delta;
				vec[i] -= delta;
				x_max += delta;
				if (vec[*it] == 0)
					neg.erase(it);
			}

		// cerr << "  x_min = " << x_min << '\n';
		// cerr << "  x_max = " << x_max << '\n';
		cout << x_max - x_min + 1 << '\n';
	}

	return 0;
}
