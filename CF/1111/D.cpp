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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(x%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 100;

int m;
int fat[N], qnt[200];
int dp[N];
char s[N];
int mp[200][200];

int invMod (int v) {
	int p = MOD - 2;
	int ret = 1;
	int b = v;
	while (p) {
		if (p&1)
			ret = mod (ret * 1LL * b);
		b = mod (b * 1LL * b);
		p >>= 1;
	}

	return ret;
}

int main () {
	int n = 0;
	scanf ("%s %d", s, &m);
	set<char> st;
	vector<char> allChars;
	for (int i = 0; s[i] != '\0'; i++) {
		qnt[s[i]]++;
		st.insert (s[i]);
		++n;
	}
	for (char c : st)
		allChars.push_back (c);

	// Precalculate fat
	fat[0] = fat [1] = 1;
	for (int i = 2; i <= n/2; i++)
		fat[i] = (fat[i-1] * 1LL * i)%MOD;
	int allInvs = 1;
	for (char c : allChars) {
		if (qnt[c] > n/2) {
			while (m--) printf ("0\n");
			exit (0);
		}
		allInvs = (allInvs*1LL*invMod (fat[qnt[c]]))%MOD;
	}
	int base = mod (mod (fat[n/2] * 1LL * fat[n/2]) * 1LL * allInvs);

	// DP
	dp[0] = 1;
	for (char c : allChars) {
		int q = qnt[c];
		for (int i = n/2; i >= q; i--)
			dp[i] = (dp[i] + dp[i-q])%MOD;
	}

	for (int i = 0; i < len (allChars); i++)
		for (int j = i; j < len (allChars); j++) {
			char a = allChars[i], b = allChars[j];
			int qA = qnt[a], qB = qnt[b];

			for (int k = qA; k <= n/2; k++)
				dp[k] = (dp[k] - dp[k-qA])%MOD;

			if (a != b)
				for (int k = qB; k <= n/2; k++)
					dp[k] = (dp[k] - dp[k-qB])%MOD;

			if (dp[n/2] < 0)
				dp[n/2] += MOD;
			mp[a][b] = mp[b][a] = dp[n/2];

			for (int k = n/2; k >= qA; k--)
				dp[k] = (dp[k] + dp[k-qA])%MOD;
			if (a != b)
				for (int k = n/2; k >= qB; k--)
					dp[k] = (dp[k] + dp[k-qB])%MOD;
		}

	while (m--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		--x, --y;
		int q = mp[s[x]][s[y]];
		if (q == 0)
			printf ("0\n");
		else
			printf ("%d\n", (q * 2LL * base)%MOD);
	}

	return 0;
}
