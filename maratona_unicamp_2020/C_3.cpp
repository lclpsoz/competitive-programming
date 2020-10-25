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

const int A = 30;

struct node {
	node *nxt[A];
	int val;
	node() {
		for(int i = 0; i < A; i++)
			nxt[i] = NULL;
		val = 0;
	}

	node *get(char c) {
		return nxt[c-'A'];
	}

	node set(char c, node *_node) {
		nxt[c-'A'] = _node;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, d_min;
	string s;
	cin >> n >> d_min;

	node root = node();
	for(int i = 0; i < n; i++) {
		int d;
		cin >> s >> d;
		reverse(ALL(s));
		s = s.substr(1);
		node *cur = &root;
		cout.flush();
		for(char c : s) {
			cout.flush();
			if(cur->get(c) == NULL) {
				cout.flush();
				cur->set(c, new node());
			}
			cur = cur->get(c);
		}
		cur->val = d;
	}

	cin >> s;
	int l = 0;
	int ans = 0;
	for(int r = 0; r <= LEN(s); r++)
		if(s[r] == 'X')
			if(r == l) {
				ans += d_min;
				l = r+1;
			} else { 
				cout.flush();
				string s_now = s.substr(l, r-l);
				reverse(ALL(s_now));
				node *cur = &root;
				int now = d_min;
				for(char c : s_now) {
					if(cur->get(c)) {
						cur = cur->get(c);
						now = max(now, cur->val);
					} else
						break;
				}
				ans += now;
				l = r+1;
			}
	cout << ans << '\n';


	return 0;
}
