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

const int N = 1e5+10;
const ll MAXX = 10'000'000'000'000;
const ll MAXQ = 3162277;
bitset<> sq;
int n;
ll sum = 0;
ll a[N];

bool isSq (ll x) {
	int sq = (int)sqrt ((ld)x);
	if (sq*1LL*sq == x)
		return true;
	++sq;
	if (sq*1LL*sq == x)
		return true;
	return false;
}

void no () {
	printf ("No\n");
	exit (0);
}

int findSq (ll obj, ll val) {
	int l = 0, r = MAXQ;
	while (l < r) {
		int md = (l+r)/2;
		ll now = md*1LL*md;
		if (now >= obj)
			r = md;
		else
			l = md+1;
	}
	if (l*1LL*l < obj)
		no ();

	
	
	
	return l;
}

void solve (int p, ll acu = 0) {
	if (p == n) {
		printf ("Yes\n");
		for (int i = 0; i < n; i++)
			printf ("%d%c", a[i], " \n"[i==n-1]);
		exit (0);
	}
	int ax = findSq (acu+a[p+1], a[p+1]);
	for (ax; ax <= MAXQ; ax++) {
		a[p] = (ax*1LL*ax)-acu-a[p+1];
		solve (p+2, ax*1LL*ax);
	}
}

int main () {
	int n;
	for (int i = 1; i <= n; i+=2)
		scanf ("%lld", &a[i]);
	
	vector<int> vec;
	int sq = (int)sqrt ((ld) sum);
	for (int i = sq; i < sq+1e5; i++)
		vec.push_back (i*1LL*i);
	auto it = lower_bound (vec.begin(), vec.end(), sum);
	while (it != vec.end()

	return 0;
}
