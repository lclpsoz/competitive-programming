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

const int N = 1000;

map<char, char> mp;
char str[N];

int main () {

	for (char i = 0; i < 125; i++)
		mp[i] = i;
	mp['@'] = 'a';
	mp['&'] = 'e';
	mp['!'] = 'i';
	mp['*'] = 'o';
	mp['#'] = 'u';
	while (scanf ("%[^\n]s", str) != EOF) {
		for (int i = 0; i < strlen (str); i++)
			str[i] = mp[str[i]];
		printf ("%s\n", str);
		getchar();
	}

	return 0;
}
