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

int eval (string &s, int st, int en, int cj, int jc) {
	int ret = 0;
	// cerr << "|eval: st = " << st << ", en = " << en << ", s = " << s << '\n';
	for (int i = st; i < en; i++) {
		if (s[i] == 'J' and s[i+1] == 'C') ret += jc;
		else if (s[i] == 'C' and s[i+1] == 'J') ret += cj;
		// cerr << "|  eval: i = " << i << ", ret = " << ret << '\n';
	}
	return ret;
}

string find_bst (string s, int st, int en, int cj, int jc) {
	vector<string> options(4, s);
	for (int i = st; i < en; i++) {
		options[0][i] = 'J';
		options[1][i] = 'C';
		options[2][i] = (i%2 == 0 ? 'J' : 'C');
		options[3][i] = (i%2 == 0 ? 'C' : 'J');
		// cerr << "  |i = " << i << '\n';
	}
	int bst = INF<int>;
	string bst_string;
	for (int i = 0; i < 4; i++) {
		// cerr << "|find_bst: i = " << i << '\n';
		int now = eval(options[i], st, en, cj, jc);
		if (now < bst) {
			bst = now;
			bst_string = options[i];
		}
	}
	return bst_string;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		string s;
		int cj, jc;
		int ans = 0;
		cin >> cj >> jc >> s;
		if (cj > 0 and jc > 0) {
			int st = 0;
			while (st < LEN(s) and s[st] == '?') ++st;
			int en = LEN(s);
			while (en and s[en-1] == '?') --en;
			if (st < en) {
				for (int i = st; i < en; i++) {
					if (s[i] == '?') {
						char ch = s[i-1];
						while (i < en and s[i] == '?')
							s[i++] = ch;
						--i;
					}
				}
			}
		}
		else {
			int st = 0;
			while (st < LEN(s) and s[st] == '?') ++st;
			int en = LEN(s);
			while (en and s[en-1] == '?') --en;
			if (st < en) {
				// Prefix of '?'
				s = find_bst(s, 0, st, cj, jc);
				// Suffix of '?'
				s = find_bst(s, en, LEN(s), cj, jc);

				// Middle
				if (cj+jc >= 0)
					for (int i = st; i < en; i++) {
						if (s[i] == '?') {
							char ch = s[i-1];
							while (i < en and s[i] == '?')
								s[i++] = ch;
							--i;
						}
					}
				else
					for (int i = st; i < en; i++) {
						if (s[i] == '?') {
							char ch = s[i-1];
							for (; i < en and s[i] == '?'; ++i)
								s[i] = (s[i-1] == 'C' ? 'J' : 'C');
							--i;
						}
					}

			}
		}
		cout << "Case #" << test << ": " << eval(s, 0, LEN(s)-1, cj, jc) << '\n';
	}

	return 0;
}
