#include<bits/stdc++.h>
using namespace std;

// ----------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

// ----------------


string mat[20][20];
int n = 5;
vector<string> ans[5];

int main () {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
		
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c;
			scanf (" %c", &c);
			if (c == 'V')
				ans[0].push_back (mat[i][j]);
			else if (c == 'A')
				ans[1].push_back (mat[i][j]);
			else if (c == 'N')
				ans[2].push_back (mat[i][j]);
			else if (c == 'E')
				ans[3].push_back (mat[i][j]);
		}
	for (int i = 0; i < 4; i++) {
		sort (ans[i].begin(), ans[i].end());
		for (int j = 0; j < len (ans[i]); j++) {
			if (j) putchar (' ');
			cout << ans[i][j];
		}
		putchar ('\n');
	}
	
	return 0;
}
