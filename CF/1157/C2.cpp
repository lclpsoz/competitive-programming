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
deque<int> dq;
int lst;
vector<char> ans;
int esq[N], dir[N];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		dq.push_back (x);
	}
	
	esq[n-1] = 0;
	for (int i = n-2; i >= 0; i--) {
		if (dq[i] < dq[i+1])
			esq[i] = esq[i+1] + 1;
		else
			esq[i] = 0;
	}
	dir[0] = 0;
	for (int i = 1; i < n; i++)
		if (dq[i] < dq[i-1])
			dir[i] = dir[i-1] + 1;
		else
			dir[i] = 0;
	
	int l = 0, r = n-1;
	lst = -1;
	while (!dq.empty() and (dq.front() > lst or dq.back() > lst)) {
		if (dq.front() == dq.back()) {
			if (esq[l] > dir[r]) {
				l++;
				lst = dq.front();
				dq.pop_front();
				ans.push_back ('L');
			} else {
				r--;
				lst = dq.back();
				dq.pop_back();
				ans.push_back ('R');
			}
		} else if (dq.front() < dq.back() and dq.front() > lst) {
			l++;
			lst = dq.front();
			dq.pop_front();
			ans.push_back ('L');
		} else if (dq.back() > lst) {
			r--;
			lst = dq.back();
			dq.pop_back();
			ans.push_back ('R');
		} else {
			l++;
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
