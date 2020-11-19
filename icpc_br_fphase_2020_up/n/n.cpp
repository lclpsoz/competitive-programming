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

const int P = 1e5 + 10;

int lcp[P];
vi primes;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

ll mdc(ll x, ll y) {
	if(x == 0) return y;
	return mdc(y%x, x);
}

ll pollard(ll n) {
	int i = 0, k = 2, d;
	u128 x = 3, y = 3;
	while(++i) {
		x = ((x * x) + n - 1)%n;
		u128 ax;
		if(x > y)
			ax = x-y;
		else
			ax = y-x;
		d = mdc(ax, n);
		if(d != 1 and d != n) return d;
		if(i == k) y = x, k *= 2;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	for(int i = 2; i < P; i++) {
		if(lcp[i] == 0) {
			lcp[i] = i;
			primes.push_back(i);
		}
		for(int pr : primes) {
			if(pr > lcp[i] or i*pr >= P) break;
			lcp[i*pr] = pr;
		}
	}

	int n, m, k;
	cin >> m >> n >> k;
	vector<ll> ans;
	while(n--) {
		ll val;
		cin >> val;
		for(int pr : primes) {
			if(val%pr == 0) {
				ans.push_back(pr);
				while(val%pr == 0) val /= pr;
			}
		}
		if(val > 1) {
			if(MillerRabin(val))
				ans.push_back(val);
			else {
				ll ax = pollard(val);
				ans.push_back(ax);
				ans.push_back(val/ax);
			}
		}
	}
	sort(ALL(ans));
	ans.resize(unique(ALL(ans)) - ans.begin());

	for(int i = 0; i < LEN(ans); i++)
		cout << ans[i] << " \n"[i==LEN(ans)-1];


	return 0;
}
