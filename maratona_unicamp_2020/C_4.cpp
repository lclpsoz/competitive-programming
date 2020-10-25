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

const int T = 1e6, A = 31;

int trie[T][A];
int pos_used_trie = 1;

void add(string &s, int p_s, int p_trie, int val) {
	// cout << "s = " << s << ", p_s = " << p_s << ", p_trie = " << p_trie << '\n';
	int *trie_now = trie[p_trie];
	if(p_s == LEN(s))
		trie_now[A-1] = max(val, trie_now[A-1]);
	else {
		if(!trie_now[s[p_s]-'A'])
			trie_now[s[p_s]-'A'] = ++pos_used_trie;
		add(s, p_s+1, trie_now[s[p_s]-'A'], val);
	}
}

int get_trie(string &s, int p_s, int p_trie) {
	// cout << "qry: s = " << s << ", p_s = " << p_s << '\n';
	if(!p_trie) return 0;
	int *trie_now = trie[p_trie];
	if(p_s == LEN(s)) return trie_now[A-1];
	return max(trie_now[A-1], get_trie(s, p_s+1, trie_now[s[p_s]-'A']));
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, d_min;
	string s;
	cin >> n >> d_min;
	for(int i = 0; i < n; i++) {
		int d;
		cin >> s >> d;
		reverse(ALL(s));
		s = s.substr(1);
		add(s, 0, 1, d);
	}

	cin >> s;
	int l = 0;
	int ans = 0;
	if(s[l] == 'X') ans = d_min;
	// cout << "S = " << s << '\n';
	for(int r = 1; r < LEN(s); r++) 
		if(s[r] == 'X') {
			// cout << " r = " << r << '\n';
			if(r == l+1) {
				ans += d_min;
				l = r;
			} else {
				// cout << " l = " << l << ", r = " << r << '\n';
				if(s[l] == 'X') ++l;
				string s_now = s.substr(l, r-l);
				reverse(ALL(s_now));
				ans += max(d_min, get_trie(s_now, 0, 1));
				// cout << "get = " << get_trie(s_now, 0, 0) << '\n';
				l = r;
			}
		}
	cout << ans << '\n';
	

	return 0;
}
