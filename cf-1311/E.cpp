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

const int N = 1e4 + 10;

int a[N], acu[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	int n, t, d;
	cin >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 0; i <= n+1; i++) acu[i] = 0, a[i] = 0;
		int dep = 1;
		int sum = 0;
		int nn = n;
		--n;
		for(int i = 1;n; i++) {
			int ax = min((1<<i), n);
			a[i] = ax;
			sum += ax*dep++;
			n -= ax;
		}
		// cout << sum << '\n';
		if(sum > d or d > (nn*1LL*(nn-1))/2)
			cout << "NO\n";
		else {
			for(int i = 1; a[i] and i < N and sum < d; i++) {
				// cout << "i = " << i << '\n';
				// for(int j = 1; j < 12; j++)
				// 	cout << a[j] << " \n"[j==11];
				if(2*(a[i]-1) >= (a[i+1]+1)) {
					a[i+1]++;
					a[i]--;
					sum++;
					i = 0;
				}
				// cout << "    after i = " << i << '\n';
				// for(int j = 1; j < 12; j++)
				// 	cout << a[j] << " \n"[j==11];
			}
			if(sum < d) {
				cout << "NO\n";
				continue;
			}
			acu[0] = 1;
			for(int i = 1; i < N; i++)
				acu[i] += a[i] +acu[i-1];
			int lstId = 1;
			int qnt = 0;
			cout << "YES\n";
			for(int i = 1; a[i];) {
				a[i]--;
				qnt++;
				cout << lstId << ' ';
				if(qnt == 2) {
					lstId++;
					qnt = 0;
				}
				if(a[i] == 0) {
					++i;
					lstId = acu[i-2]+1;
					qnt = 0;
				}
				// cout << "a[i] = " << a[i] << '\n';
			}
			cout << '\n';
		}
	}

	return 0;
}
