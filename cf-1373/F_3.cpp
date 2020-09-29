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

const int N = 1e6 + 10;
const int OK = 1e9;

int n;
int need[N], prod[N];

int eval(int x) {
	prod[n] -= x;

	int ret = OK;
	int transf = x;
	for(int i = 1; ret == OK and i <= n; i++)
		if(prod[i]+transf < need[i])
			ret = i;
		else if(i < n)
			transf = min(prod[i]-(need[i]-transf),need[i+1]);

	prod[n] += x;

	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		// cout << n << '\n';
		for(int i = 1; i <= n; i++) {
			cin >> need[i];
			// cout << need[i] << ' ';
		}
		// cout << '\n';
		for(int i = 1; i <= n; i++) {
			cin >> prod[i];
			// cout << prod[i] << ' ';
		}
		// cout << '\n';
		int max_transf = min(prod[n], need[1]);
		int v_max = eval(max_transf);
		int v_min = eval(0);
		if(v_max == OK or v_min == OK)
			cout << "YES\n";
		else if(v_max < n or v_min == n)
			cout << "NO\n";
		else {
			int l = 0, r = max_transf;
			int pow2 = 1;
			int qntOK = 0;
			// for(int i = 1; i < max_transf; i++)
			// 	qntOK += eval(i) == OK;
			// if(qntOK)
			// 	for(int i = 0; i <= max_transf; i++)
			// 		cout << setw(2) << i << ": " << eval(i) << '\n';
			while(l < r) {
				// if(qntOK)
				// 	cout << "l = " << l << ", r = " << r << ", pow2 = "<< pow2 << '\n';
				int md = (l+r)/2;
				int v = eval(md);
				if(v < n)
					l = md+1;
				else if(v == OK)
					l = r = md;
				else
					r = md-1;
			}
			// cout << "L = " << l << '\n';
			cout << (eval(l) == OK ? "YES" : "NO") << '\n';
			// if(qntOK) exit(0);
		}


	}

	return 0;
}
