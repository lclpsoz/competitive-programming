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
const pii BASE = {999999893, 1073741789};

int n;
string s;
set<pii> hashs;
pii inv[N], pref[N];

int invMod(int x) {
	int ret = 1;
	int p = MOD-2;
	while(p) {
		if(p&1) ret = (x * 1LL * ret)%MOD;
		x = (x * 1LL * x)%MOD;
		p /= 2;
	}

	return ret;
}

void pre_hashing() {
	inv[0] = {1, 1};
	inv[1] = {invMod(BASE.x), invMod(BASE.y)};
	for(int i = 2; i <= n; i++) {
		inv[i].x = (inv[i-1].x*1LL*inv[1].x)%MOD;
		inv[i].y = (inv[i-1].y*1LL*inv[1].y)%MOD;
	}

	pref[0] = {0, 0};
	pref[1] = {s[0], s[0]};
	pii base_now = BASE;
	for(int i = 2; i <= n; i++) {
		pref[i].x = (pref[i-1].x + s[i-1]*1LL*base_now.x)%MOD;
		pref[i].y = (pref[i-1].y + s[i-1]*1LL*base_now.y)%MOD;
		base_now = {(base_now.x * 1LL * BASE.x)%MOD,
					(base_now.y * 1LL * BASE.y)%MOD};
	}
}

pii get_hash(int l, int r) {
	return {mod((pref[r].x - pref[l-1].x)*1LL*inv[l-1].x),
			mod((pref[r].y - pref[l-1].y)*1LL*inv[l-1].y)};
}

pair<vector<int>, vector<int>> manacher() {
    vector<int> d1(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}

	vector<int> d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k ;
		}
	}

	return {d1, d2};
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> s;
	pre_hashing();
	auto man = manacher();
	vector<int> d1 = man.x, d2 = man.y;

	// cout << invMod(BASE) << '\n';
	// for(int i = 0; i < n; i++)
	// 	for(int j = i; j < n; j++)
	// 		cout << i << ' ' << j << " = " << get_hash(i+1, j+1) << '\n';

	int ans = 0;
	// Odd length
	for(int i = 0; i < n; i++)
		for(int sz = d1[i]; sz > 1; sz--) {
			bool inserted = hashs.insert(get_hash(i+1, i+sz)).y;
			ans += inserted;
			if(!inserted) break;
		}
	// hashs.clear();
	// // Even length
	// for(int i = 0; i < n; i++)
	// 	for(int sz = d2[i]; sz; sz--) {
	// 		bool inserted = hashs.insert(get_hash(i+1, i+sz)).y;
	// 		ans += inserted;
	// 		if(!inserted) break;
	// 	}
	
	cout << ans << '\n';

	return 0;
}
