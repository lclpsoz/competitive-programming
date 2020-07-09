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

const int N = 2e5+100;

vector<int> vec;
int pref[N];
deque<pii> deq;

int main () {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back (x);
	}
	for (int i = 0; i < n; i++)
		vec.push_back (vec[i]);
	
	pref[0] = vec[0];
	for (int i = 1; i < 2*n; i++)
		pref[i] = vec[i] + pref[i-1];
	
	int ans = 0;
	for (int i = 0; i < len (vec); i++) {
		while (!deq.empty() and (i-deq.front().y) > n) deq.pop_front();
		while (!deq.empty() and deq.back().x > pref[i]) deq.pop_back();
		deq.push_back ({pref[i], i});
		ans = max (ans, pref[i]-deq.front().x);
	}
	printf ("%d\n", ans);
		

	return 0;
}
