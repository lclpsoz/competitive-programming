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

int n, m, p;
int x, y;
vector<pii> vec;

int main () {
	while (scanf ("%d %d %d", &n, &m, &p) != EOF) {
		vec.clear();
		for (int i = 0; i < p; i++) {
			scanf ("%d %d", &x, &y);
			vec.push_back ({x, y});
		}
		bool ok = true;
		for (int i = 0; i < p and ok; i++)
			for (int j = i+1; j < p and ok; j++) {
				if (vec[i].x != vec[j].x and vec[i].y != vec[j].y) {
					ok = false;
					pii x = {min (vec[i].x, vec[j].x), min (vec[i].y, vec[j].y)};
					pii y = {max (vec[i].x, vec[j].x), max (vec[i].y, vec[j].y)};
					for (int k = 0; k < p; k++) {
						pii now = vec[k];
						if (k != i and k != j and now.x >= x.x and now.x <= y.x and now.y >= x.y and now.y <= y.y) {
							ok = true;
							break;
						}
					}
				}
			}
		printf ("%s\n", ok ? "Y" : "N");
	}


	return 0;
}
