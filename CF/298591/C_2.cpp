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
			inv_mods[i] = inv_mod(pw, m);
			pw = (pw*1LL*base)%m;
		}
		inv_mods[n] = inv_mod(pw, m);
		// inv_mods[1] = 1;
		// for(int i = 2; i < n; i++)
		// 	inv_mods[i] = m - (m/i) * inv_mods[m%i]%m;
		// inv_mods[n-1] = inv_mod((pw*1LL*inv_mod(base, m))%m, m);

		// inv_mods[n-1] = inv_mod(pw, m);
		// for(int i = n-2; i >= 1; i--)
		// 	inv_mods[i] = (base * 1LL * inv_mods[i+1])%m;
	}

	int get_hash(int l, int r) {
		int ret = vals[r];
		if(l) {
			// cout << "ret1 = " << ret << '\n';
			ret = (ret-vals[l-1]+m)%m;
			// cout << "ret2 = " << ret << '\n';
			ret = (ret * 1LL * inv_mods[l])%m;
			// cout << "ret3 = " << ret << '\n';
			// cout << "inv = " << inv_mods[l] << '\n';
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
	// vector<hash_struct> words;
	map<int, int> words;
	bitset<N> words_sizes_msk;
	for(int i = 0; i < n; i++) {
		int d;
		cin >> s >> d;
		// words.push_back({999999937, s, MOD});
		s = s.substr(0, LEN(s)-1);
		words_sizes_msk[LEN(s)] = 1;
		int hash_now = hash_struct(999999937, s, MOD).get_hash(0, LEN(s)-1);
		cout << "s = " << s << ", hash = " << hash_now << '\n';
		words[hash_now] = d;

	}
	vi words_sizes;
	for(int i = 0; i < N; i++)
		if(words_sizes_msk[i])
			words_sizes.push_back(i);
	int ans = 0;
	cin >> s;
	int st = 0;
	hash_struct hash_s = hash_struct(999999937, s, MOD);
	vi dp(LEN(s)+10);
	cout << "HERE!\n";
	cout.flush();
	for(int i = 0; i < LEN(s); i++)
		if(s[i] == 'X') {
			cout << "i = " << i << '\n';
			cout.flush();
			if(st >= i-1) {
				st = i;
				ans+=min_d;
			} else {
				int en = i-1;
				int sz = i-st;
				dp[sz] = 0;
				for(int j = en, p = sz-1; j >= st; j--, p--) {
					// cout << "  j = " << j << '\n';
					cout.flush();
					dp[p] = dp[p+1];
					for(int w_sz : words_sizes) {
						// cout << "   w_sz = " << w_sz << '\n';
						if(w_sz+p-1 < sz) {
							int hash_now = hash_s.get_hash(j, j+w_sz-1);
							// cout << "    hash_now = " << hash_now << '\n';
							if(words.count(hash_now))
								dp[p] = max(dp[p], dp[w_sz+p]+words[hash_now]);
						}
					}
				}
				// cout << "HERE, AFTER!\n";
				cout << "  dp[0] = " << dp[0] << '\n';
				cout.flush();
				ans += max(min_d, dp[0]);
			}
		}
	cout << ans << '\n';

	return 0;
}
