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
string str1, str2;
map<string, string> mp;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	
	while (cin >> n, n) {
		mp.clear();
		while (n--) {
			cin >> str1 >> str2;
			mp[str1] = str2;
		}
		int ans = 0;
		cin >> n;
		while (n--) {
			cin >> str1 >> str2;
			string check = mp[str1];
			if (len (check) != len (str2)) {
				++ans;
			} else {
				int qnt = 0;
				for (int i = 0; i < len (str2); i++)
					if (check[i] != str2[i]) {
						if (tolower (check[i]) == tolower (str2[i]))
							++qnt;
						else
							qnt = 1000;
					}
				if (qnt > 1)
					++ans;
			}
// 			cout << ans << "<-\n";
		}
		cout << ans << '\n';
	}

	return 0;
}
