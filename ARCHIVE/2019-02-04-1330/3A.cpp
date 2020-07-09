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

string s1, s2;
vector<string> ans;

int main () {
	cin >> s1 >> s2;
	while (s1 != s2) {
		string mv = "";
		if (s1[0] > s2[0]) {
			mv += "L";
			s1[0]--;
		} else if (s1[0] < s2[0]) {
			mv += "R";
			s1[0]++;
		}
		if (s1[1] > s2[1]) {
			mv += "D";
			s1[1]--;
		}
		else if (s1[1] < s2[1]) {
			mv += "U";
			s1[1]++;
		}
		ans.push_back (mv);
	}
	cout << len (ans) << '\n';
	for (string s : ans)
		cout << s << '\n';

	return 0;
}
