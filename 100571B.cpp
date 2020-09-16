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

const int MOD = 1e9 + 7;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10;

int n, q;
int a, b;
int f[N], x[N], x_brute[N], partial_ins[N];
vector<int> partial_rem[N];
int aux[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> q;
	cin >> f[1] >> f[2];
	cin >> a >> b;
	for(int i = 1; i <= n; i++)
		cin >> x[i];

	for(int i = 3; i <= n; i++)
		f[i] = (a*1LL*f[i-2] + b*1LL*f[i-1])%MOD;
	while(q--) {
		int l, r;
		cin >> l >> r;
		// START BRUTE
		// for(int i = 0; i < r-l+1; i++)
		// 	x_brute[l+i] = (x_brute[l+i] + f[i+1])%MOD;
		// END BRUTE
		x[l] = (x[l]+f[1])%MOD;
		if(r > l)
			x[l+1] = (x[l+1]+f[2])%MOD;
		if(r-l+1 >= 3) {
			partial_ins[l+2]++;
			partial_rem[r].push_back(r-l+1);
		}
	}
	// cout << "f = ";
	// for(int i = 1; i <= n; i++)
	// 	cout << f[i] << " \n"[i==n];
	// cout << "x = ";
	// for(int i = 1; i <= n; i++)
	// 	cout << x[i] << " \n"[i==n];

	for(int i = 3; i <= n; i++) {
		while(partial_ins[i]--) {
			aux[i-2] = (aux[i-2]+f[1])%MOD;
			aux[i-1] = (aux[i-1]+f[2])%MOD;
			// cout << "aux[i-2, i-1] = " << aux[i-2] << ' ' << aux[i-1] << '\n';
		}
		aux[i] = ((a*1LL*aux[i-2]) + (b*1LL*aux[i-1]))%MOD;
		x[i] = (x[i] + aux[i])%MOD;

		for(int rem : partial_rem[i]) {
			aux[i-1] = mod(aux[i-1] - f[rem-1]);
			aux[i] = mod(aux[i]-f[rem]);
		}
	}


	for(int i = 1; i <= n; i++)
		cout << x[i] << " \n"[i==n];
	// BRUTE
	// for(int i = 1; i <= n; i++)
	// 	cout << x_brute[i] << " \n"[i==n];

	return 0;
}
