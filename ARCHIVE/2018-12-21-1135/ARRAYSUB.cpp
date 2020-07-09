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

const int N = 1e6+10;

int n, k;
int a[N];
deque<int> deq;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	scanf ("%d", &k);
	
	for (int i = 0; i < k; i++) {
		if (deq.empty()) deq.push_back (a[i]);
		else {
			while (!deq.empty() and a[i] > deq.back())
				deq.pop_back ();
			deq.push_back (a[i]);
		}
	}
	
	printf ("%d", deq.front());
	for (int i = k; i < n; i++) {
		if (a[i-k] == deq.front()) {
			deq.pop_front();
		}
		while (!deq.empty() and a[i] > deq.back())
			deq.pop_back ();
		deq.push_back (a[i]);
		
		printf (" %d", deq.front());
	}
	putchar ('\n');
	

	return 0;
}
