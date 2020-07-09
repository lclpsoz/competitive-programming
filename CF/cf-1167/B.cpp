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

map<int, pair<int, int>> mp;
int a[] = {4, 8, 15, 16, 23, 42};
set<int> st;
int main () {
	for (int i = 0; i < 6; i++) {
		st.insert (a[i]);
		for (int j = i+1; j < 6; j++) {
			assert (mp.count (a[i]*a[j]) == 0);
			mp[a[i]*a[j]] = {a[i], a[j]};
		}
	}

	int ans[10];
	for (int i = 1; i < 5; i++) {
		cout << "? " <<  i << ' ' << i+1 << '\n';
		cout << flush;
		int x;
		cin >> x;
		if (i == 1) {
			ans[i] = mp[x].x;
			ans[i+1] = mp[x].y;
		} else {
			if (ans[i-1] == mp[x].x or ans[i-1] == mp[x].y)
				swap (ans[i-1], ans[i]);
			if (ans[i] == mp[x].x)
				ans[i+1] = mp[x].y;
			else
				ans[i+1] = mp[x].x;
		}
	}
	for (int i = 1; i <= 5; i++) st.erase (ans[i]);
	ans[6] = *st.begin();
	cout << "! ";
	for (int i = 1; i <= 6; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	cout << flush;

	return 0;
}
