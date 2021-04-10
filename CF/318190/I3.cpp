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

void print_vec(const vector<long long> &a) {
	if (a.size() == 0)
		return;

	for (int i = 0; i < a.size(); i++) {
		if (a[i] > 1e9) {
			cout << "IMPOSSIBLE" << endl;
			exit(0);
		}
	}

	cout << a[0];
	for (int i = 1; i < a.size(); i++) {
		cout << " " << a[i];
	}
	cout << endl;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;

	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	reverse(b.begin(), b.end());
	vector<long long> elems;
	elems.push_back(1);

	//print_vec(elems);

	for (int i = 0; i < n - 1; i++) {
		vector<long long> new_elems;
		new_elems.push_back(1);

		if (b[i] == 0)
			reverse(elems.begin(), elems.end());
		for (long long elem: elems)
			new_elems.push_back(new_elems[new_elems.size() - 1] + elem);
		if (b[i] == 0)
			reverse(new_elems.begin(), new_elems.end());

		elems = new_elems;

		//print_vec(elems);
	}

	print_vec(elems);

	return 0;
}
