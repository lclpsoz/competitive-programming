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

int n;
queue<int> q;
bool vis[N];
int ans[N];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		q.push (x);
	}
	
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		while (!vis[x] and !q.empty() and q.front() != x) {
			++ans[i];
			vis[q.front()] = true;
			q.pop();
		}
		if (!vis[x]) {
			vis[x] = true;
			ans[i]++;
			q.pop();
		}
	}
	for (int i = 0; i < n; i++) {
		if (i) putchar (' ');
		printf ("%d", ans[i]);
	}
	putchar ('\n');
		
	
	return 0;
}
