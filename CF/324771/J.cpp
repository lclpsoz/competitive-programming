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

const int N = 2e4 + 10;

const int DBG = 0;
int dbg_pos = 0, dbg_n, rooms[N], dbg_cnt_qry = 0;

bool input () {
	int x;
	cin >> x;
	return x;
}

int mov (char opt) {
	if (!DBG) {
		cout << opt << '\n';
		cout.flush();
		return input();
	}
	else {
		dbg_cnt_qry++;
		if (opt == 'L')
			dbg_pos--;
		else if (opt == 'R')
			dbg_pos++;
		dbg_pos = mod(dbg_pos, dbg_n);
		// cerr << "\t|mov(" << opt << "): dbg_pos = " << dbg_pos << '\n';
		return rooms[dbg_pos];
	}
}

void inv () {
	// cerr << "\t|inv(" << dbg_pos << ")\n";
	if (!DBG)
		cout << 'S' << endl;
	else {
		dbg_cnt_qry++;
		rooms[dbg_pos] = !rooms[dbg_pos];
	}
}

void ans (int x) {
	cout << x << '\n';
	if (DBG) {
		// cout << "queries = " << dbg_cnt_qry << '\n';
		assert(x == dbg_n and dbg_cnt_qry <= 10*dbg_n);
	}
	cout.flush();
	exit(0);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	if (DBG) {
		// cin >> dbg_n;
		mt19937 rng (( llu) chrono :: steady_clock :: now (). time_since_epoch (). count ());
		uniform_int_distribution <int> dis_n (0, 20000);
		uniform_int_distribution <int> dis_b (0, 1);
		dbg_n = dis_n(rng);
		for (int i = 0; i < dbg_n; i++)
			rooms[i] = dis_b(rng);
	}
	vector<bool> lft, rig;

	// Start
	if (!DBG)
		lft.push_back(input());
	else
		lft.push_back(rooms[0]);
	rig.push_back(!mov('L'));
	inv();
	bool run_lft = true;
	while (1) {
		// cerr << "LENs = " << LEN(lft) << ' ' << LEN(rig) << ", dbg_pos = " << dbg_pos << '\n';
		if (run_lft) {
			for (int i = 0; i < LEN(lft); i++)
				if (lft[i] != mov('R'))
					ans(LEN(rig) + i);
			// cerr << "\tdbg_pos = " << dbg_pos << '\n';
			int now = LEN(lft);
			for (int i = 0; i < now; i++) {
				lft.push_back(!mov('R'));
				inv();
			}
			for (int i = 0; i < LEN(lft)-1; i++)
				mov('L');
		}
		else {
			for (int i = 0; i < LEN(rig); i++)
				if (rig[i] != mov('L'))
					ans(LEN(lft) + i);
			int now = LEN(rig);
			for (int i = 0; i < now; i++) {
				rig.push_back(!mov('L'));
				inv();
			}
			for (int i = 0; i < LEN(rig)-1; i++)
				mov('R');
		}
		run_lft = !run_lft;
	}

	return 0;
}
