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

int n, l, t;
int a[105], ans[105];
pii vals[105];

int main () {
	scanf ("%d", &t);
	for (int caso = 1; caso <= t; caso++) {
		set<int> st;
		map<int, char> mp;
		printf ("Case #%d: ", caso);
		scanf ("%d %d", &n, &l);
		for (int i = 0; i < l; i++)
			scanf ("%d", &a[i]);
		
		// Find the first pair there is diferent
		int frst;
		for (int i = 0;; i++)
			if (a[i] != a[i+1]) {
				frst = i;
				for (int p = 2;; p++) {
					if (a[i]%p == 0) {
						ans[i] = p, ans[i+1] = a[i]/p;
						if (a[i+1]%p == 0)
							swap (ans[i], ans[i+1]);
						break;
					}
				}
				break;
			}
		
		// Back from first
		for (int i = frst; i >= 1; i--)
			ans[i-1] = a[i-1]/ans[i];
		// Forward from first
		for (int i = frst; i < l; i++)
			ans[i+1] = a[i]/ans[i];

		for (int i = 0; i <= l; i++)
			st.insert (ans[i]);
		char c = 'A';
		for (int v : st) 
			mp[v] = c++;
		for (int i = 0; i <= l; i++)
			putchar (mp[ans[i]]);
		putchar ('\n');
	}

	return 0;
}
