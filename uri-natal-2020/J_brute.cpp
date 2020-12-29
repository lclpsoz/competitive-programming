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

int k;
map<vi, int> dp;

int get_xor (vi vec) {
	int ret = 0;
	for (int v : vec)
		ret ^= v;
	return ret;
}

int get_sum (vi vec) {
	int ret = 0;
	for (int v : vec)
		ret += v;
	return ret;
}

int solve (vi now) {
	if (get_sum (now) == 0)
		return 0;
	if (dp.count(now))
		return dp[now];
	vi nxt;
	if (now[0]) {
		vi ax = now;
		for (int i = 0; i < k and ax[0]; i++) {
			ax[0]--;
			nxt.push_back(solve(ax));
		}
	}
	for (int i = 1; i < LEN(now); i++) {
		vi ax = now;
		for (int j = 0; j < k and ax[i] > ax[i-1]; j++) {
			ax[i]--;
			nxt.push_back(solve(ax));
		}
	}
	sort(ALL(nxt));
	nxt.resize(unique(ALL(nxt)) - nxt.begin());
	int mex = 0;
	for (int v : nxt) {
		if (v != mex)
			break;
		++mex;
	}
	return dp[now] = mex;
}

void prt_all () {
	for (auto [vec, grundy] : dp) {
		for (int v : vec)
			cout << setw(2) << v << ' ';
		cout << "| grundy = ";
		cout << grundy << '\n';
	}
}

vi to_unique (vi vec) {
	int sz = LEN(vec);
	vi ret;
	map<int, int> mp;
	for (int v : vec)
		mp[v]++;
	vec.clear();
	for (auto [v, cnt] : mp) {
		if (v and cnt%2 == 1)
			vec.push_back(v);
		else if (v > 0) {
			vec.push_back(v);
			vec.push_back(v);
		}
	}
	for (int i = 0; i < sz-LEN(vec); i++)
		ret.push_back(0);
	for (int v : vec)
		ret.push_back(v);
	return ret;
}

void check_unique () {
	bool ok = true;
	for (auto [vec, grundy] : dp) {
		vi vec_unique = to_unique(vec);
		if (grundy != dp[vec_unique]) {
			ok = false;
			cout << "full: ";
			for (int v : vec)
				cout << setw(2) << v << ' ';
			cout << "| grundy = ";
			cout << grundy << '\n';

			cout << "uniq: ";
			for (int v : vec_unique)
				cout << setw(2) << v << ' ';
			cout << "| grundy = ";
			cout << dp[vec_unique] << '\n';

			cout << '\n';
		}
	}
	if (!ok) {
		cout << "to_unique() !EQUIVALENT!\n";
		exit(0);
	}
	else
		cout << "to_unique() IS OKAY!\n";
}

vector<pair<vi, int>> get_uniques (bool uniq = true) {
	vector<pair<vi, int>> all_unique;
	for (auto [vec, grundy] : dp)
		if (uniq)
			all_unique.push_back({to_unique(vec), grundy});
		else
			all_unique.push_back({vec, grundy});
	sort(ALL(all_unique));
	if (uniq)
		all_unique.resize(unique(ALL(all_unique)) - all_unique.begin());
	return all_unique;
}

void prt_unique () {
	vector<pair<vi, int>> all_unique = get_uniques();
	for (auto [vec, grundy] : all_unique) {
		for (int v : vec)
			cout << setw(2) << v << ' ';
		cout << "| grundy = ";
		cout << grundy << '\n';
	}
}

vi vec_bef (vi vec) {
	for (int i = 0; i < LEN(vec); i++)
		if (vec[i]) {
			vec[i] = 0;
			return vec;
		}
}

vi left_val (vi vec, int grundy, int zeros = 0) {
	if (zeros) {
		for (int i = 0; i < LEN(vec); i++)
			if (vec[i]) {
				if (i == LEN(vec)-1)
					return {i%2, vec[i]};
				else
					return {i%2, vec[i+1], vec[i]};
			}
	}
	else
		for (int i = 0; i < LEN(vec); i++)
			if (vec[i]) {
				if (i == LEN(vec)-1)
					return {i%2, vec[i]};
				else if (i == LEN(vec)-2)
					return {i%2, vec[i+1], vec[i]};
				else if (i <= LEN(vec)-3)
					return {i%2, vec[i+2], vec[i+1], vec[i]};
			}
	return {-1, -1};
}

void explore_unique () {
	vector<pair<vi, int>> all_unique = get_uniques(false);
	map<vector<vi>, int> mp;
	map<vector<vi>, vi> lst_vec;
	for (auto [vec, grundy] : all_unique) {
		// deltas
		vi deltas;
		for (int i = 1; i < LEN(vec); i++)
			deltas.push_back(vec[i]-vec[i-1]);

		int sum = get_sum(deltas);
		int xr = get_xor(deltas);
		// cnt_uniq
		set<int> st;
		for (int v : deltas)
			st.insert(v);
		int cnt_uniq = LEN(deltas);
		vi uq = deltas;
		uq.resize(unique(ALL(uq)) - uq.begin());
		vector<vi> info = {vec};
		if (mp.count(info) and mp[info] != grundy) {
			// cout << "grundy = " << grundy << ", sum = " << sum << ", xor = " << xr << ", cnt_uniq = " << cnt_uniq << '\n';
			for (int v : vec)
				cout << setw(2) << v << ' ';
			cout << "| grundy = ";
			cout << grundy << '\n';
			for (int v : lst_vec[info])
				cout << setw(2) << v << ' ';
			cout << "| grundy = ";
			cout << mp[info] << '\n';
			cout << '\n';
		}
		mp[info] = grundy;
		lst_vec[info] = vec;
	}
}

void solve_k3 () {
	vector<pair<vi, int>> all_unique = get_uniques(false);
	map<vector<vi>, int> mp;
	map<vector<vi>, vi> lst_vec;
	for (auto [vec, grundy] : all_unique) {
		// deltas
		vi deltas;
		for (int i = 1; i < LEN(vec); i++)
			deltas.push_back(vec[i]-vec[i-1]);

		// DELTAS 2ND
		// vi deltas2;
		// for (int v : deltas)
		// 	if (v)
		// 		deltas2.push_back(v);
		// if (LEN(deltas)-LEN(deltas2) > 3) {
		// 	for (int v : deltas)
		// 		cout << setw(2) << v << ' ';
		// 	cout << '\n';
		// 	for (int v : deltas2)
		// 		cout << setw(2) <<  v << ' ';
		// 	cout << '\n';
		// 	cout << '\n';
		// }
		// END DELTAS 2ND

		
		// grundy = grundy > 0;

		int sum = get_sum(deltas);
		int xr = get_xor(deltas);
		// cnt_uniq
		set<int> st;
		for (int v : deltas)
			st.insert(v);
		int cnt_uniq = LEN(deltas);
		vi uq = deltas;
		uq.resize(unique(ALL(uq)) - uq.begin());
		vector<vi> info = {vec};
		if (mp.count(info) and mp[info] != grundy) {
			// cout << "grundy = " << grundy << ", sum = " << sum << ", xor = " << xr << ", cnt_uniq = " << cnt_uniq << '\n';
			for (int v : vec)
				cout << setw(2) << v << ' ';
			cout << "| grundy = ";
			cout << grundy << '\n';
			for (int v : lst_vec[info])
				cout << setw(2) << v << ' ';
			cout << "| grundy = ";
			cout << mp[info] << '\n';
			cout << '\n';
		}
		mp[info] = grundy;
		lst_vec[info] = vec;
	}
	cout << "LEN(now) = " << LEN(mp) << " vs LEN(all_unique) = " << LEN(all_unique) << " vs LEN(dp) = " << LEN(dp) << '\n';
	for (auto [info, grundy] : mp) {
		auto vec = info[0];

		if (vec[0]) {
			int sum_vec = get_sum(vec);
			for (int v : vec)
				cout << setw(2) << v << ' ';
			cout << "| grundy = " << grundy << " || ";
			int old_val = vec[0];
			vec[0] = 0;
			int old_grundy = mp[{vec}];
			for (int v : vec)
				cout << setw(2) << v << ' ';
			cout << "| old_grundy = " << old_grundy << "\n";
			if (((LEN(vec)+0)%2 == 1 and sum_vec%2 == 0) or
				((LEN(vec)+0)%2 == 0 and sum_vec%2 == !(vec[1]%2))) {
				if ((grundy+(old_val%(k+1)))%(k+1) != old_grundy) {
					cout << "FAIL!!!\n";
					cout.flush();
					exit(0);
				}
			}
			else {
				if ((grundy-(old_val%(k+1))+k+1)%(k+1) != old_grundy) {
					cout << "FAIL!!!\n";
					cout.flush();
					exit(0);
				}
			}
		}
	}

}

void explore_dp () {
	map<vector<vi>, int> mp;
	map<vector<vi>, vi> lst_vec;
	int p = 0;
	int md = LEN(dp)/1000 + 1;
	for (auto [vec, grundy] : dp) {

		int sum = get_sum(vec);
		int xr = get_xor(vec);
		vi vec_b = vec_bef(vec);

		grundy = grundy;

		if (p++ < 10000 or (p%md == 0)) {
			for (int v : vec)
				cerr << v << ' ';
			cerr << " | grundy: " << dp[vec_b] << " -> " << grundy << '\n';
		}

		vector<vi> info = {{left_val(vec, grundy)}, {dp[vec_b]}};
		vector<vi> info2 = {{left_val(vec, grundy, 1)}, {dp[vec_b]}};
		if (mp.count(info) and mp[info] != grundy) {
			cerr << "info[0] = " << '\n';
			for (int v : info[0])
				cerr << v << ' ';
			cerr << '\n';
			cerr << "FAIL!\n";
			exit(0);
		}
		if (mp.count(info2) and mp[info2] != grundy) {
			cerr << "FAIL2!\n";
			exit(0);
		}
		// cerr << "\tinfo: " << info[0][0] << ' ';
		// for (int v : vec_b)
		// 	cerr << v << ' ';
		// cerr << '\n';
		mp[info] = grundy;
		mp[info2] = grundy;
	}
	cout << "LEN(dp) = " << LEN(dp) << ", LEN(mp) = " << LEN(mp) << '\n';
	cout << "  % = " << (100*(ld)LEN(mp)/LEN(dp)) << '\n';

	// for (auto [info, grundy] : mp) {
	// 	cerr << "pos = " << info[1][0];
	// 	if (LEN(info[1]) == 3)
	// 		cerr << ", " << info[1][2] << ", " << info[1][1];
	// 	else
	// 		cerr << ", vals = " << info[1][1];
	// 	cerr << " | grundy_bef = " << info[0][0] << '\n';
	// 	cerr << "\tgrundy = " << grundy << '\n';
	// }
	for (auto [info, grundy] : mp) {
		if (LEN(info[0]) == 4 and info[0].back()) {
			vi infos;
			infos.push_back(info[0][0]);
			infos.push_back(info[0][3]);
			infos.push_back(info[0][2]);
			infos.push_back(info[0][1]);
			infos.push_back(info[1][0]);
			cerr << infos[0] << ", vec: " << infos[1] << ' ' << infos[2] << ' ' << infos[3] << ", last_g = " << infos[4] << " -> " << grundy;
			cerr << "\n\t{";
			vector<vi> cpy = info;
			int ori_2 = cpy[0][3];
			for (int i = cpy[0][3]-1, j = 1; i >= 0 and j <= k; i--, j++) {
				// if (i == 0) {
				// 	vi vv(4);
				// 	vv[0] = !cpy[0][0];
				// 	vv[1] = cpy[0][2];
				// 	vv[2] = cpy[0][1];
				// 	vv[3] = cpy[1][0];
				// 	cpy = {vv};
				// }
				// else {
					cpy[0][3] = i;
				if (mp.count(cpy))
					cerr << mp[cpy] << ", ";
				else if (i == 0)
					cerr << cpy[1][0] << ", ";
				else
					cerr << "-, ";
			}
			cerr << "}\n";
			// cpy[0][2] = ori_2;



			// cerr << " .. \n\t";
			// for (int i = cpy[0][1]-1, j = 1; cpy[0][1] >= cpy[0][2] and j <= k; i--, j++) {
			// 	cpy[0][1] = i;
			// 	if (mp.count(cpy))
			// 		cerr << mp[cpy] << ", ";
			// 	else
			// 		cerr << "-, ";
			// }
			// cerr << "}\n";

		} else if (LEN(info[0]) == 3) {
			// cerr << "\n\t" << info[0][0] << ", vec: " << info[0][1] << ' ' << info[0][2] << ", last_g = " << info[1][0] << " -> " << grundy;
			// cerr << '\n';
			// cerr << '\n';
			// 	cerr << info[0][0] << ' ' << info[0][3] << ' ' << info[0][2] << ' ' << info[0][1] << ' ' << info[0][0] << ' ' << info[1][0] << " -> " << grundy << '\n';
			// else
			// 	cerr << info[0][0] << ' ' << info[0][2] << ' ' << info[0][1] << ' ' << info[0][0] << ' ' << info[1][0] << " -> " << grundy << '\n';
			
		}
		// cerr << "pos = " << info[1][0];
		// if (LEN(info[1]) == 3)
		// 	cerr << ", " << info[1][2] << ", " << info[1][1];
		// else
		// 	cerr << ", vals = " << info[1][1];
		// cerr << " | grundy_bef = " << info[0][0] << '\n';
		// cerr << "\tgrundy = " << grundy << '\n';
	}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n >> k;
	vi vec(n);
	for (int &v : vec)
		cin >> v;
	
	cout << solve(vec) << '\n';

	// prt_all();

	check_unique();

	// prt_unique();

	explore_dp();

	// vector<vi> all_vecs;
	// map<vi, int> mp;
	// for (auto [vvec, grundy] : dp) {
	// 	// cout << "here!\n";
	// 	all_vecs.push_back(vvec);
	// 	int val_get_sum = get_sum(vvec);
	// 	int val_xor = get_xor(vvec);
	// 	int m = 0;
	// 	for (int v : vvec)
	// 		m += v > 0;
	// 	vi ax = vvec;
	// 	ax.resize(unique(ALL(ax)) - ax.begin());
	// 	int m_ax = 0;
	// 	for (int v : ax)
	// 		m_ax += v > 0;
	// 	bool win = grundy > 0;
	// 	vi info = {m, val_get_sum, val_xor, m_ax, get_sum(ax), get_xor(ax)};
	// 	if (mp.count(info)>0 and (mp[info] != win)) {
			
	// 		cout << win << " vs " << mp[info] << '\n';
	// 		mp[info] = -1;
	// 	}
	// 	// assert((!mp.count(info)>0) or (mp[info] == win));
	// 	mp[info] = win;
	// 	// if (val_get_sum%2 == 1) {
	// 	// 	for (int v : vvec)
	// 	// 		cout << v << ' ';
	// 	// 	cout << ":\t" << grundy << '\n';
	// 	// 	// assert(grundy > 0);
	// 	// }
	// 	// << ", get_sum = " << get_sum(vvec) << '\n';
	// 	// assert(grundy>0 == get_sum(vvec)%(k+1)==0);
	// }

	// for (auto [info, res] : mp) {
	// 	if (res != -1) {
	// 		cout << res << ": ";
	// 		for (int v : info)
	// 			cout << v << ' ';
	// 		cout << '\n';
	// 	}
	// }

	// exit(0);
	// for (auto [info, win] : mp)
	// 	cout << info[0] << ' ' << info[1] << ' ' << win << '\n';

	// sort(ALL(all_vecs), [&] (vi &lhs, vi &rhs) {
	// 	return get_sum(lhs) < get_sum(rhs);
	// });
	// int ss = 0;
	// for (vi &vvec : all_vecs) {
	// 	int val_get_sum = get_sum(vvec);
	// 	if (val_get_sum != ss) {
	// 		cout << '\n';
	// 		ss = val_get_sum;
	// 	}
	// 	for (int v : vvec) {
	// 		cout << v << ' ';
	// 	}
	// 	cout << "\tgrundy = " << grundy(vvec) << ", get_sum = " << val_get_sum << '\n';
	// }
	// map<int, set<int>> mp;
	// for (vi &vvec : all_vecs) {
	// 	int xr = 0;
	// 	for (int v : vvec) {
	// 		xr = xr ^ v;
	// 	}
	// 	if (get_sum(vvec)%2 == 0) {
	// 		if (grundy(vvec) > 0) {
	// 			// can_go_to_zero(vvec);
	// 			cout << "    ";
	// 		}
	// 		for (int v : vvec) {
	// 			cout << v << ' ';
	// 		}
	// 		// if (xr)
	// 		cout << ":  " << grundy(vvec) << ", " << get_sum(vvec) << ", " << xr << '\n';
	// 		mp[grundy(vvec) > 0].insert(xr);
	// 	}
	// 	// if (grundy(vvec) > 0 != xr%2 == 1)
	// 	// 	cout << "FAKE\n";
	// }
	// cout << "WIN: ";
	// for (int v : mp[1])
	// 	cout << v <<  ' ';
	// cout << '\n';
	// cout << "LOSE: ";
	// for (int v : mp[0])
	// 	cout << v <<  ' ';
	// cout << '\n';


	return 0;
}
