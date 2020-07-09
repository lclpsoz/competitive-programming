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

string s;
map<string, vector<string>> mp;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		mp.clear();
		while (n--) {
			cin >> s;
			string ax = s;
			sort (ax.begin(), ax.end());
			vector<string> &v = mp[ax];
			v.push_back (s);
		}
		
		while (cin >> s, s != "END") {
			cout << "Anagrams for: " << s << '\n';
			string ax = s;
			sort (ax.begin(), ax.end());
			
			if (mp.count (ax) == 0)
				cout << "No anagrams for: " << s << '\n';
			else {
				vector<string> &v = mp[ax];
				for (int i = 1; i <= len (v); i++) {
					if (i < 10)
						cout << ' ';
					if (i < 100)
						cout << ' ';
					cout << i << ") " << v[i-1] << '\n';
				}
			}
		}
		
		if (t) cout << '\n';
	}

	return 0;
}
