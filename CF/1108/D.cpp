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

const int N = 2e5+10;

int n;
int dp[N][4];
string str;
vector<int> vec;

int solve (int p, int bef) {
// 	cout << p << ' ' << bef << '\n';
	if (p == n) return 0;
	int &ret = dp[p][bef];
	if (ret != -1) return ret;
	ret = 1e9;
	
	for (int i = 0; i < 3; i++)
		if (i != bef)
			ret = min (ret, (int)(solve (p+1, i) + (str[p] != i)));
		
	return ret;
}

void recu (int p, int bef) {
	if (p == n) return;
	int &ret = dp[p][bef];
	
	for (int i = 0; i < 3; i++)
		if (i != bef)
			if (ret == (solve (p+1, i) + (str[p] != i))) {
				vec.push_back (i);
				recu (p+1, i);
				return;
			}
}


int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	
	memset (dp, -1, sizeof dp);
	
	cin >> n >> str;
	for (int i = 0; i < len (str); i++)
		if (str[i] == 'R') str[i] = 0;
		else if (str[i] == 'G') str[i] = 1;
		else str[i] = 2;
	
	int ans = 1e9;
	for (int i = 0; i < 3; i++)
		ans = min (ans, (int)(solve (1, i) + (str[0] != i)));
	
	cout << ans << '\n';
	
	for (int i = 0; i < 3; i++)
		if (ans == (int)(solve (1, i) + (str[0] != i))) {
			vec.push_back (i);
			recu (1, i);
			break;
		}
	for (int v : vec)
		if (v == 0)
			cout << 'R';
		else if (v == 1)
			cout << 'G';
		else
			cout << 'B';
	cout << '\n';

	return 0;
}
