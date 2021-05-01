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

int cost (string &ans) {
	int ret = 0;
	for (int i = 0; i < LEN(ans)-1; i++)
		for (int j = i+1; j < LEN(ans)-1; j++)
			if (ans[i] == ans[j] and ans[i+1] == ans[j+1])
				ret++;
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, k;
	cin >> n >> k;
	// for (int kk = 2; kk <= 26; kk++)
	// 	for (int n = 1; n <= 3000; n++) {
	if (k == 1) {
		for (int i = 0; i < n; i++)
			cout << "a";
		cout << '\n';
	}
	else {
		string base = "abbaa";
		// int k = kk;
		k-=2;
		string now = "c";
		while (k--) {
			// cerr << base << '\n';
			bitset<500> vis;
			for (int i = 1; i < LEN(base); i++)
				if (base[i-1] == base[i] and !vis[base[i]]) {
					vis[base[i]] = 1;
					base.insert(i, now);
				}
			// cerr << base << '\n';
			vis.reset();
			for (int i = 0; i < LEN(base); i++)
				if (!vis[base[i]]) {
					vis[base[i]] = 1;
					base.insert(i, base.substr(i, 1));
				}
			// cerr << base << '\n';
			++now[0];
			// set<string> st;
			// for (int i = 0; i < LEN(base)-1; i++) {
			// 	string now = base.substr(i, 2);
			// 	cerr << now << '\n';
			// 	if (st.count(now)) {
			// 		cerr << "FAIL!! " << now << '\n';
			// 		cerr << base << '\n';
			// 		exit(0);
			// 	}
			// 	st.insert(now);
			// }
			// // cerr << LEN(st) << ' ' << LEN(base) << '\n';
			// assert(base[0] == base.back());
		}

		string ans1 = "", ans2 = "";
		// for (int i = 0; i < n; i++) {
		// 	ans1.push_back(base[i%LEN(base)]);
		// }
		// ans1 = base[0];
		for (int i = 0; i < n; i++)
			ans1.push_back(base[1+((i)%(LEN(base)-1))]);
		int pos_change = 0;
		// vector<vi> counter(500, vi(500));
		// for (int i = 0; i < n; i++) {
		// 	if (i%LEN(base) == 0 and i > 0) {
		// 		char nxt = 'a';
		// 		int mn = INF<int>;
		// 		char bef = base.back();
		// 		for (char c = 'a'; c < now[0]; c++)
		// 			if (counter[bef][c] < mn) {
		// 				mn = counter[bef][c];
		// 				nxt = c;
		// 			}
		// 		counter[bef][nxt]++;
		// 		while (base[0] != nxt)
		// 			for (int j = 0; j < LEN(base); j++) {
		// 				base[j]++;
		// 				if (base[j] == now[0]) base[j] = 'a';
		// 			}
		// 	}
		// 	ans2.push_back(base[i%LEN(base)]);
		// }

		// cerr << cost(ans1) << " vs " << cost(ans2) <<'\n';
		// cerr << ans1 << ' ' << ans2 << '\n';
		// if( cost(ans1) > cost(ans2)) {
		// 	cout << n << ' ' << k << '\n';
		// 	assert(false);
		// }
		// assert(cost(ans1) < cost(ans2));
		// cerr << ans1 << " vs " << ans2 << '\n';
		cout << ans1 << '\n';
		// cerr << "here\n";
	}

	// map<char, vector<char>> mp;
	// for (int i = 0; i < k; i++)
	// 	for (int j = 0; j < k; j++)
	// 		mp['a'+i].push_back('a'+j);
	// string base = "a";
	// for (int i = 1; i <= k*k; i++)
	// 	if (mp[base[i-1]])

	return 0;
}
