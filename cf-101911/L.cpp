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

const int N = 1e5 + 10;

int n, m;
int tr;
int a1, a2, b1, b2;

vector<int> lgt, rgt;
map<int, int> up, down;
map<int, int> ax1, ax2;

int main () {
	scanf("%d %d", &n, &tr);
	int po2 = 536870912*2;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		up[x%po2]++;
	}
	scanf("%d %d", &m, &tr);
	for(int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		down[x%po2]++;
	}
	int ans = 2;

	while(po2 >= 2) {
		for(pii p : up) {
			int val = p.x;
			int qnt = p.y;
			int ax = (val+po2/2)%po2;
			// if(p.x == 0) ax = 0;
			if(down.count(ax)) qnt += down[ax];
			ans = max(ans, qnt);
		}
		for(pii p : down) {
			int val = p.x;
			int qnt = p.y;
			int ax = (val+po2/2)%po2;
			// if(p.x == 0) ax = 0;
			if(up.count(ax)) qnt += up[ax];
			ans = max(ans, qnt);
		}
		po2/=2;
		for(pair<int, int> p : up)
			ax1[p.x%po2] += p.y;
		for(pair<int, int> p : down)
			ax2[p.x%po2] += p.y;
		up = ax1;
		down = ax2;
		ax1.clear();
		ax2.clear();
	}

	printf("%d\n", ans);

	return 0;
}
