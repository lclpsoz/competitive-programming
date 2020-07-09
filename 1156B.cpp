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

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		sort (s.begin(), s.end(), [&] (char a, char b) {
			if (a%2 != b%2)
				return a%2 == 1;
			return a < b;
		});
		int p = 0;
		while (p < len(s) and s[p]%2 == 1) ++p;
		if (p == len (s) or p == 0)
			cout << s << '\n';
		else {
			int s1 = p;
			int s2 = len (s) - s1;
			bool ok = false;
			for (int i = 0; !ok and i < s1; i++) {
				for (int j = 0; !ok and j < s2; j++) {
					if (abs (s[p] - s[p-1]) != 1) {
						ok = true;
						break;
					}
					rotate (s.begin()+s1, s.begin()+s1+1, s.end());
				}
				if (!ok)
					rotate (s.begin(), s.begin()+1, s.begin()+s1);
			}
			if (ok)
				cout << s << '\n';
			else
				cout << "No answer\n";
		}
	}

	return 0;
}
