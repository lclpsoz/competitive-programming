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
set<pii> a;
deque<int> b;
vector<int> ax1, ax2;

int main () {
	scanf ("%d", &n);
	ll total = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		total += x;
		a.insert ({x, i});
		ax1.push_back (x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		total -= x;
		b.push_back (x);
		ax2.push_back (x);
	}
	sort (b.begin(), b.end());
	if (total) {
		printf ("NO\n");
		exit (0);
	} else {
		vector<pair<pii, int>> ans;
		while (len (a) > 1) {
			int mini = a.begin()->x;
			int miniPos = a.begin()->y;
			auto it = a.end();
			it--;
			int maxi = it->x;
			int maxiPos = it->y;

			int bMini = b.front();
			int bMaxi = b.back();
			// printf ("mini = %d, maxi = %d, bMini = %d, bMaxi = %d\n", mini, maxi, bMini, bMaxi);

			if (mini > bMini) {
				printf ("NO\n");
				exit (0);
			}
			else if (maxi < bMaxi) {
				printf ("NO  \n");
				exit (0);
			} else if (mini == bMini) {
				a.erase (a.begin());
				b.pop_front();
			} else if (maxi == bMaxi) {
				a.erase (it);
				b.pop_back ();
			} else {
				// printf ("here!\n");
				int d = min (bMini-mini, maxi-bMaxi);
				assert (2*d <= maxi - mini);
				a.erase (a.begin());
				a.erase (it);
				if (mini+d == bMini) {
					b.pop_front();
					a.insert ({maxi-d, maxiPos});
				}
				else {
					a.insert ({mini+d, miniPos});
					if (maxi-d == bMaxi)
						b.pop_back();
					else
						a.insert ({maxi-d, maxiPos});
				}

				ans.push_back ({{miniPos, maxiPos}, d});
			}
		}
		assert (len (a) == len (b));
		assert (!(len (a) == 1 and a.begin()->x != b.front()));
		if (len (a) > 1 or (len (a) == 1 and a.begin()->x != b.front())) {
			printf ("NO\n");
			exit (0);
		} else {
			printf ("YES\n");
			printf ("%d\n", len (ans));
			for (auto p : ans) {
				printf ("%d %d %d\n", p.x.x, p.x.y, p.y);
				ax1[p.x.x-1] += p.y;
				ax1[p.x.y-1] -= p.y;
			}
			sort (ax1.begin(), ax1.end());
			sort (ax2.begin(), ax2.end());
			for (int i = 0; i < len (ax1); i++)
				assert (ax1[i] == ax2[i]);
		}
	}

	return 0;
}