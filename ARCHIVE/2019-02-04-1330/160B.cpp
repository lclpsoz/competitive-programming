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

string str;
vector<int> v1, v2;

int main () {
	int n; cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++)
		v1.push_back (str[i]-'0');
	for (int i = n; i < 2*n; i++)
		v2.push_back (str[i]-'0');
	sort (v1.begin(), v1.end());
	sort (v2.begin(), v2.end());
	bool t1 = true, t2 = true;
	for (int i = 0; i < n; i++)
		if (v1[i] > v2[i])
			t2 = false;
		else if (v1[i] < v2[i])
			t1 = false;
		else
			t1 = t2 = false;
	printf ("%s\n", (t1 or t2) ? "YES" : "NO");
	
	return 0;
}
