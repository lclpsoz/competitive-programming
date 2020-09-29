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

const int N = 110;

int t, n, m;
int a[N];
vector<pii> vec;
bitset<N> p;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	cin >> t;
	while(t--) {
		p.reset();
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= m; i++) {
			int x;
			cin >> x;
			p[x] = 1;
		}
		bool ans = true;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n-i; j++)
				if(p[j] and a[j] > a[j+1])
					swap(a[j], a[j+1]);
		for(int i = 1; i < n; i++)
			ans = ans and a[i] <= a[i+1];
		cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}
