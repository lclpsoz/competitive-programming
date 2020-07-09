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
int t;
string s;

bool isPal (string ax) {
	for (int i = 0, j = len (ax) - 1; i < j; i++, j--)
		if (ax[i] != ax[j]) return false;
	return true;
}

bool isPal (int now) {
	if (now == 0) return true;
	int mn = now%60;
	int hr = now/60;
	if (hr == 0)
		return isPal (to_string (mn));
	else {
		string ax = to_string (hr);
		if (mn < 10)
			ax += '0';
		ax += to_string (mn);
		return isPal (ax);
	}
}

int main () {
	cin.tie (NULL);
	ios::sync_with_stdio (false);
	
	for (int i = 0; i < 1440; i++)
		if (isPal (i))
			vec.push_back (i);
	
	cin >> t;
	while (t--) {
		cin >> s;
		int h = (s[0] - '0')*10 + (s[1] - '0');
		int mn = (s[3] - '0')*10 + (s[4] - '0');
		
		int now = h*60 + mn;
		auto it = lower_bound (vec.begin(), vec.end(), now+1);
		if (it == vec.end())
			printf ("00:00\n");
		else
			printf ("%02d:%02d\n", *it/60, *it % 60);
	}

	return 0;
}
