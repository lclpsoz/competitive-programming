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

const int N = 3005;

int dp[N][N];
string s1, s2;
char ans[N];

void recu (int x, int y) {
	if (x == 0 or dp[x][y] == 0) return;
	while (dp[x-1][y] == dp[x][y]) --x;
	while (dp[x][y-1] == dp[x][y]) --y;
	ans[dp[x][y]] = s1[x-1];
	recu (x-1, y-1);
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	cin >> s1 >> s2;
	for (int i = 1; i <= len (s1); i++) {
		for (int j = 1; j <= len (s2); j++) {
			dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
			if (s1[i-1] == s2[j-1])
				dp[i][j] = max (dp[i][j], dp[i-1][j-1] + 1);
// 			cout << dp[i][j] << ' ';
		}
// 		puts ("");
	}

	recu (len (s1), len (s2));
	for (int i = 1; i <= dp[len (s1)][len (s2)]; i++)
		cout << ans[i];
	cout << '\n';
	
	return 0;
}
