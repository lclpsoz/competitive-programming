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

int t, n;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> t;
	while(t--) {
		cin >> n;
		ll total = 0;
		vector<ll> vec(n);
		for (ll &v : vec) {
			cin >> v;
			total += v;
		}
		if (total%n)
			cout << "-1\n";
		else {
			int single_val = total/n;
			vector<vi> operations;
			auto ins_op = [&] (int a, int b, int val) {
				operations.push_back({a, b, val});
				vec[a-1] -= val*a;
				vec[b-1] += val*a;
			};
			for (int i = 2; i <= n; i++) {
				int complement = (i - (vec[i-1]%i))%i;
				if (complement)
					ins_op(1, i, complement);

				if (vec[i-1])
					ins_op(i, 1, vec[i-1]/i);
			}
			for (int j = 2; j <= n; j++) {
				int i = 1;
				int x = single_val - vec[j-1];
				if (x)
					ins_op(1, j, x);
			}
			bool ans = true;
			for (ll v : vec)
				if (v != single_val)
					ans = false;
			if (ans) {
				cout << LEN(operations) << '\n';
				for (vi op : operations)
					for (int i = 0; i < 3; i++)
						cout << op[i] << " \n"[i==2];
			}
			else {
				cout << "-1\n";
			}
		}
	}

	return 0;
}
