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

using pp = pair<int, pair<string, string>>;
const int N = 1e5+100;

string MAXI = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

int n;
string str1, str2;
pp a[N];

int main () {
	cin.tie (0); cout.tie (0);
	ios::sync_with_stdio (false);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str1 >> str2;
		a[i].y = {str1, str2};
	}
	for (int i = 1; i <= n; i++) {
		int p; cin >> p;
		a[p].x = i;
	}
	sort (a+1, a+n+1);
// 	for (int i = 1; i <= n; i++)
// 		cout << a[i].x << ' ' << a[i].y.x << ' ' << a[i].y.y << '\n';
	
	for (int i = 1; i <= n; i++) {
		int qnt = 0;
		if (a[i-1].y.x > a[i].y.x and a[i-1].y.y > a[i].y.x) {
			a[i].y.x = MAXI;
			++qnt;
		}
		if (a[i-1].y.x > a[i].y.y and a[i-1].y.y > a[i].y.y) {
			a[i].y.y = MAXI;
			++qnt;
		}
		if (qnt == 2) {
			cout << "NO\n";
			return 0;
		}
	}
// 	for (int i = 1; i <= n; i++)
// 		cout << a[i].y.x << ' ' << a[i].y.y << '\n';
	
	cout << "YES\n";

	return 0;
}
