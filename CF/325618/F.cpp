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

vector<string> comp;

int get_id (string &s) {
	return lower_bound(ALL(comp), s) - comp.begin();
}

int main () {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	string st, en;
	set<string> base;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		base.insert(s);
		if (i == 1) st = s;
		else if (i == n) en = s;
		comp.push_back(s);
		string ax = s;
		for (int j = 0; j < LEN(s); j++) {
			char c = ax[j];
			ax[j] = '#';
			comp.push_back(ax);
			ax[j] = c;
		}
	}
	sort(ALL(comp));
	comp.resize(unique(ALL(comp)) - comp.begin());
	vector<vi> mp(LEN(comp));	

	for (string s : base) {
		// if (!s.count('#')) {
			// cerr << "s = " << s << '\n';
			int id_base = get_id(s);
			for (int j = 0; j < LEN(s); j++) {
				char c = s[j];
				s[j] = '#';
				int id_ax = get_id(s);
				mp[id_ax].push_back(id_base);
				// cerr << "  ax = " << ax << ", s = " << s << '\n';
				s[j] = c;
			}
		// }
	}


	//----- BFS
	vi bfs;
	vi bef(LEN(comp), -1);
	bfs.push_back(get_id(st));
	bef[get_id(st)] = -2;
	// cerr << "bfs = " << LEN(bfs) << '\n';
	// for (auto [x, y] : mp)
	// 	cerr << x << ": " << y << '\n';
	for (int i = 0; i < LEN(bfs); i++) {
		// cerr << "\ni = " << i << '\n';
		int id_now = bfs[i];
		string now = comp[id_now];
		// cerr << "  | now = " << now << '\n';
		string ax = now;
		// cerr << "now = " << now << '\n';
		for (int j = 0; j < LEN(ax); j++) {
			char c = ax[j];
			ax[j] = '#';
			// cerr << "ax = " << ax << ", " << mp.count(ax) << '\n';
			// cerr << "mp[v#na] -> " << mp.count("v#na") << '\n';
			int id_ax = get_id(ax);
			if (LEN(mp[id_ax])) {
				for (int nxt : mp[id_ax]) {
					if (bef[nxt] == -1) {
						// cerr << "   nxt = " << comp[nxt] << '\n';
						// cerr << "  IN MAP!!\n";
						bfs.push_back(nxt);
						bef[nxt] = id_now;
					}
				}
			}
			ax[j] = c;
		}
	}
	if (bef[get_id(en)] == -1)
		cout << "FAIL\n";
	else {
		vi ans;
		int val = get_id(en);
		while (bef[val]) {
			ans.push_back(val);
			if (bef[val] == -2) break;
			val = bef[val];
		}
		reverse(ALL(ans));
		cout << LEN(ans) << '\n';
		for (int x : ans)
			cout << comp[x] << '\n';
	}

	return 0;
}
