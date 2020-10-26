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

const int MOD = 11092019;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	string s;
	cin >> s;
	int n = LEN(s);
	
	int ans = 1;
	// int now = 1;
	// vi p2(n+1);
	// for(int i = 0; i < n; i++) {
	// 	ans = (ans + now)%MOD;
	// 	p2[i+1] = (p2[i]+now)%MOD;
	// 	now = (now*2)%MOD;
	// }

	vi amnt(200);
	for(int i = 0; i < n; i++)
		amnt[s[i]]++;

	ans = 1;
	for(int i = 'a'; i <= 'z'; i++)
		if(amnt[i])
			ans = (ans*1LL*(amnt[i]+1))%MOD;
	// cout << "bef = " << ans << '\n';
	// for(int i = 'a'; i <= 'z'; i++)
	// 	if(amnt[i]) {
	// 		int val = ((p2[amnt[i]]-amnt[i])*1LL*(p2[n-amnt[i]]+1))%MOD;
	// 		cout << "amnt = " << amnt[i] << ", p2 = " << p2[amnt[i]] << ", val = " << val << '\n';
			
	// 		ans = (ans-val+MOD)%MOD;
	// 	}

	cout << ans << '\n';

	return 0;
}
