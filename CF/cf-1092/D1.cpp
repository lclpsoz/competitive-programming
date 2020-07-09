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

int n;
stack<pii> st;

int main () {
	scanf ("%d", &n);
	if (n == 1) {
		printf ("YES\n");
		return 0;
	}

	int mx = -1;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		mx = max (x, mx);
		int pos = i;
		while (!st.empty() and st.top().x == x) {
			pos = st.top().y;
			st.pop();
		}
		while (!st.empty() and st.top().x < x)
			if ((i-st.top().y) % 2 != 0) {
				pii ax = st.top();
				st.pop();
				if (!st.empty() and (i-st.top().y)%2 == 1) {
					printf ("NO\n");
					return 0;
				} else {
					if (!st.empty()) st.pop(); // The before one
					st.push ({ax.x+2, ax.y});
				}
			} else
				st.pop();
		if (st.empty() or st.top().x > x)
			st.push ({x, pos});
	}
	int x = mx;
	int i = n+1;
	while (!st.empty() and st.top().x == x)
		st.pop();
	while (!st.empty() and st.top().x < x)
		if ((i-st.top().y) % 2 != 0) {
			pii ax = st.top();
			st.pop();
			if (!st.empty() and (i-st.top().y)%2 == 1) {
				printf ("NO\n");
				return 0;
			} else {
				if (!st.empty()) st.pop(); // The before one
				st.push ({ax.x+2, ax.y});
			}
		} else
			st.pop();
	
	printf ("YES\n");

	return 0;
}