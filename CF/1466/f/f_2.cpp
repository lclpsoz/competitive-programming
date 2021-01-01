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
const int MOD = 1e9 + 7;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return x%m;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

mt19937 rng (( llu ) chrono :: steady_clock :: now () . time_since_epoch () . count () ) ;

struct Dsu {
	int n;
	vi sz, link, edge;

	Dsu (int _n) : n(_n) {
		sz = vi(n+1);
		link = vi(n+1);
		edge = vi(n+1, -1);
		for (int i = 1; i <= n; i++)
			link[i] = i, sz[i] = 1;
	}

	int find (int v) {
		if (v == link[v]) return v;
		return find(link[v]);
	}

	bool same (int u, int v) {
		return find(u) == find(v);
	}

	void unite (int u, int v, int idx) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		if (sz[u] > sz[v]) swap(u, v);
		sz[v] += sz[u];
		link[u] = v;
		edge[u] = idx;
	}
};

vector<vi> solve (int n, int m, vpii &inp) {
	set<int> active;
	vi ans;
	vi lft(n+1), rig(n+1);
	vi indexes_two;
	vi val_one_to_idx(m+1);
	for (int i = 1; i <= n; i++) {
		auto [x, y] = inp[i-1];
		if (y == -1) {
			if (active.insert(x).y) {
				// ans.push_back(i);
				val_one_to_idx[x] = i;
			}
		}
		else {
			indexes_two.push_back(i);
			lft[i] = x;
			rig[i] = y;
		}
	}

	Dsu dsu(m+1);
	for (int idx : indexes_two) {
		int x = lft[idx];
		int y = rig[idx];
		if (!dsu.same(x, y)) {
			// cerr << "unite: " << x << " + " << y << '\n';
			dsu.unite(x, y, idx);
		}
	}

	vector<bool> vis(m+1);
	vector<vector<pii>> adj(m+1);
	for (int i = 1; i <= m; i++) {
		int comp = dsu.find(i);
			// cerr << "  i = " << i << ", comp = " << comp << ", dsu.sz[comp] = " << dsu.sz[comp] << '\n';
		if (!vis[comp] and dsu.sz[comp] > 1 and active.count(i)) {
			vis[comp] = 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		int comp = dsu.find(i);
		if (vis[comp] and dsu.sz[comp] > 1 and comp != i) {
			int v = i;
			int to = dsu.link[i];
			adj[v].push_back({to, dsu.edge[i]});
			adj[to].push_back({v, dsu.edge[i]});
		}
	}

	set<pii> dij;
	vis.assign(LEN(vis), false);
	for (int i = 1; i <= m; i++)
		if (active.count(i)) {
			dij.insert({val_one_to_idx[i], i});
		}

	while (LEN(dij)) {
		auto [idx, v] = *dij.begin();
		dij.erase(dij.begin());
		if (vis[v]) continue;
		// cerr << "v = " << v << '\n';
		ans.push_back(idx);
		vis[v] = 1;
		active.insert(v);
		for (auto [to, idx] : adj[v])
			if (!vis[to])
				dij.insert({idx, to});
	}
	// cerr << "LEN(ans) = " << LEN(ans) << ", LEN(active) = " << LEN(active) << '\n';

	ll mult = 1;
	int n_comp = LEN(active);
	for (int i = 1; i <= m; i++) {
		// cerr << "dsu_sz[" << i << "] = " << dsu.sz[i] << '\n';
		int comp = dsu.find(i);
		if (!vis[comp] and dsu.link[i] == i and dsu.sz[i] > 1) {
			// n_comp++;
			int qnt = dsu.sz[i];
			int p2 = 1;
			for (int i = 0; i < qnt-1; i++)
				p2 = mod(p2*2);
			mult = mod(mult * 1LL * p2);
		}

		if (!vis[comp] and dsu.sz[comp] and i != comp) {
			assert(dsu.edge[i] >= 1);
			ans.push_back(dsu.edge[i]);
		}
	}


	ll sz_t = 1;
	for (int i = 0; i < n_comp; i++)
		sz_t = mod(sz_t*2);
	sz_t = mod(sz_t * mult);
	sort(ALL(ans));
	// sz_t++;
	// cout << sz_t << ' ' << LEN(ans) << '\n';
	// for (int i = 0; i < LEN(ans); i++)
	// 	cout << ans[i] << " \n"[i == LEN(ans)-1];
	return {{(int)sz_t}, {LEN(ans)}, ans};
}

vector<vi> solve_slow (int n, int m, vpii &inp);

void solve_read () {
	int n, m;
	cin >> n >> m;
	vpii inp(n, {-1, -1});
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k >> inp[i].x;
		if (k == 2)
			cin >> inp[i].y;
	}

	vector<vi> ans = solve(n, m, inp);
	cout << ans[0][0] << ' ' << ans[1][0] << '\n';
	vi &vec = ans[2];
	for (int i = 0; i < LEN(vec); i++)
		cout << vec[i] << " \n"[i==LEN(vec)-1];
}

bool case_brute ();

bool case_solve_slow () {
	uniform_int_distribution<int> dist_n(1, 10);
	uniform_int_distribution<int> dist_m(2, 10);
	int n = dist_n(rng);
	int m = dist_m(rng);
	uniform_int_distribution<int> dist_val(1, m);
	uniform_int_distribution<int> dist_bool(0, 1);
	cerr << n << ' ' << m << '\n';
	vpii inp(n);
	for (int i = 0; i < n; i++) {
		inp[i].x = dist_val(rng);
		if (dist_bool(rng)%2) {
			do {
				inp[i].y = dist_val(rng);
			} while (inp[i].y == inp[i].x);
		}
		else
			inp[i].y = -1;
	}
	
	vector<vi> ans = solve(n, m, inp);
	vector<vi> ans_slow = solve_slow(n, m, inp);
	bool verify_vals = true;
	for (int i = 0; i < min(LEN(ans[2]), LEN(ans_slow[2])); i++)
		verify_vals = verify_vals and (ans[2][i] == ans_slow[2][i]);
	if (!verify_vals or ans[0][0] != ans_slow[0][0] or ans[1][0] != ans_slow[1][0]) {
		cout << "SOLVE: " << ans[0][0] << ", " << ans[1][0] << '\n';
		cout << "BRUTE: " << ans_slow[0][0] << ", " << ans_slow[1][0] << '\n';
		// cout << "ALL:\n";
		// for (int v : all_possible)
		// 	cout << "\t" << bitset<6>(v) << '\n';
		cout << "CASE:\n";
		cout << n << ' ' << m << '\n';
		for (auto [x, y] : inp) {
			if (y == -1)
				cout << 1 << ' ' << x << '\n';
			else
				cout << 2 << ' ' << x << ' ' << y << '\n';	
		}
		return false;
	}
	return true;
}

void test_brute () {
	while (case_brute());
	exit(0);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// test_brute();

	solve_read();

	return 0;
}



vector<vi> solve_slow (int n, int m, vpii &inp) {
	set<int> process;
	vi ans;
	set<pii> lft, rig;
	vi other_lft(n+1);
	vi other_rig(n+1);
	vi indexes_two;
	for (int i = 1; i <= n; i++) {
		auto [x, y] = inp[i-1];
		if (y == -1) {
			if (process.insert(x).y)
				ans.push_back(i);
		}
		else {
			indexes_two.push_back(i);
			lft.insert({x, i});
			rig.insert({y, i});
			other_lft[i] = y;
			other_rig[i] = x;
		}
	}
	
	set<int> nxt, active;
	do {
		for (int v : process) {
			auto ins_val = [&] (auto &it, set<pii> &st, vi &other_val) {
				vpii to_remove;
				while (it != st.end() and it->x == v) {
					auto [val, idx] = *it;
					to_remove.push_back(*it);
					int new_val = other_val[idx];
					if (!active.count(new_val) and !process.count(new_val) and !nxt.count(new_val)) {
						ans.push_back(idx);
						nxt.insert(new_val);
					}
					it++;
				}
				for (pii p : to_remove)
					st.erase(p);
			};

			auto it_lft = lft.lower_bound({v, -1});
			ins_val(it_lft, lft, other_lft);

			auto it_rig = rig.lower_bound({v, -1});
			ins_val(it_rig, rig, other_rig);
		}
		for (int v : process)
			active.insert(v);
		process.swap(nxt);
		nxt.clear();
	} while (LEN(process));

	Dsu dsu(m+1);
	for (int idx : indexes_two) {
		int x = other_rig[idx];
		int y = other_lft[idx];
		int check_count = active.count(x) + active.count(y);
		assert(check_count%2 == 0);
		if (check_count == 0 and !dsu.same(x, y)) {
			// cerr << "unite: " << x << " + " << y << '\n';
			dsu.unite(x, y, 1);
			ans.push_back(idx);
		}
	}
	ll mult = 1;
	int n_comp = LEN(active);
	for (int i = 1; i <= m; i++) {
		// cerr << "dsu_sz[" << i << "] = " << dsu.sz[i] << '\n';
		if (dsu.link[i] == i and dsu.sz[i] > 1) {
			// n_comp++;
			int qnt = dsu.sz[i];
			int p2 = 1;
			for (int i = 0; i < qnt-1; i++)
				p2 = mod(p2*2);
			mult = mod(mult * 1LL * (p2));
		}
	}


	ll sz_t = 1;
	for (int i = 0; i < n_comp; i++)
		sz_t = mod(sz_t*2);
	sz_t = mod(sz_t * mult);
	sort(ALL(ans));
	// sz_t++;
	// cout << sz_t << ' ' << LEN(ans) << '\n';
	// for (int i = 0; i < LEN(ans); i++)
	// 	cout << ans[i] << " \n"[i == LEN(ans)-1];
	return {{(int)sz_t}, {LEN(ans)}, ans};
}


bool case_brute () {
	uniform_int_distribution<int> dist_n(1, 14);
	uniform_int_distribution<int> dist_m(2, 63);
	int n = dist_n(rng);
	int m = dist_m(rng);
	uniform_int_distribution<int> dist_val(1, m);
	uniform_int_distribution<int> dist_bool(0, 1);
	cerr << n << ' ' << m << '\n';
	vpii inp(n);
	for (int i = 0; i < n; i++) {
		inp[i].x = dist_val(rng);
		if (dist_bool(rng)%2) {
			do {
				inp[i].y = dist_val(rng);
			} while (inp[i].y == inp[i].x);
		}
		else
			inp[i].y = -1;
	}
	vector<ll> all_possible;
	for (int msk = 0; msk < (1<<n); msk++) {
		ll val = 0;
		for (int i = 0; i < n; i++)
			if ((1<<i)&msk) {
				auto [x, y] = inp[i];
				val ^= 1LL<<x;
				if (y>0)
					val ^= 1LL<<y;
			}
		all_possible.push_back(val);
	}
	sort(ALL(all_possible));
	all_possible.resize(unique(ALL(all_possible)) - all_possible.begin());

	vector<vi> valids;
	int brute_s = 1e9;
	for (int msk = 0; msk < (1<<n); msk++) {
		// cerr << bitset<8>(msk) << '\n';
		vector<ll> cur_all;
		for (int sub_msk = msk;; sub_msk=(sub_msk-1)&msk) {
			ll val = 0;
			// cerr << '\t' << bitset<8>(sub_msk) << '\n';
			for (int i = 0; i < n; i++)
				if ((1<<i)&sub_msk) {
					auto [x, y] = inp[i];
					val ^= 1LL<<x;
					if (y>0)
						val ^= 1LL<<y;
				}
			cur_all.push_back(val);
			if (!sub_msk) break;
		}
		sort(ALL(cur_all));
		cur_all.resize(unique(ALL(cur_all)) - cur_all.begin());
		// if (msk == ((1<<n)-1)) {
		// 	cerr << LEN(all_possible) << " vs " << LEN(cur_all) << '\n';
		// }
		if (LEN(cur_all) == LEN(all_possible)) {
			vi now;
			for (int i = 0; i < n; i++)
				if (msk&(1<<i))
					now.push_back(i+1);
			valids.push_back(now);
			brute_s = min(brute_s, LEN(now));
			// cerr << "LEN(now) = " << LEN(now) << '\n';
		}
	}
	vi vals;
	for (vi &now : valids)
		if (LEN(now) == brute_s and (LEN(vals) == 0 or vals > now))
			vals = now;
			
	
	vector<vi> ans = solve(n, m, inp);
	bool ans_vals = true;
	for (int i = 0; i < min(LEN(ans[2]), LEN(vals)); i++)
		ans_vals = ans_vals and (ans[2][i] == vals[i]);
	if (LEN(ans[2]) != LEN(vals) or ans[0][0] != LEN(all_possible) or !ans_vals) {
		cout << "SOLVE_|T|: " << ans[0][0] << '\n';
		cout << "BRUTE_|T|: " << LEN(all_possible) << '\n';
		cout << "SOLVE_|S|: " << ans[1][0] << '\n';
		cout << "BRUTE_|S|: " << LEN(vals) << '\n';
		cout << "SOLVE_S:";
		for (int v : ans[2])
			cout << " " << v;
		cout << '\n';
		cout << "BRUTE_S:";
		for (int v : vals)
			cout << " " << v;
		cout << '\n';

		cout << "ALL:\n";
		for (int v : all_possible)
			cout << "\t" << bitset<6>(v) << '\n';
		cout << "CASE:\n";
		cout << n << ' ' << m << '\n';
		for (auto [x, y] : inp) {
			if (y == -1)
				cout << 1 << ' ' << x << '\n';
			else
				cout << 2 << ' ' << x << ' ' << y << '\n';	
		}
		return false;
	}
	return true;
}