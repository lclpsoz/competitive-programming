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

const int N = 1e6;

int n, ans;
int trie[N][5];
int lstPos;

void ins (string str, int p, int pTrie) {
	trie[pTrie][2]++;
	if (p == len (str))
		return;
	int &v = trie[pTrie][str[p]-'0'];
	if (v == 0) v = ++lstPos;
	ins (str, p+1, v);
}

void dfs (int p) {
	++ans;
	if (p == 0) return;
	if (trie[p][2] <= 1) return;
	dfs (trie[p][0]);
	dfs (trie[p][1]);
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		ins (str, 0, 0);
	}
	ans = 1;
	if (n > 1) {
		dfs (trie[0][0]);
		dfs (trie[0][1]);
	}
	cout << ans << '\n';
	
	return 0;
}
