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
string l, r;
vector<pii> ans;
vector<int> esq[30], lExtra, rExtra;
vector<int> rCan, lCan;

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		if (l[i] == '?') lExtra.push_back (i + 1);
		else esq[l[i]-'a'].push_back (i + 1);
	for (int i = 0; i < n; i++)
		if (r[i] != '?') {
			if (len (esq[r[i]-'a']) > 0) {
				ans.push_back ({esq[r[i]-'a'].back(), i+1});
				esq[r[i]-'a'].pop_back ();
			}
			else rCan.push_back (i+1);
		} else
			rExtra.push_back (i+1);
// 	for (int v : lExtra)
// 		cout << v << '\n';
// 	for (int v : rExtra)
// 		cout << v << '\n';
	while (len (lExtra)) {
		if (len (rCan) == 0) break;
		int pos = lExtra.back();
		ans.push_back ({pos, rCan.back()});
		rCan.pop_back ();
		lExtra.pop_back ();
	}
	
	for (int i = 0; i < 30; i++)
		for (int p : esq[i])
			lCan.push_back (p);
	while (len (rExtra)) {
		if (len (lCan) == 0) break;
		ans.push_back ({lCan.back(), rExtra.back()});
// 		printf ("%d %d\n", ans.back().x, ans.back().y);
		lCan.pop_back ();
		rExtra.pop_back ();
	}
// 	printf ("--\n");
// 	for (int v : lExtra)
// 		cout << v << '\n';
// 	for (int v : rExtra)
// 		cout << v << '\n';
	
	while (len (lExtra)) {
		if (len (rExtra) == 0) break;
		ans.push_back ({lExtra.back(), rExtra.back()});
		lExtra.pop_back ();
		rExtra.pop_back ();
	}
	
	printf ("%d\n", len (ans));
	for (auto p : ans)
		printf ("%d %d\n", p.x, p.y);
		
		
	return 0;
}
