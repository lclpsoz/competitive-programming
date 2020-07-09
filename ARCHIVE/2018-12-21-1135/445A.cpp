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

int n, m;

vector<string> vec;

int main () {
	cin >> n >> m;
	while (n--) {
		string str;
		cin >> str;
		vec.push_back (str);
	}
	bool start = true;
	for (int i = 0; i < len (vec); i++) {
		bool now = start;
		for (int j = 0; j < len (vec[i]); j++) {
			now = !now;
			if (vec[i][j] == '.')
				vec[i][j] = (now ? 'B' : 'W');
		}
		cout << vec[i] << '\n';
		start = !start;
	}

	return 0;
}
