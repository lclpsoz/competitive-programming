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

const int N = 2e5 + 20;

int n, k;
char s[N], str[N];
int bg[N], en[N], sz[N];

int main () {
	scanf ("%d %d %s", &n, &k, s);
	bool rep = s[0] == s[n-1];
	for (int i = 1; !rep and i < n; i++)
		if (s[i] == s[i-1])
			rep = true;

	if (!rep) {
		if (k%2 == 0)
			printf ("%s\n", s);
		else {
			for (int i = 0; s[i] != '\0'; i++)
				putchar (s[i] == 'B' ? 'W' : 'B');
			putchar ('\n');
		}
	} else {
		int pShft = 0;
		if (s[0] == s[n-1]) {
			for (int i = 1; i <= n; i++)
				str[i] = s[i-1];
		} else {
			pShft = 1;
			while (s[pShft] != s[pShft-1]) ++pShft;
			int pos = 1;
			for (int i = 0; i < n; i++)
				str[pos++] = s[(i+pShft)%n];
		}
		str[0] = str[1];
		str[n+1] = str[n];
		// printf ("%s\n", str);
		bool seq = false;
		int posSeq = 0;
		for (int i = 1; i <= n; i++) {
			if (str[i] != str[i-1] and str[i-1] == str[i+1]) {
				if (seq) {
					en[posSeq]++;
					sz[posSeq]++;
				} else {
					posSeq++;
					seq = true;
					bg[posSeq] = i;
					en[posSeq] = i;
					sz[posSeq] = 1;
				}
			} else
				seq = false;
		}

		for (int i = 1; i <= posSeq; i++) {
			int q = k;
			char frst = str[bg[i]], lst = str[en[i]];
			// printf ("l = %d, r = %d, sz = %d\n", bg[i], en[i], sz[i]);
			frst = frst == 'B' ? 'W' : 'B';
			lst = lst == 'B' ? 'W' : 'B';
			for (int j = 0; j < (sz[i]+1)/2; j++) {
				// printf ("  j = %d, q = %d\n", j, q);
				if (q > 0)
					str[j+bg[i]] = frst, str[en[i]-j] = lst;
				else if (k%2 == 1) {
					str[j+bg[i]] = str[j+bg[i]] == 'B' ? 'W' : 'B';
					if (en[i]-j != j+bg[i]) str[en[i]-j] = str[en[i]-j] == 'B' ? 'W' : 'B';
				}
				--q;
			}
		}

		// printf ("pShift = %d\n", pShft);
		// printf ("str = %s\n", str);
		for (int i = 1; i <= n; i++)
			s[i-1] = str[i];
		// printf ("s = %s\n", s);
		for (int i = 0; i < n; i++)
			putchar (s[(i-pShft+n)%n]);
		putchar ('\n');
	}
	
	return 0;
}
