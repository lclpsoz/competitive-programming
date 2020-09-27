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

int n;

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	cin >> n;
	int node = 1;
	int bef = -1;
	int dist;
	do {
		cout << node << '\n';
		cout.flush();
		cin >> dist;
		if(dist) {
			if(node != 1 and dist != bef-1) {
				node++;
				dist = bef-1;
			}
			if(dist and 2*1LL*node <= ((1LL<<n)-1))
				node = 2*node;
			else
				break;
		}
		bef = dist;
	} while(dist);
	cout << "! " << node << '\n';

	return 0;
}
