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

int n, a[1000000], b[100];

int main () {
 	scanf ("%d", &n);
	vector<int> vec, perm;
	for (int i = 1; i <= n; i++)
		vec.push_back (i);
	do {
		for (int v : vec) {
			perm.push_back (v);
 			printf ("%d", v);
		}
 		printf (";");
 		if (vec[0] == 2)
 			putchar ('\n');
	} while (next_permutation (vec.begin(), vec.end()));
//   	for (int v : perm)
//   		printf ("%d ", v);
//   	putchar ('\n');
	int l = 0, r = n-1;
	
	int ans = 0;
	int sum = 0, target = (n*(n+1))/2;
	for (int i = 0; i <= r; i++) sum += perm[i];
	putchar ('\n');
	while (r < len (perm)) {
		if (sum == target) {
			++ans;
			if (l < 120) {
 				if (l%5 == 0)
 					putchar ('\n');
 				printf ("%d %d\n", l, ans);
				a[l/5]++;
			}
		}
		if (r < len (perm)) {
			sum += perm[++r];
			sum -= perm[l++];
		}
	}
	for (int i = 0; i < 24; i++) {
		printf("%d: %d\n", i, a[i]);
		b[a[i]]++;
	}
	for (int i = 0; i < 6; i++)
		printf ("%d: %d\n", i, b[i]);
	printf ("%d\n", ans);
	
	return 0;
}
