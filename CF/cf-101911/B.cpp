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

int n, h;


int main () {
	scanf("%d %d", &n, &h);
	vector<pii> vec;
	vector<pii> acu;
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		vec.push_back({x, y});
	}
	reverse(vec.begin(), vec.end());
	int ans = h;
	int now = 0;
	int minH = 1;
	int st = vec[0].y+1;
	for(int i = 0; i < n-1; i++) {
		minH += vec[i].x - vec[i+1].y;
		acu.push_back({vec[i+1].y+1, minH-1});
		// printf("  [%2d, %2d] st = %2d, minH = %2d, i = %2d\n", vec[i].x, vec[i].y, st, minH, i);
		while(minH > h) {
			minH -= vec[i].x - vec[i+1].y;
			ans = max(ans, st - (vec[i].x-(h-minH)));
			minH += vec[i].x - vec[i+1].y;
			st = acu.back().x;
			minH -= acu.back().y;
			acu.pop_back();
			// minH = 1 + vec[i].x - vec[i+1].y;
		}
		// printf("    ans = %d\n", ans);
	}
	// printf("  [%2d, %2d] st = %2d, minH = %2d, i = %2d\n", vec[n-1].x, vec[n-1].y, st, minH, n-1);
	ans = max(ans, st - (vec[n-1].x-(h-minH)));
	printf("%d\n", ans);

	return 0;
}
