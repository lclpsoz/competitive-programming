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

int q, h, n;
vector<int> vec;

int main () {
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d", &h, &n);
		while (n--) {
			int x;
			scanf ("%d", &x);
			vec.push_back (x);
		}
		int now = 0;
		int ans = 0;
		while (now < len (vec)-1) {
			// printf ("now = %d | %d %d\n", now, vec[now], vec[now+1]+1);
			if (vec[now] == vec[now+1]+1) {
				// if (now+2 < len(vec))
				// 	printf ("  vec[now+2] = %d\n", vec[now+2]);
				if (vec[now] >= 3 and (now+2 == len(vec) or vec[now+1] > vec[now+2]+1)) {
					++ans;
					++now;
					vec[now]--;
				} else
					now += 2;
			}
			else {
				vec[now] = vec[now+1] + 1;
			}
		}
		printf ("%d\n", ans);
		vec.clear();
	}

	return 0;
}
