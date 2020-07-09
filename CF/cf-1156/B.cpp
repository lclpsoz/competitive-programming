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

int t;
string s;
int a[105];
set<int> st;

int main () {
	cin >> t;
	while (t--) {
		memset (a, 0, sizeof a);
		cin >> s;
		st.clear();
// 		sort (s.begin(), s.end());
		for (int i = 0; i < len (s); i++) {
			a[s[i]-'a']++;
			st.insert (s[i]-'a');
		}
		if (len (st) > 1 and len (st) < 4) {
			vector<int> ax;
			for (int v : st)
				ax.push_back (v);
			bool ok = false;
			for (int i = 1; i < len (st); i++)
				if (ax[i]-ax[i-1] > 1) ok = true;
				
			if (!ok) {
				printf ("No answer\n");
				continue;
			} else if (ok and len (st) == 3) {
				int x = ax[0], y = ax[1], z = ax[2];
				if (y == z-1) swap (x, z);
				while (a[x]--) putchar (x+'a');
				while (a[z]--) putchar (z+'a');
				while (a[y]--) putchar (y+'a');
				putchar ('\n');
				continue;
			}
		} else if (len (st) == 4) {
			vector<int> ax;
			bool ok = false;
			for (int v : st)
				ax.push_back (v);
			int pos = -1;
			for (int i = 1; i < len (st); i++)
				if (ax[i]-ax[i-1] > 1) {
					ok = true;
					pos = i-1;
				}
			while (a[ax[2]]--)
				putchar (ax[2]+'a');
			while (a[ax[0]]--)
				putchar (ax[0]+'a');
			while (a[ax[3]]--)
				putchar (ax[3]+'a');
			while (a[ax[1]]--)
				putchar (ax[1]+'a');
			putchar ('\n');
			continue;
		}
		for (int i = 0; i < 30; i++)
			if (a[i] and i%2 == 0)
				while (a[i]--)
					putchar (i+'a');
		for (int i = 0; i < 30; i++)
			if (a[i] and i%2 == 1)
				while (a[i]--)
					putchar (i+'a');
		putchar ('\n');
	}

	return 0;
}
