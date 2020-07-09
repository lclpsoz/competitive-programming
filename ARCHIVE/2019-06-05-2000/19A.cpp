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
map<string, int> score, diff, goals;
vector<pair<pair<int, int>, pair<int, string>>> vec;

int main () {
// 	cin.tie (0);
// 	ios::sync_with_stdio (false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
	}
	
	for (int i = 0; i+i < (n*(n-1)); i++) {
		string teams, res;
		cin >> teams >> res;
		string l, r;
		int x, y;
		int j = 0;
		for (; teams[j] != '-'; j++);
		l = teams.substr (0, j);
		++j;
		r = teams.substr (j, len (teams) - j);
		
		j = 0;
		for (; res[j] != ':'; j++);
		x = stoi (res.substr (0, j));
		++j;
		y = stoi (res.substr (j, len (res) - j));
		
		if (x == y)
			score[l]++, score[r]++;
		else if (x > y)
			score[l]+=3;
		else
			score[r]+=3;
		diff[l] += x-y;
		diff[r] += y-x;
		goals[l] += x;
		goals[r] += y;
//  		cout << l << " vs " << r << '\n';
//  		cout << x << ' ' << y << '\n';
	}
	for (auto p : score) {
		string s = p.x;
// 		cout << s << ": " << -p.y << ' ' << -diff[s] << " " << -goals[s] << '\n';
		vec.push_back ({{-p.y, -diff[s]}, {-goals[s], s}});
// 		cout << p.x << ' ' << p.y << '\n';
	}
	sort (vec.begin(), vec.end());
	vector<string> ans;
	for (int i = 0; i < n/2; i++)
		ans.push_back (vec[i].y.y);
	sort (ans.begin(), ans.end());
	for (auto s : ans)
		cout << s << '\n';
	
	return 0;
}
