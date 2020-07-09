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

int n, m;
int weight[505];
bool check[505];
vector<int> vec, acu;
stack<int> st;

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &weight[i]);
	for (int i = 1; i <= m; i++) {
		int x;
		scanf ("%d", &x);
		if (!check[x]) {
			check[x] = true;
			acu.push_back (x);
		}
		vec.push_back (x);
	}
	
	while (!acu.empty()) {
		st.push (acu.back());
		acu.pop_back ();
	}
	
	ll ans = 0;
	for (int x : vec) {
		while (st.top() != x) {
			ans += weight[st.top()];
			acu.push_back (st.top());
			st.pop();
		}
		st.pop(); // x
	
		while (!acu.empty()) {
			st.push (acu.back());
			acu.pop_back ();
		}
		st.push (x);
	}
	printf ("%lld\n", ans);
	
	return 0;
}
