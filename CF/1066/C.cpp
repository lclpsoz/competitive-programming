#include "bits/stdc++.h"
using namespace std;

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

const int N = 2e5+100;

int q, id = 1;
deque<int> dq;
int lef[N], rig[N];
map<int, int> mp;

int sum (int p, int *bit) {
	int r = 0;
	for (; p >= 1; p-=p&-p)
		r += bit[p];
	
	return r;
}

void add (int p, int v, int *bit) {
	for (; p < N; p+=p&-p)
		bit[p] += v;
}

int main () {
	scanf ("%d", &q);
	while (q--) {
		char opt;
		int v;
		scanf (" %c %d", &opt, &v);
		if (opt == 'L') {
// 			dq.push_front (v);
			if (id > 1) {
				add (1, 1, lef);
				add (id, -1, lef);
				add (id, id-1, rig);
				add (id+1, -(id-1), rig);
			}
			mp[v] = id++;
		} else if (opt == 'R') {
// 			dq.push_back (v);
			if (id > 1) {
				add (1, 1, rig);
				add (id, -1, rig);
				add (id, id-1, lef);
				add (id+1, -(id-1), lef);
			}
			mp[v] = id++;
		}else {
			int p = mp[v];
// 			printf ("%d %d\n", sum (p, lef), sum (p, rig));
			printf ("%d\n", min (sum (p, lef), sum (p, rig)));
		}
	}

	return 0;
}
