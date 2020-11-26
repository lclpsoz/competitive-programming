#include "stdio.h"
#include "vector"
#include "algorithm"
#include "string.h"
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

const int N = 1e5+2, M = 302;

int n, m;
vector<int> sweep[N];
int arr[N];
bool segs[M];

// Get max
int getVal () {
	int qntNow = 0;
	int val = - 1e9;
	
	for (int i = 1; i <= n; i++) {
		for (int v : sweep[i])
			if (segs[abs(v)]) (v > 0) ? --qntNow : ++qntNow;
		
		val = max (val, arr[i] + qntNow);
// 		printf ("  ||%d: %d\n", i, val);
	}
// 	for (int i = 1; i <= m; i++)
// 		printf ("%d ", segs[i]);
// 	printf (" val: %d\n", val);
	
	return val;
}

// Get min
pii solve () {
	int qntNow = 0;
	pii ret = {- 1e9, -1};
	int val = 1e9;
	
	int lst = 1;
	for (int i = 1; i <= n; i++) {
		if (len (sweep[i])) { // Process before
			if (i > 1) {
				int now = abs (getVal () - val);
				if (now > ret.x)
					ret = {now, lst};
			}
			val = 1e9;
			for (int v : sweep[i]) {
				segs[abs (v)] = !segs[abs (v)];
				qntNow += (v > 0 ? 1 : -1);
			}
		}
		
		if (arr[i] - qntNow < val) {
			lst = i;
			val = arr[i] - qntNow;
		}
// 		printf ("%d: %d\n", i, val);
	}
	int now = abs (getVal () - val);
	if (now > ret.x)
		ret = {now, lst};
	
	return ret;
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &arr[i]);
	
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf ("%d %d", &l, &r);
		sweep[l].push_back (i);
		sweep[r+1].push_back (-i);
	}
	
	vector<int> vec;
	pii ans = solve ();
	printf ("%d\n", ans.x);
	memset (segs, false, sizeof segs);
	for (int i = 1; i <= ans.y; i++)
		for (int v : sweep[i])
			segs[abs (v)] = !segs[abs (v)];
	for (int i = 1; i <= m; i++)
		if (segs[i]) vec.push_back (i);
	printf ("%d\n", len (vec));
	for (int i = 0; i < len (vec); i++)
		printf ("%d%c", vec[i], " \n"[i==len(vec)-1]);
		
	return 0;
}
