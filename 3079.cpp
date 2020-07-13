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

int n, m;

int main () {
	scanf("%d %d", &n, &m);
	vector<pii> vec;
	vec.push_back({0, -1});
	int x;
	scanf("%d", &x);
	for(int i = 1; i < n; i++) {
		scanf("%d", &x);
		vec.back().y = x-1;
		vec.push_back({x, -1});
	}
	vec.back().y = m;
	for(int i = vec[1].y; i; i--) {
		printf("k = %d\n", i);
		for(int st = 0; st+i <= vec[1].y; st++) {
			printf("  st = %d\n", st);
			bool ok = true;
			for(int j = 1; ok and j < n; j++) {
				vec[j].x -= st;
				vec[j].y -= st;
				// printf("    [%d, %d]\n", vec[j].x, vec[j].y);
				if(vec[j].x%i and ((vec[j].x/i + 1)*i) > vec[j].y)
					ok = false;
				vec[j].x += st;
				vec[j].y += st;
			}
			if(ok) {
				printf("%d\n", i);
				exit(0);
			}
		}
	}

	return 0;
}
