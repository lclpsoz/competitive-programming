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

using vb = vector<bool>;

int t, n;

bool check(int x) {
	// cout << bitset<6>(x) << '\n';
	for(int i = 0; i < n; i++) {
		int nxt = (x&(1<<((i+1)%n)))>0;
		int bef = (x&(1<<((i-1+n)%n)))>0;
		int now = (x&(1<<i))>0;
		
		// cout << i << ": " << bef << ' ' << nxt << ' ' << now << '\n';

		if(nxt == now and bef == now)
			return false;
	}
	return true;
}

int brute(vb &vec) {
	int now = 0;
	for(int i = 0; i < n; i++)
		if(vec[i])
			now ^= (1<<i);
	int ret = n;
	for(int i = 0; i < (1<<n); i++)
		if(check(i)) {
			ret = min(ret, __builtin_popcount(now^i));
			// if(i == now) {
			// 	cout << bitset<13>(i) << '\n';
			// }
		}
	return ret;
}

int solve_wa(vb vec, vi st) {
	int ret = 0;
	for(int i = st[0]; i < n; i+=3) {
		if(vec[(i-1+n)%n] == vec[(i+1)%n] and vec[(i+1)%n] == vec[i])
			++ret, vec[i] = !vec[i];
		// cout << i << ' ' << ans << '\n';
	}
	for(int i = st[1]; i < n; i+=3) {
		if(vec[(i-1+n)%n] == vec[(i+1)%n] and vec[(i+1)%n] == vec[i])
			++ret, vec[i] = !vec[i];
		// cout << i << ' ' << ans << '\n';
	}
	for(int i = st[2]; i < n; i+=3) {
		if(vec[(i-1+n)%n] == vec[(i+1)%n] and vec[(i+1)%n] == vec[i])
			++ret, vec[i] = !vec[i];
		// cout << i << ' ' << ans << '\n';
	}
	return ret;
}

int calc(int x) {
	// cout << "x = " << x << '\n';
	return x/3;
}

int solve(vb vec, int v) {
	// cout << "\nv = " << v << '\n';
	vi pos;
	for(int i = 0; i < n; i++)
		if(vec[i] == v) pos.push_back(i);
	// cout << LEN(zeros) << '\n';
	if(LEN(pos) == 0) return calc(n+2);
	int m = LEN(pos);
	// cout << "m = " << m << '\n';
	if(m == 1)
		return calc(n-1);
	else {
		int ret = calc((n-pos.back()-1)+pos[0]);
		for(int i = 1; i < m; i++)
			ret += calc(pos[i]-pos[i-1]-1);
		return ret;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	// vector<vb> al;
	// n = 14;
	// for(int i = 0; i < (1<<n); i++) {
	// 	vb now;
	// 	for(int j = 0; j < n; j++) {
	// 		now.push_back((i&(1<<j))>0);
	// 		// cout << now.back() << '\n';
	// 	}
	// 	al.push_back(now);
	// }

	cin >> t;
	// t = LEN(al);
	while(t--) {
		cin >> n;
		// vb vec = al[t];
		// cout << "t = " << t << '\n';
		vb vec;
		for(int i = 0; i < n; i++) {
			char x;
			cin >> x;
			vec.push_back(x=='R');
		}
		int ans = 1e9;
		int ans_brute = brute(vec);
		// vi perm = {0, 1, 2};
		// do {
		// 	ans = min(solve(vec, perm), ans);;
		// } while(next_permutation(ALL(perm)));

		ans = solve(vec, 0) + solve(vec, 1);
		// if(ans != ans_brute) {
		// 	for(int v : vec)
		// 		cout << v << ' ';
		// 	cout << '\n';
		// 	cout << ans << ' ' << ans_brute << '\n';
		// }
		// assert(ans == ans_brute);
		cout << ans << '\n';
	}

	return 0;
}
