#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 1e5+10;

pii tree[4*MAXN]; // {position, value}
int lazy[4*MAXN];

void build (int a[], int v, int tl, int tr) {
	lazy[v] = 0;
	if (tl == tr)
		tree[v] = {tl, a[tl]};
	else {
		int tm = (tl+tr)/2;
		build (a, 2*v, tl, tm);
		build (a, 2*v+1, tm+1, tr);
		if (tree[2*v].y >= tree[2*v+1].y)
			tree[v] = tree[2*v];
		else
			tree[v] = tree[2*v+1];
	}
}

void update (int v, int tl, int tr) {
	tree[v].y += lazy[v];
	if (tl != tr) {
		lazy[2*v] += lazy[v];
		lazy[2*v+1] += lazy[v];
	}
	lazy[v] = 0;
}

void add (int v, int tl, int tr, int l, int r, int val) {
	update (v, tl, tr);
	// printf ("%d %d %d\n", v, tl, tr);
	if (l > tr || r < tl) return; // Out of range
	if (l <= tl && tr <= r) {// All in range
		lazy[v] += val;
		update (v, tl, tr);
		return;
	}
	if (tl != tr) {
		// Part in range:
		int tm = (tl+tr)/2;
		add (2*v, tl, tm, l, r, val);
		add (2*v+1, tm+1, tr, l, r, val);
		if (tree[2*v].y >= tree[2*v+1].y)
			tree[v] = tree[2*v];
		else
			tree[v] = tree[2*v+1];
	}
}

pii query (int v, int tl, int tr, int l, int r) {
	update (v, tl, tr); // ???
	if (l > tr || r < tl) return {-INF, -INF}; // Out of range
	if (l <= tl && tr <= r) // All in rage
		return tree[v];
	// Part in rage:
	int tm = (tl+tr)/2;
	pii q1 = query (2*v, tl, tm, l, r);
	pii q2 = query (2*v+1, tm+1, tr, l, r);
	if (q1.y >= q2.y)
		return q1;
	else
		return q2;
}

int main ()
{
	int n, q;
	char c;
	int l, r, x;
	int a[MAXN];
	while (scanf ("%d %d", &n, &q) != EOF) {
		for (int i = 1; i <= n; i++)
			scanf ("%d", &a[i]);
		build (a, 1, 1, n);
		while (q--) {
			scanf (" %c %d %d", &c, &l, &r);
			// printf ("%c %d %d\n", c, l, r);
			if (c == 'C')
				printf ("%d\n", query (1, 1, n, l, r).x);
			else {
				scanf ("%d", &x);
				add (1, 1, n, l, r, x);
			}
		}
	}

	return 0;
}
