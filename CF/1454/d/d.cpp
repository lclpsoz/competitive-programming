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

const int N = 1e5 + 100;

int lp[N];
vi primes;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	for(int i = 2; i < N; i++) {
		if(lp[i] == 0) {
			lp[i] = i;
			primes.push_back(i);
		}
		for(int p : primes) {
			if(p > lp[i] or i*1LL*p >= N) continue;
			lp[i*p] = p;
		}
	}
	// for(int i = 0; i < 100; i++)
	// 	cout << primes[i] << '\n';
	// cout.flush();
	// exit(0);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<ll> factors;
		vi pws;
		for(int p : primes) {
			while(n%p == 0) {
				if(LEN(factors) == 0 or factors.back() != p) {
					factors.push_back(p);
					pws.push_back(0);
				}
				pws.back()++;
				n/=p;
			}
			if(p*1LL*p > n) break;
		}
		if(n > 1)
			factors.push_back(n), pws.push_back(1);
		int mx = 0, p_mx = -1;
		for(int i = 0; i < LEN(pws); i++)
			if(pws[i] > mx) {
				mx = pws[i];
				p_mx = i;
			}
		ll lst = 1;
		for(int i = 0; i < LEN(pws); i++)
			if(i != p_mx) {
				// cout << "fact =  " << factors[i] << '\n';
				for(int j = 0; j < pws[i]; j++)
					lst *= factors[i];
			} else
				lst *= factors[i];
		cout << mx << '\n';
		for(int i = 0; i < mx-1; i++)
			cout << factors[p_mx] << ' ';
		cout << lst << '\n';
	}

	return 0;
}
