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

// const int P = 1e5;

// bitset<P> not_prime;
// vi primes;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	// for(int i = 2; i*i < P; i++)
	// 	if(!not_prime[i])
	// 		for(int j = i*i; j < P; j+=i)
	// 			not_prime[j] = 1;
	
	// for(int i = 2; i < P; i++)
	// 	if(!not_prime[i])
	// 		primes.push_back(i);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		// vi used, exp;
		int now = n;
		int lst = 2e9;
		for(int i = 1; i*i <= n and i <= k; i++)
			if(n%i == 0) {
				lst = min(lst, n/i);
				if(n/i <= k)
					lst = min(i, lst);
			}
		if(lst == 2e9)
			lst = n;
		cout << lst << '\n';

		// for(int p : primes)
		// 	while(now%p == 0) {
		// 		if(used.empty() or used.back() != p) {
		// 			used.push_back(p);
		// 			exp.push_back(0);
		// 		}
		// 		exp.back()++;
		// 		now /= p;
		// 	}
		// if(now > 1)
		// 	used.push_back(now);
		// exp.push_back(1);
		// vi div_exp(LEN(exp));
		// int pos = 0;
		// ll here = 1;
		// while(1) {
		// 	here *= used[pos];
		// 	if(div_exp[pos] > exp[pos]) {
		// 		if(pos == LEN(div_exp)-1) break;
		// 		else {
		// 			div_exp[pos] = 0;
		// 			pos++;
		// 		}
		// 	}
		// }
	}

	return 0;
}
