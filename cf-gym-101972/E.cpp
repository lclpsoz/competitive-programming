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

const int N = 1e4 + 100;

int t;
int n, m, k;
char prob[N];
bitset<N> abed;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	
	cin >> t;
	while(t--) {
		abed.reset();
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i++)
			cin >> prob[i];
		for(int i = 1; i <= k; i++)
			abed[i] = 1;

		int nxt = k;
		int ans = 0;
		while(m--) {
			// cout << "m = " << m << '\n';
			char opt;
			int p;
			cin >> opt;
			if(opt == 'A') p = n;
			else cin >> p;
			ans += abed[p];
			// cout << "nxt = " << nxt << ", p = " << p << '\n';
			while(nxt <= p) {
				if(prob[nxt] == 'S')
					abed[nxt] = 1;
				nxt++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}