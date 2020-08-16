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

const int P = 1e5 + 10;

bitset<P> not_prime;
vector<int> primes;
vector<int> fact, expo;

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	for(int i = 2; i*i < P; i++)
		if(!not_prime[i])
			for(int j = i*i; j < P; j+=i)
				not_prime[j] = 1;
	for(int i = 2; i < P; i++)
		if(!not_prime[i]) primes.push_back(i);

	int t, n;
	cin >> t;
	while(t--) {
		expo.clear(), fact.clear();
		cin >> n;
		int pos = 0;
		while(n > 1 and pos < LEN(primes)) {
			int prime = primes[pos];
			while(n%prime == 0) {
				if(fact.empty() or fact.back() != prime)
					fact.push_back(prime), expo.push_back(1);
				else
					expo.back()++;
				n/=prime;
			}
			++pos;
		}
		if(n > 1)
			fact.push_back(n), expo.push_back(1);
		// int sum = 0;
		// for(int v : expo) {
		// 	if(v <= 1) sum++;
		// 	else if(v )
		// }
		// cout << "sum = " << sum << '\n';
		if(LEN(fact) == 1 and expo[0] >= 6) {
			int a = fact[0];
			int b = fact[0]*fact[0];
			expo[0] -= 3;
			int c = 1;
			while(expo[0]--) c*=fact[0];
			cout << "YES\n";
			cout << a << ' ' << b << ' ' << c << '\n';
		}
		else if(LEN(fact) == 2) {
			if(expo[0] > expo[1]) swap(expo[0], expo[1]), swap(fact[0], fact[1]);
			if(expo[0] == 1) {
				if(expo[1] <= 2)
					cout << "NO\n";
				else {
					int a = fact[1];
					int b = a*a;
					expo[1] -= 3;
					int c = 1;
					for(int i = 0; i < LEN(expo); i++)
						for(int j = 0; j < expo[i]; j++)
							c *= fact[i];
					cout << "YES\n";
					cout << a << ' ' << b << ' ' << c << '\n';	
				}
			} else {
				int a = fact[0];
				int b = fact[0]*fact[1];
				expo[0] -= 2;
				expo[1]--;
				int c = 1;
				for(int i = 0; i < LEN(expo); i++)
					for(int j = 0; j < expo[i]; j++)
						c *= fact[i];
				cout << "YES\n";
				cout << a << ' ' << b << ' ' << c << '\n';	
			}
		}
		else if(LEN(fact) >= 3) {
			int a = fact[0];
			expo[0]--;
			int b;
			b = fact[1], expo[1]--;
			int c = 1;
			for(int i = 0; i < LEN(expo); i++)
				for(int j = 0; j < expo[i]; j++)
					c *= fact[i];
			cout << "YES\n";
			cout << a << ' ' << b << ' ' << c << '\n';
		} else {
			cout << "NO\n";
		}
			
	}

	return 0;
}
