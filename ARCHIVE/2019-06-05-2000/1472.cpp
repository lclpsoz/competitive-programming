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

const int N = 1e5+10;

int n;
int arr[N];
int nxt[N];

int main () {
	while (scanf ("%d", &n) != EOF) {
		int s = 0;
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &arr[i]);
			s += arr[i];
			nxt[i] = -1;
		}
		nxt[n+1] = -1;
		if (s%3) {
			printf ("0\n");
			continue;
		} else {
			s/=3;
			int p1, p2;
			p1 = p2 = 1;
			int now = 0;
			for (;p2 <= n+1;) {
				if (now < s)
					now += arr[p2++];
				else {
					if (now == s)
						nxt[p1] = p2;
					now -= arr[p1++];
				}
			}
			int ans = 0;
			for (int i = 1; i <= n; i++)
				if (nxt[i] != -1 and nxt[nxt[i]] != -1) {
					nxt[nxt[i]] = -1;
					++ans;
				}
			printf ("%d\n", ans);
		}
	}

	return 0;
}
