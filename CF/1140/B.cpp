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

char s[105];

int main () {
	int t, n;
	scanf ("%d %d", &t, &n);
	while (t--) {
		scanf ("%d", &n);
		scanf ("%s", s);
		bool a = true, b = true;
		for (int i = 0; i < n; i++)
			if (s[i] == '>')
				a = false;
			else if (s[i] == '<')
				b = false;
		if (a or b or s[0] == '>' or s[n-1] == '<')
			printf ("0\n");
		else {
			int mini = -1;
			int now = 0;
			for (int i = 0; i < n; i++)
				if (s[i] == '>') break;
				else ++now;
			mini  = now;
			now = 0;
			for (int i = n-1; i >= 0; i--)
				if (s[i] == '<') break;
				else ++now;
			mini = min (mini, now);
			printf ("%d\n", mini);
		}
	}

	return 0;
}
