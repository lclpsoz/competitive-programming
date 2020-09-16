// O(N) solution

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

int n;
int a[N], l[N], r[N];
vector<int> vec;
int ans[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		while(LEN(vec) and a[i] <= a[vec.back()])
			vec.pop_back();
		if(LEN(vec))
			l[i] = vec.back();
		else
			l[i] = 0;
		vec.push_back(i);
	}
	vec.clear();
	for(int i = n; i >= 1; i--) {
		while(LEN(vec) and a[i] <= a[vec.back()])
			vec.pop_back();
		if(LEN(vec))
			r[i] = vec.back();
		else
			r[i] = n+1;
		vec.push_back(i);
	}
	for(int i = 1; i <= n; i++) {
		ans[r[i]-l[i]-1] = max(a[i], ans[r[i]-l[i]-1]);
		// cout << "i = " << i << ", a[i] = " << a[i] << ", l[i] = " << l[i] << ", r[i] = " << r[i] << '\n';
	}

	for(int i = n; i >= 1; i--)
		ans[i] = max(ans[i], ans[i+1]);

	for(int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i==n];

	return 0;
}
