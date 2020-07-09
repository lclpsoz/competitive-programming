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
vector<ll> vec;

int main () {
	vec.push_back (4444477777ll);
	string strs[] = {"47", "4477", "444777", "44447777"};
	for (string s : strs)
		do {
			vec.push_back (stoi (s));
		} while (next_permutation (s.begin(), s.end()));
	
	sort (vec.begin(), vec.end());
	
	scanf ("%d", &n);
	printf ("%lld\n", *lower_bound (vec.begin(), vec.end(), (ll)n));

	return 0;
}
