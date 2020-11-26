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
int queries = 60;

int mdc (int a, int b) {
	if (a == 0) return b;
	return mdc (b%a, a);
}

int fMaxi () {
	int l = 0, r = 1'000'000'000;
	while (l < r) {
		int md = (l+r)/2;
		cout << "> " << md << '\n';
		cout.flush();
		queries--;
		int ans;
		cin >> ans;
		if (ans == 1) // Is larger than md
			l = md+1;
		else // Is equal or smaller than md
			r = md;
	}
	
	return r;
}

int main () {
	mt19937 rng((llu)chrono::steady_clock::now().time_since_epoch().count());
	cin >> n;
	int maxi = fMaxi();
	int d = -1;
	int st;
	
	vector<int> vec;
	for (int i = 1; i <= n; i++)
		vec.push_back (i);
	
	shuffle (vec.begin(), vec.end(), rng);
	
	cout << "? " << vec[0] << '\n';
	cout.flush();
	cin >> st;
	queries--;
	for (int i = 1; i < min (n, queries+1); i++) {
		cout << "? " << vec[i] << '\n';
		cout.flush();
		int now;
		cin >> now;
		if (d == -1)
			d = abs(st-now);
		else
			d = mdc (d, abs(st-now));
	}
	cout << "! " << maxi - (d*(n-1)) << ' ' << d << '\n';
	cout.flush();
	
	return 0;
}
