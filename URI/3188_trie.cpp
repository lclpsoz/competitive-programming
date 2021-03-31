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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10;
const int POS_SOME = 10, POS_END = 11;

int trie[N][12];
int trie_pos = 1;

bool ins (string &s, int pos_str = 0, int pos_t = 1) {
	// cerr << "|ins(): s = " << s << ", pos_str = " << pos_str << ", pos_t = " << pos_t << ", POS_END = " << trie[pos_t][POS_END] << '\n';
	if (trie[pos_t][POS_END]) return false;
	if (pos_str == LEN(s)) {
		if (trie[pos_t][POS_SOME])
			return false;
		return trie[pos_t][POS_END] = 1;
	}
	else {
		int nxt_c = s[pos_str]-'0';
		if (trie[pos_t][nxt_c] == 0) {
			trie[pos_t][nxt_c] = ++trie_pos;
			trie[pos_t][POS_SOME] = 1;
			if (trie[trie_pos][POS_SOME] or trie[trie_pos][POS_END])
				memset(trie[trie_pos], 0, sizeof trie[trie_pos]);
		}
		return ins(s, pos_str+1, trie[pos_t][nxt_c]);
	}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		trie_pos = 1;
		memset(trie[trie_pos], 0, sizeof trie[trie_pos]);
		int n;
		cin >> n;
		bool ans = true;
		while (n--) {
			string s;
			cin >> s;
			ans = ans and ins(s);
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}
