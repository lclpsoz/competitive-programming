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

const int N = 2e5+10;

int n;
char str[N];
pii target, en;

bool eval (int qnt) {
	pii now = en;
	int l = 0, r = qnt-1;
	for (int i = l; i <= r; i++) {
		if (str[i] == 'U') now.y--;
		else if (str[i] == 'D') now.y++;
		else if (str[i] == 'L') now.x++;
		else if (str[i] == 'R') now.x--;
	}
	int val = abs (now.x-target.x) + abs (now.y-target.y);
	if (val%2 != qnt%2) return false;
	while (r < n) {
		val = abs (now.x-target.x) + abs (now.y-target.y);
		if (val <= qnt)
			return true;
		++r;
		if (r < n) {
			if (str[r] == 'U') now.y--;
			else if (str[r] == 'D') now.y++;
			else if (str[r] == 'L') now.x++;
			else if (str[r] == 'R') now.x--;
			if (str[l] == 'U') now.y++;
			else if (str[l] == 'D') now.y--;
			else if (str[l] == 'L') now.x--;
			else if (str[l] == 'R') now.x++;
		}
		++l;
	}
	
	return false;
}

int main () {
	scanf ("%d %s", &n, str);
	scanf ("%d %d", &target.x, &target.y);
	int val = abs(target.x) + abs (target.y);
	if (val > n or val%2 != n%2) {
		printf ("-1\n");
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		if (str[i] == 'U') en.y++;
		else if (str[i] == 'D') en.y--;
		else if (str[i] == 'L') en.x--;
		else if (str[i] == 'R') en.x++;
	}

	if (en == target) {
		printf ("0\n");
		return 0;
	}		
	
	int l = 1, r = n;
	while (l < r) {
		int md = (l+r)/2;
		if (eval (md))
			r = md;
		else
			l = md+1;
	}
	
	printf ("%d\n", l);
	
	return 0;
}