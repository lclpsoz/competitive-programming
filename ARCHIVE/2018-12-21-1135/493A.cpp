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

using ppp = pair<int, pair<string, int>>;

int n;
string h, a;
map<string, map<int, int>> mp;
map<string, map<int, int>> ans;

int main () {
	cin.tie (0); cout.tie (0);
	ios::sync_with_stdio (false);
	cin >> h >> a;
	cin >> n;
	while (n--) {
		int t, pl;
		string team, card;
		cin >> t >> team >> pl >> card;
		int &now = mp[team][pl];
		if (card == "r")
			now+=2;
		else
			now++;
		if (now >= 2 and ans[team].count (pl) == 0)
			ans[team][pl] = t;
	}
	
	vector<ppp> vec;
	for (auto p : ans)
		for (auto pp : p.y)
			vec.push_back ({pp.y, {p.x, pp.x}});
	sort (vec.begin(), vec.end());
	for (auto p : vec)
		cout << (p.y.x == "h" ? h : a) << ' ' << p.y.y << ' ' << p.x << '\n';

	return 0;
}