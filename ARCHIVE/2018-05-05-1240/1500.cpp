#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
const int INF = 1e9;

int tests;
int n, c;
long long t[4*MAXN];
long long lazy[4*MAXN];
int opt, p, q, v;

void push(int v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, long long  addend) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = t[v*2] + t[v*2+1];
    }
}

long long query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (tl == tr)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm)) +
               query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int main ()
{
	int a[MAXN];
	scanf ("%d", &tests);
	while (tests--) {
		scanf ("%d %d", &n, &c);
		for (int i = 0; i <= 4*n; i++) {
			t[i] = 0;
			lazy[i] = 0;
		}
		while (c--) {
			scanf ("%d", &opt);
			if (opt == 0) {
				scanf ("%d %d %d", &p, &q, &v);
				if (p > q) swap (p, q);
				update (1, 0, n-1, p-1, q-1, v);
			}
			else {
				scanf ("%d %d", &p, &q);
				if (p > q) swap (p, q);
				printf ("%lld\n", query (1, 0, n-1, p-1, q-1));
			}
		}
	}

	return 0;
}
