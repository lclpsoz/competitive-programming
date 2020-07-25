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

int main () {
	int n;
	scanf("%d", &n);
	vector<int> vec;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int q = 0;
		int ax = 1;
		while(x) {
			if(x%10) {
				vec.push_back(ax*(x%10));
			}
			ax *= 10;
			x /= 10;
		}
		printf("%d\n", len(vec));
		for(int i = 0; i < len(vec); i++)
			printf("%d%c", vec[i], " \n"[i==len(vec)-1]);
		vec.clear();
	}

	return 0;
}
