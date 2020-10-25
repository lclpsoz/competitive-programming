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

const int MOD = 1e9+7;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10;

int pow_mod(int b, int p, int m) {
	int ret = 1;
	while(p) {
		if(p&1) ret = (ret *1LL* b)%m;
		p >>= 1;
		b = (b*1LL*b)%m;
	}
	return ret;
}

int inv_mod(int v, int m) {
	return pow_mod(v, m-2, m);
}

struct hash_struct {
	int n, base, m;
	vi vals, inv_mods;
	hash_struct(int _base, string &s, int _m) {
		base = _base;
		n = LEN(s);
		m = _m;
		int pw = 1;
		inv_mods = vi(n+1);
		for(int i = 0; i < n; i++) {
			if(LEN(vals))
				vals.push_back(vals.back());
			else
				vals.push_back(0);
			vals.back() = (vals.back()+(pw*1LL*s[i]))%m;
			pw = (pw*1LL*base)%m;
		}
		inv_mods[n] = inv_mod(pw, m);
		for(int i = n-1; i >= 1; i--)
			inv_mods[i] = (inv_mods[i+1]*1LL*base)%m;
	}

	int get_hash(int l, int r) {
		int ret = vals[r];
		if(l) {
			ret = (ret-vals[l-1]+m)%m;
			ret = (ret * 1LL * inv_mods[l])%m;
		}
		return ret;
	}

};


int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, min_d;
	string s;

	cin >> n >> min_d;
	vector<pair<pii, int>> words;
	bitset<N> words_sizes_msk;
	int base_1 = 999999937, base_2 = 999999797;
	for(int i = 0; i < n; i++) {
		int d;
		cin >> s >> d;
		words_sizes_msk[LEN(s)-1] = 1;
		pii hash_now = {0, 0};
		pii base_now = {1, 1};
		for(int i = 0; i < LEN(s)-1; i++) {
			hash_now.x = (hash_now.x+s[i]*1LL*base_now.x)%MOD;
			hash_now.y = (hash_now.y+s[i]*1LL*base_now.y)%MOD;
			base_now.x = (base_now.x*1LL*base_1)%MOD;
			base_now.y = (base_now.y*1LL*base_2)%MOD;
		}
		words.push_back({hash_now, d});
	}
	vi words_sizes;
	for(int i = 0; i < N; i++)
		if(words_sizes_msk[i])
			words_sizes.push_back(i);

	sort(ALL(words));

	int ans = 0;
	cin >> s;
	int st = 0;
	hash_struct hash_s1 = hash_struct(999999937, s, MOD);
	hash_struct hash_s2 = hash_struct(999999797, s, MOD);
	cout.flush();
	for(int i = 0; i < LEN(s); i++)
		if(s[i] == 'X') {
			cout.flush();
			if(st >= i-1) {
				st = i;
				ans+=min_d;
			} else {
				int en = i-1;
				int sz = i-st;
				int now = min_d;
				for(int w_sz : words_sizes) {
					if(w_sz <= sz) {
						pii hash_now = {
							hash_s1.get_hash(i-w_sz, i-1),
							hash_s2.get_hash(i-w_sz, i-1)
						};
						auto it = lower_bound(ALL(words), make_pair(hash_now, 0));
						if(it != words.end() and it->x == hash_now)
							now = max(now, it->y);
					}
					else
						break;
				}
				ans += now;
			}
		}
	cout << ans << '\n';

	return 0;
}
