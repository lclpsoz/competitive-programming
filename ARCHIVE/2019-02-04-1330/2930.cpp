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

ll e, d;

int main () {
	cin >> e >> d;
	if (e > d)
		printf ("Eu odeio a professora!\n");
	else if (d-e >= 3)
		printf ("Muito bem! Apresenta antes do Natal!\n");
	else {
		printf ("Parece o trabalho do meu filho!\n");
		e+=2;
		if (e < 24)
			printf ("TCC Apresentado!\n");
		else
			printf ("Fail! Entao eh nataaaaal!\n");
	}

	return 0;
}
