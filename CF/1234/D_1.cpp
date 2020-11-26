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
const int SQ = 400;

int q, sq = 10000;
char s[N];
int esq[N], dir[N];
ordered_set st[SQ];
map<char, int> mp;
set<pair<char, int>> rem;

void updEsq (int p, int v, int t = 0) {
	st[p/sq].erase (esq[p]);
	st[p/sq].insert (v);
	esq[p] = v;
}

int main () {
	scanf (" %s %d", s, &q);
	int n = strlen (s);
	
	// Fill esq and dir arrays
	// Esq: Position of the first equal char from the left, -1 if doesn't exist
	// Dir: Position of the first equal char from the right, -1 if doesn't exist
	for (int i = 0; i < n; i++) {
		if (mp.count (s[i]))
			esq[i] = mp[s[i]];
		else
			esq[i] = -1;
		mp[s[i]] = i;
		st[i/sq].insert (esq[i]);
		rem.insert ({s[i], i});
	}
	mp.clear();
	for (int i = n-1; i >= 0; i--) {
		if (mp.count (s[i]))
			dir[i] = mp[s[i]];
		else
			dir[i] = -1;
		mp[s[i]] = i;
	}

	// Queries
	while (q--) {
		int o;
		scanf ("%d", &o);

		if (o == 1) {
			int pos; char c;
			scanf ("%d %c", &pos, &c);
			--pos;
			if (s[pos] == c) continue;
			rem.erase ({s[pos], pos});
			s[pos] = c;
			auto it = rem.lower_bound ({s[pos], pos}); // Get the first occurrence of s[pos] after it
			st[pos/sq].erase (esq[pos]);
			
			if (dir[pos] != -1)
				updEsq (dir[pos], esq[pos]);
			if (esq[pos] != -1)
				dir[esq[pos]] = dir[pos];

			if (it == rem.end())
				dir[pos] = -1;
			else if (it->x == s[pos]) {
				dir[pos] = it->y;
				updEsq (dir[pos], pos);
			} else
				dir[pos] = -1;

			if (it == rem.begin())
				esq[pos] = -1;
			else {
				--it;
				if (it->x == s[pos]) {
					esq[pos] = it->y;
					dir[esq[pos]] = pos;
				}
				else
					esq[pos] = -1;
			}
			st[pos/sq].insert (esq[pos]);
			rem.insert ({s[pos], pos});

		} else { // QUERY 2
			int l, r;
			scanf ("%d %d", &l, &r);
			--l;
			int qntRep = 0;
			int p = l;
			while (p < r and p%sq) {
				qntRep += l <= esq[p];
				++p;
			}
			while (p+sq-1 < r) {
				qntRep += st[p/sq].order_of_key(r) - st[p/sq].order_of_key (l);
				p += sq;
			}
			while (p < r) {
				qntRep += l <= esq[p];
				++p;
			}
			printf ("%d\n", r - l - qntRep);
		}
	}

	return 0;
}