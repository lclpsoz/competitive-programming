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
string strAns[100];
ll ans[100];

int main () {
	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 2;
	strAns[0] = "0";
	strAns[1] = "1";
	strAns[2] = "2";
	for (int i = 3; i <= 60; i++) {
//   		cout << i << '\n';
		string str = to_string (ans[i-1] + ans[i-2]);
//  		cout << str << '\n';
 		strAns[i] = str;
		reverse (str.begin(), str.end());
//   		cout << str << '\n';
		ans[i] = stoll (str);
	}
	while (scanf ("%d", &n) != EOF)
		cout << strAns[n] << '\n';

	return 0;
}
