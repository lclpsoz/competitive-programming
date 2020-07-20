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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

ld dist(pii a, pii b) {
	a.x -= b.x;
	a.y -= b.y;
	return sqrt(a.x*a.x + a.y*a.y);
}

int main () {
	int n;
	scanf("%d", &n);
	while(n--) {
		vector<pii> vec;
		for(int i = 0; i < 3; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			vec.push_back({x, y});
		}
		ld a = dist(vec[0], vec[1]);
		ld b = dist(vec[1], vec[2]);
		ld c = dist(vec[2], vec[0]);
		// printf("%Lf %Lf %Lf\n", a, b, c);
		ld s = (a+b+c)/2;
		printf("%.3Lf\n", sqrt(s*(s-a)*(s-b)*(s-c)));
	}

	return 0;
}
