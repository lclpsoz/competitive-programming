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

const int M = 5e5+100;
const int FLAG = 29;

int n, m;
int opt;
string key, keyNow;
int trie[M][30];
int lstPos;
char conv[30];

void add (string str, int p = 0, int tPos = 0) {
	if (len (str) == p) {
		trie[tPos][FLAG] = -1;
		return;
	}
	int &now = trie[tPos][str[p]-'A'];
	if (now == 0)
		now = ++lstPos;
	
	add (str, p+1, now);
}

void updKey () {
	for (int i = 0; i < n; i++)
		keyNow[i] = key[keyNow[i]-'A'];
}

void encrypty (string &str) {
	for (int i = 0; i < n; i++)
		conv[keyNow[i]-'A'] = 'A'+i;
	for (int i = 0; i < len (str); i++)
		str[i] = conv[str[i]-'A'];
}

bool verif (string str, int p = 0, int tPos = 0) {
	if (len (str) == p)
		return true;
	
	int &now = trie[tPos][str[p]-'A'];
	if (now == 0)
		return false;
	return verif (str, p+1, now);
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	
	string str;
	
	cin >> n >> m;
	cin >> key;
	for (int i = 0; i < n; i++)
		keyNow += (char)('A'+i);
	while (m--) {
		cin >> opt;
		if (opt == 1) {
			cin >> str;
			add (str);
		} else if (opt == 2)
			updKey();
		else {
			cin >> str;
			encrypty (str);
			cout << (verif (str) ? "YES" : "NO") << '\n';
		}
	}
	
	return 0;
}
