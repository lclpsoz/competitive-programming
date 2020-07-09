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

string str, opt, ans;
vector<string> vec;
set<string> st;

int main () {
	cin >> str;
	while (str != "FIM") {
		cin >> opt;
		if (opt == "YES")
			st.insert (str);
		else
			vec.push_back (str);
		if (opt == "YES" and str.size() > ans.size())
			ans = str;
		cin >> str;
	}
	sort (vec.begin(), vec.end());
	
	for (string s : st)
		cout << s << '\n';
	for (string s : vec)
		cout << s << '\n';
	cout << "\nAmigo do Habay:\n";
	cout << ans << '\n';
	
	return 0;
}