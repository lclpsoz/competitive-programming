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

int solve (vi &a) {
	int n = LEN(a);
	vi mini, lst;
	mini.push_back(-1);
	lst.push_back(a[0]);
	set<int> st;
	for (int i = 1; i < n; i++) {
		int val = a[i];
		auto it = upper_bound(ALL(mini), val);
		// auto it2 = lower_bound(ALL(mini), val);
		// if (it2 != it) {
		// 	// cerr << "  NEW IT! i = " << i << '\n';
		// 	auto pos = it2 - mini.begin();
		// 	// cerr << "    pos = " << pos << ", lst[pos-1] = " << lst[pos-1] << '\n';
		// 	if (mini[pos] > min(lst[pos-1], val)) {
		// 		lst[pos] = val;
		// 		mini[pos] = min(lst[pos], lst[pos-1]);
		// 	}
		// }
		int pos;
		if (it == mini.end()) {
			mini.push_back(min(lst.back(), val));
			lst.push_back(val);
			pos = LEN(lst)-1;
		}
		else {
			pos = it - mini.begin();
			if (lst[pos] > val) {
				lst[pos] = val;
				mini[pos] = min(lst[pos], lst[pos-1]);
			}
			if (pos < LEN(lst)-1 and mini[pos+1] > lst[pos]) {
				st.insert(pos+1);
				// cerr << "st.: " << pos+1 << '\n';
			}
		}
		st.erase(pos);
		vi process;
		while (LEN(st) and *st.begin() < pos) {
			process.push_back(*st.begin());
			// cerr << "upd: " << upd << '\n';
			st.erase(st.begin());
		}
		reverse(ALL(process));
		for (int upd : process) {
			if (mini[upd] > lst[upd-1]) {
				lst[upd] = val;
				mini[upd] = lst[upd-1];
			}
		}
		// cerr << "i = " << i << "\n";
		// for (int j = 0; j < LEN(mini); j++)
		// 	cerr << mini[j] << " \n"[j == LEN(mini)-1];
		// for (int j = 0; j < LEN(lst); j++)
		// 	cerr << lst[j] << " \n"[j == LEN(lst)-1];
		// 	cerr << '\n';
	}
	return LEN(mini);
}

int brute (vi &a) {
	int n = LEN(a);
	int ret = 2;
	for (int i = 1; i < (1<<n); i++) {
		// cerr << "msk = " << i << '\n';
		if (__builtin_popcount(i) <= 2) continue;
		vi ax;
		for (int j = 0; j < n; j++)
			if ((1<<j)&i)
				ax.push_back(a[j]);
		int bef = -1;
		for (int j = 1; j < LEN(ax); j++) {
			int mn = min(ax[j], ax[j-1]);
			if (bef > mn) {
				bef = -1;
				break;
			}
			else
				bef = mn;
		}
		// if (bef != -1 and LEN(ax) == 7) {
		// 	cerr << "choosen = ";
		// 	for (int v : ax)
		// 		cerr << v << ' ';
		// 	cerr << '\n';
		// }
		if (bef != -1)
			ret = max(ret, LEN(ax));
			// cerr << "out!\n";
	}
	// cerr << "ret = " << ret << '\n';
	return ret;
}

void test () {
	int mx = 12;
	vi a(mx, 0);
	do {
		// cerr << "here!\n";
		int p = 0;
		a[p]++;
		while(a[p] == 2) {
			a[p] = 0;
			++p;
			if (p == mx) {
				cerr << "WTF\n";
				exit(0);
			}
			a[p]++;
		}

	} while(brute(a) == solve(a));
	for (int v : a)
		cerr << v << ' ';
	cerr << '\n';
	cerr << brute(a) << " vs " << solve(a) << '\n';
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	test();

	// int t; cin >> t;
	// while(t--)
	// {
	// 	int n; cin >> n;
	// 	vi a(n);
	// 	for(int& i : a) cin >> i;
	// 	// brute(a);
	// 	cout << solve(a) << '\n';
	// }

	return 0;
}
