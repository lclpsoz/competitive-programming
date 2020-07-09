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

vector<int> vec;


bool testStr (string &base, string &s, int sz) {
	bool test = true;
	for (int i = 0; test and i < len (s); i += sz)
		for (int j = 0; j < sz; j++)
			if (base[j] != s[i+j]) {
				test = false;
				break;
			}
			
	return test;
}

int main () {
	string s1, s2;
	cin >> s1 >> s2;
	int mn = min (len (s1), len (s2));
	for (int i = 1; i <= mn; i++)
		if (len (s1)%i == 0 and len (s2)%i == 0)
			vec.push_back (i);
		
	int ans = 0;
	for (int sz : vec) {
		string base = s1.substr (0, sz);
		if (!testStr (base, s1, sz) or !testStr (base, s2, sz))
			continue;
		++ans;
	}
	
	cout << ans << '\n';
	

	return 0;
}
