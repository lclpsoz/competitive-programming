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
deque<int> dq;
int lst;
vector<char> ans;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		dq.push_back (x);
	}
	
	lst = -1;
	while (!dq.empty() and (dq.front() > lst or dq.back() > lst)) {
		if (dq.front() < dq.back() and dq.front() > lst) {
			lst = dq.front();
			dq.pop_front();
			ans.push_back ('L');
		} else if (dq.back() > lst) {
			lst = dq.back();
			dq.pop_back();
			ans.push_back ('R');
		} else {
			lst = dq.front();
			dq.pop_front();
			ans.push_back ('L');
		}
	}
	printf ("%d\n", len (ans));
	for (char d : ans)
		putchar (d);
	putchar ('\n');

	return 0;
}
