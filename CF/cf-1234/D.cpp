#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 1e5 + 10;

int q;
char s[N];
ordered_set st[30];

int main () {
	scanf ("%s %d", s, &q);
	for (int i = 0; s[i] != '\0'; i++)
		st[s[i]-'a'].insert (i);
	while (q--) {
		int o;
		scanf ("%d", &o);
		if (o == 1) {
			int pos; char c;
			scanf ("%d %c", &pos, &c);
			--pos;
			st[s[pos]-'a'].erase (pos);
			s[pos] = c;
			st[s[pos]-'a'].insert (pos);
		} else {
			int l, r;
			scanf ("%d %d", &l, &r);
			--l, --r;
			int ans = 0;
			for (int i = 0; i <= 'z'-'a'; i++)
				ans += (st[i].order_of_key (l) - st[i].order_of_key (r+1)) > 0;
			printf ("%d\n", ans);
		}
	}
	

	return 0;
}
