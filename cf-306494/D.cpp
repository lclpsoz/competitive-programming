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
const int MOD = 1e9+7;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

using i128 = __int128_t;

const int N = 1e4 + 10;

bitset<N> not_prime;
vi primes;

pair<vi, vi> factorization (int x) {
	vi factors, exps;
	for (int pr : primes) {
		if (x == 1) break;
		if (x%pr == 0) {
			if (!LEN(factors) or pr != factors.back()) {
				factors.push_back(pr);
				exps.push_back(0);
			}
			while (x%pr == 0) {
				x /= pr;
				exps.back()++;
			}
		}
	}
	assert(LEN(factors) == LEN(exps));
	return {factors, exps};
}

i128 eval (vi &factors, vi &exps) {
	i128 val = 1;
	assert(LEN(factors) == LEN(exps));
	for (int i = 0; val <= INF<ll> and i < LEN(exps); i++)
		for (int j = 0; val <= INF<ll> and j < exps[i]; j++)
			val *= factors[i];
	if(val > INF<ll>)
		return -1;
	return val;
}

ll solve (int a, int b) {
	// cerr << "START SOLVE\n";
	auto _vv = factorization(a);
	vi &factors = _vv.x;
	vi &exps_a = _vv.y;

	vi base_x(LEN(exps_a), 1);

	// cerr << "HERE!\n";
	while (1) {
		i128 val = eval (factors, base_x);
		int p = 1;
		while (val == -1) {
			if (p == LEN(base_x))
				break;
			base_x[p-1] = 1;
			base_x[p++]++;
			val = eval (factors, base_x);
		}
		if (val == -1)
			break;

		// cerr << "val = " << (ll)val << '\n';
		// cerr << "base_x = ";
		// for (int i = 0; i < LEN(base_x); i++)
		// 	cerr << base_x[i] << ' ';
		// cerr << '\n';		
		bool ans = true;
		for (int i = 0; ans and i < LEN(exps_a); i++) {
			if (exps_a[i]*val != base_x[i]*b)
				ans = false;
			// cerr << i << ": " << exps_a[i]*(ll)val << " != " <<  base_x[i]*b << '\n';
		}
		// cerr << '\n';
		if (ans)
			return ((ll)val);

		base_x[0]++;
	}

	return 0LL;
}

bool check (ll a, int b, ll x) {
	ll val_a = 1;
	for(int i = 0; i < x; i++)
		val_a = (a*1LL*val_a)%MOD;

	ll val_b = 1;
	for(int i = 0; i < b; i++)
		val_b = (x*1LL*val_b)%MOD;
	
	return val_a == val_b;
}

void brute () {
	for(int a = 2; a <= 50; a++)
		for(int b = 2; b <= 50; b++) {
			int now = 0;
			for (int x = 2; x < 50; x++)
				if (check(a, b, x)) {
					now = x;
					break;
				}
			if (solve (a, b) < 50 and now != solve (a, b)) {
				cout << "a = " << a << ", b = " << b << ", now = " << now << ", solve = " << solve(a, b) << '\n';
				exit(0);
			}
		}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	for (int i = 2; i*i < N; i++)
		if (!not_prime[i])
			for (int j = i*i; j < N; j+=i)
				not_prime[j] = 1;

	for (int i = 2; i < N; i++)
		if (!not_prime[i])
			primes.push_back(i);

	// brute();

	int a, b;
	cin >> a >> b;
	cout << solve(a, b) << '\n';

	return 0;
}
