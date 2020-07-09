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
int qnt[N], a[N], b[N];
int pos[N];

int simu () {
	deque<int> dq;
	for (int i = 0; i < n; i++) dq.push_back (b[i]);
	int pos1 = -1;
	for (int i = n-1; i >= 0; i--)
		if (b[i] == 1) {
			pos1 = i;
			break;
		}
	if (pos1 == -1) return -1;
	for (int i = pos1+1; i < n; i++)
		if (b[i] != b[i-1] + 1) return -1;
	int ret = 0;
	while (dq.front() != 1) {
		if (qnt[dq.back()+1] == 0) return -1;
		else {
			++ret;
			qnt[dq.front()]++;
			dq.pop_front();
			dq.push_back (dq.back()+1);
		}
	}

	return ret;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		qnt[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		scanf ("%d", &b[i]);
		pos[b[i]] = i+1-(b[i]-1);
	}
	int val = simu ();
	if (val != -1)
		printf ("%d\n", val);
	else {
		int mx = -1;
		for (int i = 1; i <= n; i++) mx = max (mx, pos[i]);
		// printf ("mx = %d\n", mx);
		printf ("%d\n", n + mx);
	}

	return 0;
}
