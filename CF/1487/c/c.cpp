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

bool check (int n, vi vec, bool prt = false) {
	vi score(n);
	int p = 0;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++) {
			// cerr << "  brute: p = " << p << '\n';
			if (vec[p] == 0)
				score[i]++, score[j]++;
			else if (vec[p] == 1)
				score[i]+=3;
			else
				score[j]+=3;
			++p;
		}
	if (prt) {
		for (int v : score)
			cerr << v << ' ';
		cerr << '\n';
	}
	for (int v : score)
		if (v != score.front()) return false;
	return true;
}

void brute (int n) {
	cerr << "brute!\n";
	vi vec((n*(n-1))/2);
	int pos = 0;
	while (pos < LEN(vec)) {
		// cerr << "pos = " <<pos << '\n';
		if (check(n, vec, false)) {
			for (int i = 0; i < LEN(vec); i++)
				cerr << vec[i] << " \n"[i==LEN(vec)-1];
			check(n, vec, true);
		}
		vec[pos]++;
		while (pos < LEN(vec) and vec[pos] == 3) {
			vec[pos++] = 0;
			if (pos < LEN(vec))
				vec[pos]++;
		}
		if (pos == LEN(vec)) break;
		pos = 0;
	}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		// brute(n);
		vi ans;
		int q = (n*(n-1))/2;
		if (n%2 == 1) {
			vi wins(n+1, q/n);
			for (int i = 1; i <= n; i++)
				for (int j = i+1; j <= n; j++)
					if (wins[i]) {
						wins[i]--;
						ans.push_back(1);
					}
					else if (wins[j]) {
						wins[j]--;
						ans.push_back(-1);
					}
					else
						ans.push_back(0);
		}
		else {
			vi wins(n+1, n/2-1), draws(n+1, 1), loses(n+1, n/2-1);
			for (int i = 1; i <= n; i++)
				for (int j = i+1; j <= n; j++)
					if (wins[i] and loses[j]) {
						wins[i]--;
						loses[j]--;
						ans.push_back(1);
					}
					else if (draws[i] and draws[j]) {
						draws[i]--;
						draws[j]--;
						ans.push_back(0);
					}
					else if (wins[j] and loses[i]) {
						wins[j]--;
						loses[i]--;
						ans.push_back(-1);
					}
					else {
						cerr << "i = " << i << ", j = " << j << '\n';
						cout << "FAIL!!!\n";
						exit(0);
					}
		}
		for (int i = 0; i < LEN(ans); i++)
			cout << ans[i] << " \n"[i==LEN(ans)-1];
	}

	return 0;
}
