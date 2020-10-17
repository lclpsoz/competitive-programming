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

vi players[1010];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < n; j++) {
			int adv;
			cin >> adv;
			players[i].push_back(adv);
		}
	}

	for(int i = 1; i <= n; i++)
		reverse(ALL(players[i]));

	bitset<1010> vis;
	for(int i = 1;; i++) {
		bool played = 0;
		bool empty = 1;
		vis.reset();
		for(int j = 1; j <= n; j++)
			if(vis[j] == 0 and LEN(players[j])) {
				vis[j] = 1;
				empty = 0;
				int adv = players[j].back();
				if(vis[adv] == 0 and LEN(players[adv]) and players[adv].back() == j) {
					played = 1;
					players[adv].pop_back();
					players[j].pop_back();
					vis[adv] = 1;
				}
			}
		if(empty) {
			cout << (i-1) << '\n';
			exit(0);
		} else if(!played) {
			cout << "-1\n";
			exit(0);
		}
	}

	return 0;
}
