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
vector<int> vec1;

bool solve (int qnt) {
	vector<int> vec = vec1;
	queue<int> q; 
	for (int i = 0; i < qnt; i++) {
		if (vec.back())
			q.push (vec.back());
		vec.pop_back ();
	}
	
	while (!q.empty() and !vec.empty()) {
		int old = q.front();
		int now = vec.back(); vec.pop_back ();
		now = min (now, old-1);
		if (now > 0)
			q.push (now);
		q.pop();
	}
	
	return vec.empty();
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vec1.push_back (x);
	}
	sort (vec1.begin(), vec1.end());
	for (int i = 1; i <= n; i++)
		if (solve (i)) {
			printf ("%d\n", i);
			return 0;
		}

	return 0;
}
