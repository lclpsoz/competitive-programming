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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int DBG=1;

int n;
ll mat[26][26];

void solve(ll val, vpii path_ans = {}) {
	vpii path;
	ll lst = 2;
	pii pos = {1, 1};
	int p = 0;
	int down = 0;
	for(int i = 0; i < 2*(n-1); i++) {
		path.push_back(pos);
		if(pos.x == n) pos.y++;
		else if(pos.y == n) pos.x++;
		else {
			int eval = (val&(1LL<<p)) > 0;
			// if(DBG)
			// 	cout << i << ": eval = " << eval << ", down = " << down << '\n';
			if(eval == down) pos.x++;
			else {
				pos.y++;
				down = !down;
			}
			p++;
		}
	}
	path.push_back({n, n});
	if(!DBG) {
		for(pii coord : path)
			cout << coord.x << ' ' << coord.y << '\n';
		cout.flush();
	}
	else {
		// cout << "PATH:\n";
		// for(pii coord : path)
		// 	cout << coord.x << ' ' << coord.y << '\n';
		cout.flush();
		for(int i = 0; i < LEN(path); i++) {
			// if(path[i] != path_ans[i]) {
			// 	cout << path[i].x << ", " << path[i].y << " vs " << path_ans[i].x << ", " << path_ans[i].y << '\n';
			// 	cout.flush();
			// }
			assert(path[i] == path_ans[i]);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n;
	
	mat[1][1] = mat[n][n] = 0;
	vpii all_pairs;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			all_pairs.push_back({i, j});
	sort(ALL(all_pairs), [&](const pii &lhs, const pii &rhs) {
		return lhs.x+lhs.y < rhs.x+rhs.y;
	});

	int bef = -1;
	int lst = -1;

	for(int i = 1; i < LEN(all_pairs)-1; i++) {
		auto [x, y] = all_pairs[i];
		if(bef != (x+y)) {
			lst++;
			bef = x+y;
		}
		int ax = y&1;
		// if(x+y > n+1 and (x+y)%2 == n%2) ax=(!ax);
		if(ax)
			mat[x][y] = 0;
		else
			mat[x][y] = 1LL<<lst;
	}
	if(DBG)
		cout << "lst = " << lst << '\n';

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			cout << mat[i][j] << " \n"[j==n];
			// cout << __builtin_ctzll(mat[i][j]) << " \n"[j==n];
		}
	cout.flush();

	int q;
	if(!DBG) {
		cin >> q;
		while(q--) {
			ll val;
			cin >> val;
			solve(val);
		}
	} else {
		vector<vpii> paths;
		for(ll i = 0; LEN(paths) < 5e6 and i < (1LL<<((n-1)*2)); i++) {
			if(__builtin_popcountll(i) == n-1) {
				vpii path;
				pii now = {1, 1};
				for(int j = 0; j < 2*(n-1); j++) {
					path.push_back(now);
					if(i&(1LL<<j))
						now.x++;
					else
						now.y++;
				}
				path.push_back(now);
				paths.push_back(path);
			}
		}
		for(ll i = (1LL<<((n-1)*2))-1; LEN(paths) < 1e7 and i; i--) {
			if(__builtin_popcountll(i) == n-1) {
				vpii path;
				pii now = {1, 1};
				for(int j = 0; j < 2*(n-1); j++) {
					path.push_back(now);
					if(i&(1LL<<j))
						now.x++;
					else
						now.y++;
				}
				path.push_back(now);
				paths.push_back(path);
			}
		}
		cout << "LEN(paths) = " << LEN(paths) << '\n';
		q = LEN(paths);
		while(q--) {
			ll val = 0;
			// cout << "CORRECT:\n";
			for(pii coord : paths[q]) {
				// cout << coord.x << ' ' << coord.y << '\n';
				val += mat[coord.x][coord.y];
			}
			// cout << "val = " << val << '\n';
			cout.flush();
			solve(val, paths[q]);
		}
	}


	return 0;
}
