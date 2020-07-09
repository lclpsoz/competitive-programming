#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
    return (int)(((x%m) + m) % m);
}



// ------------------------------------------------------------

const int N = 1e5+10;

string base = "aeiou";
string str;
int vogals[N];

inline bool isVogal (char c) {
	for (char v : base)
		if (c == v)
			return true;
	return false;
}

int qryVogals (int l, int r) {
	return vogals[r] - vogals[max (0, l-1)];
}

int solve (int l, int r, bool inv) {
	if (l == r)
		return 1;
	if (!inv) {
		// c..v
		if (!isVogal (str[l]) and isVogal (str[r]))
			return 0;
		// c..c
		else if (!isVogal (str[l]) and !isVogal (str[r]))
			return qryVogals (l, r) == 0;
		// v..c
		else if (isVogal (str[l]) and !isVogal (str[r]))
			return solve (l+1, r, !inv) + solve (l, r-1, inv);
		// v..v
		else if (isVogal (str[l]) and isVogal (str[r]))
			return solve (l+1, r, !inv);
	} else {
		// c..v
		if (!isVogal (str[r]) and isVogal (str[l]))
			return 0;
		// c..c
		else if (!isVogal (str[r]) and !isVogal (str[l]))
			return qryVogals (l, r) == 0;
		// v..c
		else if (isVogal (str[r]) and !isVogal (str[l]))
			return solve (l, r-1, !inv) + solve (l+1, r, inv);
		// v..v
		else if (isVogal (str[r]) and isVogal (str[l]))
			return solve (l, r-1, !inv);
	}
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	while (cin >> str) {
		vogals[0] = isVogal (str[0]);
		for (int i = 1; i < len (str); i++)
			vogals[i] = vogals[i-1] + isVogal (str[i]);
		printf ("%d\n", solve (0, len (str)-1, false));
	}
    
    return 0;
}
