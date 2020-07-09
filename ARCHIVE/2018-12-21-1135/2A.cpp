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

int n, pt;
int mx;
string str;
vector<pair<string, int>> inp;
map<int, string> ans;
map<string, int> acu;
map<string, vector<int>> scoreboard;

int main () {
	cin >> n;
	while (n--) {
		cin >> str >> pt;
		acu[str] = 0;
		inp.push_back ({str, pt});
	}
	
	for (auto p : inp) {
		acu[p.x] += p.y;
		for (auto pont : acu)
			scoreboard[pont.x].push_back (pont.y);
	}
	
	for (auto p : acu)
		mx = max (mx, p.y);
	
	for (auto p : inp)
		if (scoreboard.count (p.x) and scoreboard[p.x].back() < mx)
			scoreboard.erase (p.x);

	int pos = 1e9;
	for (auto &p : scoreboard)
		for (int i = 0; i < len (p.y); i++)
			if (p.y[i] >= mx and i < pos) {
				pos = i;
				str = p.x;
			}
	cout << str << '\n';

	return 0;
}
