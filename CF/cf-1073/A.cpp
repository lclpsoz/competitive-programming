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
string str;

int main () {
	cin >> n >> str;
	char c = str[0];
	for (int i = 1; i < len (str); i++)
		if (str[i] != c) {
			cout << "YES\n";
			cout << str[i-1] << str[i] << '\n';
			return 0;
		}
		
	cout << "NO\n";
	
	return 0;
}
