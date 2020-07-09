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

const int N = 2e5 + 10;

int n;
int a[N];
int ans[N];
vector<pii> vec;
ll stAcu[4][N];
int lst[4];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		vec.push_back ({a[i], i});
	}
	sort (vec.begin(), vec.end());
	if (n%3 == 0)
		for (int i = 0; i < n; i++) {
			int pos = lower_bound (vec.begin(), vec.end(), make_pair (a[i], i)) - vec.begin();
			printf ("%d ", pos/3 + 1);
		}
	else {
		for (int st = 0; st < 3; st++)
			for (int i = st+2; i < n; i+=3) {
				stAcu[st][i] = vec[i].x - vec[i-2].x;
				if (i > 2)
					stAcu[st][i] += stAcu[st][i-3];
			}
		lst[0] = 3*(n/3) - 1;
		lst[1] = 3*(n/3);
		if (lst[1] >= n-1) lst[1]-=3;
		lst[2] = 3*(n/3) + 1;
		if (lst[2] >= n-1) lst[2]-=3;
		if (n%3 == 1) {
			// Find best 4
			ll best = 1e18;
			int now = 0;
			int nxt = 1;
			for (int i = 0; i < n-3; i++) {
				printf ("i = %d\n", i);
				ll nowVal = 0;
				if (i)
					nowVal += stAcu[now][i-1];
				nowVal += ((stAcu[nxt][lst[nxt]] - stAcu[nxt][i+4-3]) + 
					vec[i+3].x - vec[i].x);
				if (nowVal < best) {
					best = nowVal;
				}
				++now;
				++nxt;
				if (now == 3) now = 0;
				if (nxt == 3) nxt = 0;
			}
			printf ("%lld\n", best);
		} else {

		}	
	}

	return 0;
}
