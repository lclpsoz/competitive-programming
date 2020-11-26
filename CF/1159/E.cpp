#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

////////////////////////// Solution starts below. //////////////////////////////

vector<int> vec;
set<int> acu;
ordered_set ordSet;

bool check (vector<int> s) {
	bool ok = true;
	for (int i = 0; i < len (s); i++) {
		while (len (acu) and *acu.begin() == i+1) acu.erase (acu.begin());
		if (s[i] <= i+1 or (len (acu) and s[i] > *acu.begin())) {
			ok = false;
			break;
		}
		acu.insert (s[i]);
	}
	acu.clear();
	// cout << s << '\n';
	// if (st.count (ss) and !ok)
	// 	cout << ss << " it's okay, but check say it isn't!!\n";
	// else if (!st.count (ss) and ok)
	// 	cout << ss << " not okay!! Check say it is!!\n";
	return ok;
}

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 2; i <= n+1; i++) {
			int x;
			cin >> x;
			if (x > -1)
				vec.push_back (x);
			else
				vec.push_back (i);
		}
		// cout << "nxt: ";
		// for (int x : vec)
		// 	cout << x << ' ';
		// cout << '\n';
		if (!check (vec))
			cout << -1 << '\n';
		else {
			for (int i = 1; i <= n; i++)
				ordSet.insert (i);
			for (int i = 2; i <= n+1; i++) {
				cout << *ordSet.find_by_order (vec[i-2]-i) << ' ';
				ordSet.erase (ordSet.find_by_order (vec[i-2]-i));
			}
			cout << '\n';
		}
		vec.clear();
	}

	return 0;
}