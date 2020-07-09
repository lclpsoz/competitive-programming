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

const int MAXM = (1<<20) + 10;
const int MSK = (1<<20) - 1;

string s;
int dp[MAXM];
int qnt[20];

int solve (int msk) {
	int &ret = dp[msk];
	if (ret != -1) return ret;
	for (int i = 0; i < 20; i++)
		if (msk & (1<<i))
			ret = max (ret, solve (msk^(1<<i)));
	return ret;
}

int main () {
	ios::sync_with_stdio (false);
	memset (dp, -1, sizeof dp);
	dp[0] = 0;
	cin >> s;
	for (int i = 0; i < len (s); i++) s[i] -= 'a';
	for (int sz = 1; sz <= min (len (s), 20); sz++) {
		int now = 0;
		memset (qnt, 0, sizeof qnt);
		for (int j = 0;  j < sz; j++) {
			qnt[s[j]]++;
			now |= 1<<s[j];
		}
		if (__builtin_popcount (now) == sz) dp[now] = sz;
		for (int j = sz; j < len (s); j++) {
			qnt[s[j-sz]]--;
			if (!qnt[s[j-sz]]) now ^= (1<<s[j-sz]);
			qnt[s[j]]++;
			now |= (1<<s[j]);
			if (__builtin_popcount (now) == sz) dp[now] = sz;
		}
	}
	int ans = -1;
	for (int i = 0; i < MAXM; i++) {
		ans = max (ans, solve (i) + solve ((~i) & MSK));
	}
	printf ("%d\n", ans);


	return 0;
}
