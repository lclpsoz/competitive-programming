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

int q;
ll a, b;
vector<ll> vec;
char arr[20];

void func (int n, int p) {
	if (p == 0)
		for (int i = '1'; i <= '9'; i++) {
			arr[p] = arr[n-p-1] = i;
			if (n <= 2)
				vec.push_back (atoll (arr));
			else
				func (n, p+1);
		}
	else if (p == (n-1)/2) {
		for (int i = '0'; i <= '9'; i++) {
			arr[p] = arr[n-p-1] = i;
			vec.push_back (atoll (arr));
		}
	} else
		for (int i = '0'; i <= '9'; i++) {
			arr[p] = arr[n-p-1] = i;
			func (n, p+1);
		}
}

bool verif (ll x) {
	string str = to_string (x);
	string aux = str;
	reverse (aux.begin(), aux.end());
	ll y = stoll (aux);
	return x == y;
}

int main () {
	for (int qnt = 1; qnt <= 10; qnt++)
		func (qnt, 0);
	
	sort (vec.begin(), vec.end());
	
	
	scanf ("%d", &q);
	assert (q <= 100'000);
	while (q--) {
		scanf ("%lld %lld", &a, &b);
		assert (a >= 1 and b <= 10'000'000'000ll and a <= b);
		vector<ll>::iterator itL = lower_bound (vec.begin(), vec.end(), a);
		vector<ll>::iterator itR = upper_bound (vec.begin(), vec.end(), b);
		if (itL == itR)
			printf ("0 -1 -1\n");
		else {
			int qnt = itR-itL;
			--itR;
			printf ("%d %lld %lld\n", qnt, *itL, *itR);
		}
	}

	return 0;
}