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

const int S = 10010;

char ax[S];
map<string, set<string>> mp;

string process (string &s) {
	int p = 0;
	for (int i = 0; i < len (s); i++)
		if (s[i] != ' ')
			ax[p++] = s[i];
		
	ax[p] = '\0';
	sort (ax, ax + p);
	
	return ax;
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	int t;
	cin >> t;
	cin.ignore ();
	cin.ignore ();
	
	string s;
	while (t--) {
// 		cout << "t: " << t << '\n';
		mp.clear();
		while (getline (cin, s)) {
			if (s == "") break;
			assert (len (s) < S);
			string aux = process (s);
//  			cout << aux << " vs " << s << '\n';
			mp[aux].insert (s);
		}
		
		vector<string> ans;
		for (auto &p : mp)
			if (len (p.y) > 1) {
				vector<string> v;
				for (auto &str : p.y)
					v.push_back (str);
				for (int i = 0; i < len (v); i++)
					for (int j = i+1; j < len (v); j++) {
						string now = v[i] + " = " + v[j] + '\n';
						ans.push_back (now);
					}
			}
		sort (ans.begin(), ans.end());
		for (string &ss : ans)
			cout << ss;
		if (t > 0) cout << '\n';
	}

	return 0;
}
