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

const int N = 4e5 + 10;

int n, m;
int k[N], total;
int ax[N];
bool ok[N];
bool maxiDeal[N];
vector<int> allDeals[N], deals[N];

bool eval (int days) {
	// printf ("DAYS = %d\n", days);
	int totalNow = total, freeDays = 0;
	for (int i = 0; i < n; i++)
		ax[i] = k[i], maxiDeal[i] = false;

	for (int i = days; i >= 0; i--) {
		deals[i].clear();
		for (int v : allDeals[i])
			if (!maxiDeal[v]) {
				maxiDeal[v] = true;
				deals[i].push_back (v);
			}
	}

	for (int i = 1; i <= days; i++) {
		freeDays++;
		for (int v : deals[i]) {
			// printf ("  deal = %d\n", v);
			while (freeDays and ax[v]) {
				ax[v]--;
				totalNow--;
				freeDays--;
			}
			if (!freeDays) break;
		}
		// if (days < 30)
		// 	printf ("  day = %d | freeDays = %d | totalNow = %d\n", i, freeDays, totalNow);
	}

	return 2*totalNow <= freeDays;
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &k[i]);
		total += k[i];
	}
	while (m--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		allDeals[x].push_back (y-1);
	}

	int l = 1, r = 4e5 + 10;
	while (l < r) {
		int md = (l+r)/2;
		if (eval (md))
			r = md;
		else
			l = md + 1;
	}
	printf ("%d\n", l);

	return 0;
}
