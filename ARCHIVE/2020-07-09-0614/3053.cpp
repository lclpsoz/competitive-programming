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

int n;
char st;
bool en[] = {false, false, false};

int main () {
	scanf("%d %c ", &n, &st);
	st -= 'A';
	en[st] = true;
	while(n--) {
		int now;
		scanf("%d", &now);
		if(now == 1) swap(en[0], en[1]);
		else if(now == 2) swap(en[1], en[2]);
		else swap(en[0], en[2]);
	}
	if(en[0]) st = 'A';
	else if(en[1]) st = 'B';
	else st = 'C';
	putchar(st);
	putchar('\n');

	return 0;
}
