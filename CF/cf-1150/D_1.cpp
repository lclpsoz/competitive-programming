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

const int N = 1e5 + 10;

int n, q;
int qnt[N];
vector<char> words[5];
bool check[N];
char str[N];

int main () {
	scanf ("%d %d ", &n, &q);
	scanf (" %s", str);
	while (q--) {
		char opt; int id;
		scanf (" %c %d", &opt, &id);
		if (opt == '+') {
			char c;
			scanf (" %c", &c);
			words[id].push_back (c);
		} else
			words[id].pop_back ();
		bool ok = true;
		memset (check, 0, sizeof check);
		for (int i = 1; ok and i <= 3; i++) {
			int p = 0;
			printf ("len = %d\n", len (words[i]));
			for (char c : words[i]) {
				while (p < n)
					if (!check[p] and str[p] == c) {
						check[p] = true;
						break;
					}
					else
						++p;
				printf ("%d: %d\n", i, p);
				if (p == n) {
					ok = false;
					break;
				}
				++p;
			}
		}
		if (ok)
			printf ("YES\n");
		else
			printf ("NO\n");
	}

	return 0;
}
