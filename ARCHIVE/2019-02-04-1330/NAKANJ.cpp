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

using pp = pair<int, pii>;
int t;
string st, targetStr;
bool vis[10][10];

bool valid (int a, int b) {
	return (a >= 1 and a <= 8 and b >= 1 and b <= 8);
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	cin >> t;
	while (t--) {
		memset (vis, false, sizeof vis);
		cin >> st >> targetStr;
		pii target = {targetStr[0]-'a'+1, targetStr[1]-'0'};
		queue<pp> q;
		q.push ({0, {st[0]-'a'+1, st[1]-'0'}});
		while (q.front().y != target) {
			int d = q.front().x;
			pii p = q.front().y;
			q.pop();
			if (vis[p.x][p.y]) continue;
			vis[p.x][p.y] = true;
			for (int i = -2; i <= 2; i+=4)
				for (int j = -1; j <= 1; j+=2) {
					if (valid (p.x+i, p.y+j))
						q.push ({d+1, {p.x+i, p.y+j}});
					if (valid (p.x+j, p.y+i))
						q.push ({d+1, {p.x+j, p.y+i}});
				}
		}
		printf ("%d\n", q.front().x);		
	}

	return 0;
}
