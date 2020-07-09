
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

const ld EPS = 1e-6;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

ld c = 3e8;

ld f (ld v) {
	return 700*(sqrt (((ld)c-v)/((ld)c+v)));
}

int vals[] = {
	400,
	425,
	445,
	500,
	575,
	585,
	620,
	750
};

string ans[] = {"invisivel",
"violeta",
"anil",
"azul",
"verde",
"amarelo",
"laranja",
"vermelho",
"invisivel"};

int main () {
	ld v;
	scanf ("%Lf", &v);
	ld val = f(v);
	for (int i = 0; i < 8; i++)
		if (vals[i] > val) {
			cout << ans[i] << '\n';
			break;
		}
	cout << "invisivel\n";

	return 0;
}
