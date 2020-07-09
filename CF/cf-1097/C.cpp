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

const int N = 5e5+100;

int n;
int lef[N], rig[N], ok;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		pii p = {0, 0};
		string str;
		cin >> str;
		for (int j = 0; j < len (str); j++)
			if (str[j] == ')') {
				if (p.x)
					p.x--;
				else
					p.y++;
			} else
				p.x++;
// 		printf ("%d %d\n", p.x, p.y);
		if (p.x == 0 and p.y == 0)
			++ok;
		else if (p.x == 0)
			rig[p.y]++;
		else if (p.y == 0)
			lef[p.x]++;
	}
	for (int i = 1; i < N; i++)
		ans += min (lef[i], rig[i]);
	ans += ok/2;
	printf ("%d\n", ans);

	return 0;
}
