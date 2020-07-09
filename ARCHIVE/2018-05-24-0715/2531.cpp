// Adapt Segment Tree Functions from Carlos Vinicius implementation
// to receive array and to have option for maximum and minimum query
//
// SINGLE UPDATES
// RANGE QUERIES

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e5+10;

void build (int t[], int opt, int a[], int v, int tl, int tr)
{
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build (t, opt, a, v*2, tl, tm);
		build (t, opt, a, v*2+1, tm+1, tr);
		if (opt)
			t[v] = max(t[v*2], t[v*2+1]);
		else
			t[v] = min(t[v*2], t[v*2+1]);
	}
}

// opt == 0 MIN
// opt == 1 MAX

int sum (int t[], int opt, int v, int tl, int tr, int l, int r)
{
	if (l > r) {
		if (opt)
			return 0;
		else
			return 1e9;
	}
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	if (opt)
		return max(	sum (t, opt, v*2, tl, tm, l, min(r, tm)),
				sum (t, opt, v*2+1, tm+1, tr, max (l, tm+1), r));
	else
		return min(	sum (t, opt, v*2, tl, tm, l, min(r, tm)),
				sum (t, opt, v*2+1, tm+1, tr, max (l, tm+1), r));
}

void update (int t[], int opt, int v, int tl, int tr, int pos, int new_val)
{
	if (tl == tr)
		t[v] = new_val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update (t, opt, v*2, tl, tm, pos, new_val);
		else
			update (t, opt, v*2+1, tm+1, tr, pos, new_val);
		if (opt)
			t[v] = max(	t[v*2],
						t[v*2+1]	);
		else
			t[v] = min(	t[v*2],
						t[v*2+1]	);
	}
}

int main ()
{
	int n, tMin[4*MAXN], tMax[4*MAXN];
	int a[MAXN];

	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < n; i++)
			scanf ("%d", &a[i]);
		for (int i = 0; i <= 4*n; i++)
			tMin[i] = tMax[i] = 0;

		build (tMin, 0, a, 1, 0, n-1);
		build (tMax, 1, a, 1, 0, n-1);

		int q, x, y, opt;
		scanf ("%d", &q);
		while (q--) {
			scanf ("%d %d %d", &opt, &x, &y);
			if (opt == 1) {
				update (tMin, 0, 1, 0, n-1, x-1, y);
				update (tMax, 1, 1, 0, n-1, x-1, y);
			}
			else
				printf ("%d\n", abs(sum (tMax, 1, 1, 0, n-1, x-1, y-1)-sum (tMin, 0, 1, 0, n-1, x-1, y-1)));
		}
	}

	return 0;
}
