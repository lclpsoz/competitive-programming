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

string str;
char ans[100];

int main () {
	cin >> str;
	int st = (len (str) - 1) /2;
// 	cout << st << '\n';
	ans[0] = str[st];
	for (int i = st+1, j = 1; i < len (str); i++, j+=2)
		ans[j] = str[i];
	for (int i = st-1, j = 2; i >= 0; i--,j+=2)
		ans[j] = str[i];
	printf ("%s\n", ans);

	return 0;
}
