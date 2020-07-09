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

int n;
string s;
char conv[11];

int main () {
	cin >> n >> s;
	for (int i = 1; i <= 9; i++)
		scanf (" %c", &conv[i]);
	
	for (int i = 0; i < len (s); i++)
		if (s[i] < conv[s[i]-'0']) {
			for (int j = i; j < len (s); j++)
				if (s[j] <= conv[s[j]-'0'])
					s[j] = conv[s[j]-'0'];
				else
					break;
			break;
		}
		
	cout << s << '\n';
	
	return 0;
}
