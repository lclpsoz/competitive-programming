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

void brute (vi &vec) {
	int m = LEN(vec)-1;
	set<vi> vecs;
	for (int i = 0; i < (1<<m); i++) {
		for (int j = i+1; j < (1<<m); j++) {
			vi r1(LEN(vec)), r2(LEN(vec));
			for (int k = 0; k < m; k++) {
				int op1 = (1<<k)&i;
				if (!op1)
					r1[k]++;
				else
					r1[k+1]++;
				int op2 = (1<<k)&j;
				if (!op2)
					r2[k]++;
				else
					r2[k+1]++;
			}
			vi now;
			// for (int i = 0; i < LEN(vec); i++)
			// 	now.push_back(abs(r1[i]-r2[i]));
			// vecs.insert(now);
			cout << bitset<5>(i) << ' ' << bitset<5>(j) << ": ";
			for (int i = 0; i < LEN(vec); i++)
				cout << abs(r1[i]-r2[i]) << " ";
			cout << '\n';
		}
	}
	// sort(ALL(vecs));
	for (vi vec : vecs) {
		for (int x : vec)
			cerr << x << ' ';
		cerr << '\n';
	}
}

int avail (pii a, pii b) {
	int x = !a.x + b.x;
	int y = !a.y + b.y;
	// cerr << "     x,y = " << x << ' ' << y << '\n';
	return abs(x - y);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	vi vec(n);
	for (int &x : vec)
		cin >> x;
	// brute(vec);
	set<pii> st_bef;
	if (vec[0] == 0)
		st_bef = {{1, 1}, {0, 0}};
	else if (vec[0] == 1)
		st_bef = {{1, 0}, {0, 1}};
	set<pii> st_nxt;
	for (int pos = 1; pos < n; pos++) {
		for (pii bef : st_bef)
			for (int i = 0; i <= 1; i++)
				for (int j = 0; j <= 1; j++)
					if (avail(bef, {i, j}) == vec[pos])
						st_nxt.insert({i, j});
		// cerr << "st_nxt " << pos << ":\n";
		// for (auto pp : st_nxt)
		// 	cerr << "  " << pp.x << " " << pp.y << '\n';
		if (LEN(st_nxt) == 0){
			cout << "NO\n";
			exit(0);
		}
		st_bef.swap(st_nxt);
		st_nxt.clear();
	}

	cout << (st_bef.count({0, 0}) ? "YES\n" : "NO\n");


		// if (vec[i]+vec[i+1] == 0 or vec[i]+vec[i+1] > 2 or vec[i] > 1) {
		// 	cout << "NO\n";
		// 	exit(0);
		// }
		// else if (vec[i])
		// 	vec[i]--;
		// else if (vec[i+1])
		// 	vec[i+1]--;
		// else
		// 	assert(false);

	return 0;
}
