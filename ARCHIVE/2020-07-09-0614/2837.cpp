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

const int N = 1e5 + 10;

int n, l, h;
int flags[N], pref[N];
deque<int> dq;
int st, md, en, qnt, mini;

bool nxt () {
	mini = pref[st];
	++st; // Remove one flag
	--qnt;
	while (st <= n and flags[st] == 0)
		mini = min (mini, pref[st++]);

	if (flags[md] == 1 and dq.front() == pref[md]) dq.pop_front();
	++md; // Move mid pointer, minimum number of flags
	while (md <= n and flags[md] == 0)
		if (dq.front() == pref[md++]) dq.pop_front();

	if (md > n) return false; // Can't obtain minimum number of flags
	while (qnt < h and en <= n) {
		qnt += flags[en];
		if (qnt >= l) {
			if (md == 0) md = en;
			if (dq.empty()) dq.push_back (pref[en]);
			else {
				while (!dq.empty() and dq.back() < pref[en]) dq.pop_back ();
				dq.push_back (pref[en]);
			}
		}
		++en;
	}
	return true;
}

int zero () {
	int ret = 0;
	int p = 1;
	while (p <= n) {
		while (flags[p] == 1) ++p;
		// printf ("startP = %d\n", p);
		int acu = 0;
		while (p <= n and flags[p] == 0) {
			// printf ("p: %d\n", p);
			acu = max (acu + pref[p], pref[p]);
			ret = max (ret, acu);
			++p;
		}
		// putchar ('\n');
	}

	return ret;
}

int main () {
	scanf ("%d %d %d", &n, &l, &h);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		pref[i] += pref[i-1] + x;
	}
	for (int i = 1; i <= n; i++)
		scanf ("%d", &flags[i]);

	int ans = - 2e9;
	if (l == 0)
		ans = zero ();
	if (h == 0) {
		printf ("%d\n", ans);
		exit (0);
	}

	mini = 1e9;
	st = 1;
	while (flags[st] == 0)
		mini = min (mini, pref[st++]);
	if (mini == 1e9) mini = pref[st-1];
	qnt = 0;
	en = st; // [st, en) <- Interval
	while (qnt < h and en <= n) {
		qnt += flags[en];
		if (qnt >= l) {
			if (md == 0) md = en;
			if (dq.empty()) dq.push_back (pref[en]);
			else {
				while (!dq.empty() and dq.back() < pref[en]) dq.pop_back ();
				dq.push_back (pref[en]);
			}
		}
		++en;
	}
	while (flags[en] == 0 and en <= n) {
		if (dq.empty()) dq.push_back (pref[en]);
		else {
			while (!dq.empty() and dq.back() < pref[en]) dq.pop_back ();
			dq.push_back (pref[en]);
		}
		en++;
	}
	// printf ("st = %d, md = %d, en = %d, qnt = %d, len (dq) = %d\n", st, md, en, qnt, len(dq));
	// putchar ('\n');
	ans = max (ans, dq.front() - mini);
	while (nxt ()) {
		// printf ("st = %d, md = %d, en = %d, qnt = %d, len (dq) = %d\n", st, md, en, qnt, len(dq));
		ans = max (ans, dq.front() - mini);
		// printf ("st = %d, md = %d, en = %d, qnt = %d, len (dq) = %d\n", st, md, en, qnt, len(dq));
		// putchar ('\n');
	}
	printf ("%d\n", ans);

	return 0;
}
