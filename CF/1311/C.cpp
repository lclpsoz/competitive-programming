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

const int N = 2e5 + 10;

int t, n, m;
int partial[N];
ll ans[30];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> t;
	while(t--) {
		memset(partial, 0, sizeof(partial));
		memset(ans, 0, sizeof(ans));
		cin >> n >> m;
		string s;
		cin >> s;
		while(m--) {
			int p;
			cin >> p;
			partial[p]++;
		}
		int acu = 1;
		for(int i = n; i; i--) {
			acu += partial[i];
			// cout << "i = " << i << ", acu = " << acu << '\n';
			ans[s[i-1]-'a']+=acu;
		}
		for(int i = 0; i <= 'z'-'a'; i++)
			cout << ans[i] << " \n"[i=='z'-'a'];
	}

	return 0;
}
