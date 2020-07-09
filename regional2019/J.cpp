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

int n, k;
map<char, int> mp;
int qnt[15][15];

int main () {
	mp['A'] = 1;
	for (int i = 2; i <= 9; i++) mp[i+'0'] = i;
	mp['D'] = 10;
	mp['Q'] = 11;
	mp['J'] = 12;
	mp['K'] = 13;
	scanf ("%d %d", &n, &k);
	--k;
	for (int i = 0; i < n; i++) {
		char str[20];
		scanf ("%s", str);
		for (int j = 0; j < 4; j++) {
			qnt[i][mp[str[j]]]++;
			if (qnt[i][mp[str[j]]] == 4 and i != k) {
				printf ("%d\n", i+1);
				exit (0);
			}
		}
	}

	int pos = k;
	bool canPass = false;
	while (true) {
		// printf ("pos = %d, k = %d\n", pos, k);
		if (pos == k and canPass) k = (k+1)%n, canPass = false;
		else {
			canPass = true;
			int mn = 10, now = -1;
			for (int card = 0; card < 15; card++) {
				// printf ("%d ", qnt[pos][card]);
				if (qnt[pos][card] and qnt[pos][card] < mn) {
					mn = qnt[pos][card];
					now = card;
				}
			}
			// putchar ('\n');
			// putchar ('\n');
			qnt[pos][now]--;
			qnt[(pos+1)%n][now]++;
		}
		for (int card = 0; card < 15; card++) {
			if (qnt[pos][card] == 4 and pos != k) {
				printf ("%d\n", pos+1);
				exit (0);
			}
		}

		++pos;
		pos%=n;
	}



	return 0;
}
