// Segment Tree in URI 1804, Mathematicians Needed in Mars (update value, to sum to it just use the previous value in a[])
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair<int, int> pii;

const int MAXN = 1e5+10;

int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main ()
{
	int a[MAXN];
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);

	build (a, 1, 0, n-1);

	/*int q, x, y;
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d %d", &x, &y);
		printf ("[%d, %d] -> %d\n", x, y, sum (1, 0, n-1, x, y));
	}*/

	char c;
	int x;
	while (scanf (" %c %d\n", &c, &x) != EOF) {
		if (c == 'a')
			update (1, 0, n-1, x-1, 0);
		else if (c == '?') {
			if (x == 1)
				printf("0\n");
			else
				printf ("%d\n", sum (1, 0, n-1, 0, x-2));
		}
	}


	return 0;
}
