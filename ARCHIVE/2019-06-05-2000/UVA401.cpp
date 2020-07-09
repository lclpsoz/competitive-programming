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

char conv[1000];
char ori[] = "AEHIJLMOSTUVWXYZ12358";
char now[] = "A3HILJMO2TUVWXY51SEZ8";

bool isPal (string &s) {
	int i = 0, j = len (s) - 1;
	for (; i < len (s) and i < j; i++, j--)
		if (s[i] != s[j]) return false;
	return true;
}

bool isMir (string &s) {
	int i = 0, j = len (s) - 1;
	for (; i < len (s) and i <= j; i++, j--)
		if (s[i] != conv[s[j]]) return false;
	return true;
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	for (int i = 0; i < 256; i++)
		conv[i] = '\0';
	for (int i = 0; ori[i] != '\0'; i++)
		conv[ori[i]] = now[i];
	
	string str;
	while (cin >> str) {
		bool pal = isPal (str);
		bool mir = isMir (str);
		cout << str << " -- is ";
		if (pal and mir)
			cout << "a mirrored palindrome.\n";
		else if (!pal and !mir)
			cout << "not a palindrome.\n";
		else if (pal)
			cout << "a regular palindrome.\n";
		else if (mir)
			cout << "a mirrored string.\n";
		cout << '\n';
	}

	return 0;
}
