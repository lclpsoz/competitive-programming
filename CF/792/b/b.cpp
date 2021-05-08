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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, k;
	cin >> n >> k;
	vi vec(k);
	for (int &x : vec)
		cin >> x;
	vi children(n);
	int total = n;
	vi ans;
	int leader = 0;
	for (int i = 1; i <= k; i++) {
		// cerr << "i = " << i << '\n';
		int now = vec[i-1]%total;
		if (now == 0) now = total;
		int dead = leader+1;
		if (dead == LEN(children)) dead = 0;
		while (children[dead] == -1) {
			++dead;
			if (dead == LEN(children)) dead = 0;
		}
		for (int j = 0; j < now-1; j++) {
			// cerr << j << ": " << dead << '\n';
			++dead;
			if (dead == LEN(children)) dead = 0;
			while (children[dead] == -1) {
				++dead;
				if (dead == LEN(children)) dead = 0;
			}
		}
		ans.push_back(dead+1);
		children[dead] = -1;
		total--;
		++dead;
		if (dead == LEN(children)) dead = 0;
		while (children[dead] == -1) {
			++dead;
			if (dead == LEN(children)) dead = 0;
		}
		leader = dead;
	}
	for (int i = 0; i < LEN(ans); i++)
		cout << ans[i] << " \n"[i==LEN(ans)-1];

	return 0;
}
