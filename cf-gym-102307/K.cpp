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

const int MOD = 2;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

vector<int> fib(1e5 + 1, 0);

fib_gcd(int m, int n) {
	return fib[__gcd(m, n)];
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= 1e5; i++) {
    	fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    vector<int> ans(1e5 + 1, 0);
    ans[0] = ans[1] = ans[2] = 0;
    ans[3] = 2;
    ans[4] = 3;
    ans[5] = 3;
    int count = 3;
    for (int i = 6; i <= 1e5; i++) {
    	if ((fib[i] % 2) != (fib[i - 1] % 2) && fib_gcd(i, i - 1) == 1)
    		count++;
    	ans[i] = count;
    }

    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	cout << ans[n] << endl;
    }

	return 0;
}
