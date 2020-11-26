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

const int N = 302;

int n, m;
int arr[N], aux[N];
vector<pii> segs;

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &arr[i]);
	while (m--) {
		int l, r;
		scanf ("%d %d", &l, &r);
		segs.push_back ({l, r});
	}
	
	int ans = - 1e9;
	int bst = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			aux[j] = arr[j];
		
		int now = arr[i];
		for (pii p : segs)
			if (p.y < i or p.x > i)
				for (int j = p.x; j <= p.y; j++)
					aux[j]--;
		int mini = 1e9;
		for (int j = 1; j <= n; j++)
			mini = min (mini, aux[j]);
		now -= mini;
		if (now > ans) {
			ans = now;
			bst = i;
		}
	}
	
	printf ("%d\n", ans);
	vector<int> vec;
	for (int i = 0; i < len (segs); i++)
		if (segs[i].y < bst or segs[i].x > bst)
			vec.push_back (i+1);
	printf ("%d\n", len (vec));
	for (int i = 0; i < len (vec); i++)
		printf ("%d%c", vec[i], " \n"[i==len (vec)-1]);
		

	return 0;
}
