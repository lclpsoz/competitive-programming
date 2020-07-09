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

string s;
int qnt[310];

bool palin (int l, int r) {
	int n = (r-l+1);
	if (n == 1) return false;
	for (int i = 0; i < n/2; i++)
		if (s[l+i] != s[r-i])
			return false;
	return true;
}

bool ok[310];

int main () {
	cin >> s;
	int total = 0;
	int ans = 0;
	bool zero = true;
	for (int i = 0; i < len (s); i++)
		for (int j = 0; j < len (s); j++)
			if (palin (i, j))
				for (int k = i; k <= j; k++)
					{zero = false; break;};
	if (zero) printf ("0\n");
	do {
		memset (qnt, 0, sizeof qnt);
		int maxi  = -1;
		for (int i = 0; i < len (s); i++)
			for (int j = 0; j < len (s); j++)
				if (palin (i, j))
					for (int k = i; k <= j; k++) {
						qnt[k]++;
						maxi = max (maxi, qnt[k]);
					}
		if (maxi == -1) break;
		for (int i = 0; i < len (s); i++)
			if (qnt[i] == maxi) {
				ans += !ok[i];
				ok[i] = true;
				s[i] = (((s[i]-'a')+1)%('z'-'a'))+'a';
				break;
			}
	cout << s << '\n';
	} while (true);
	cout << s << '\n';
	printf ("%d\n", ans);

	return 0;
}
