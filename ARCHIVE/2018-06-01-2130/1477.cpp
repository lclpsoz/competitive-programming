#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 1e6+10;

struct _node {
	int l, r;
	int val[3];
	int lazy;
} Node[4*MAXN];

void build (int v, int tl, int tr) {
	Node[v] = {tl, tr};
	Node[v].lazy = 0;
	if (tl == tr) {
		Node[v].val[0] = 1;
		for (int i = 1; i < 3; i++)
			Node[v].val[i] = 0;
	} else {
		int tm = (tl+tr)/2;
		build (2*v, tl, tm);
		build (2*v+1, tm+1, tr);
		for (int i = 0; i < 3; i++)
			Node[v].val[i] = Node[2*v].val[i] + Node[2*v+1].val[i];
	}
}

void transf (int a[], int qnt) {
	qnt %= 3;
	while (qnt--) {
		swap (a[0], a[1]);
		swap (a[0], a[2]);
	}
}

void update (int v) {
	transf (Node[v].val, Node[v].lazy);
	if (Node[v].l != Node[v].r) {
		Node[2*v].lazy += Node[v].lazy;
		Node[2*v+1].lazy += Node[v].lazy;
	}
	Node[v].lazy = 0;
}

void change (int v, int tl, int tr, int l, int r) {
	update (v);
	if (tl > r || tr < l) return;
	if (l <= tl && tr <= r) {
		Node[v].lazy++;
		update (v);
	} else if (r >= tl && tr >= l) {
		int tm = (tl+tr)/2;
		change (2*v, tl, tm, l, r);
		change (2*v+1, tm+1, tr, l, r);
		for (int i = 0; i < 3; i++)
			Node[v].val[i] = Node[2*v].val[i] + Node[2*v+1].val[i];
	}
}

void query (int a[], int v, int tl, int tr, int l, int r) {
	update (v);
	if (l <= tl && tr <= r) // Todo range incluso
		for (int i = 0; i < 3; i++)
			a[i] += Node[v].val[i];
	else if (r >= tl && tr >= l) { // Algum range incluso
		int tm = (tl+tr)/2;
		query (a, 2*v, tl, tm, l, r);
		query (a, 2*v+1, tm+1, tr, l, r);
		for (int i = 0; i < 3; i++)
			Node[v].val[i] = Node[2*v].val[i] + Node[2*v+1].val[i];
	}
}

int main ()
{
	int n, m, l, r;
	char c;
	int a[3];

	while (scanf ("%d %d", &n, &m) != EOF) {
		build (1, 1, n);
		while (m--) {
			scanf (" %c %d %d", &c, &l, &r);
			if (c == 'C') {
				a[0] = a[1] = a[2] = 0;
				query (a, 1, 1, n, l, r);
				printf ("%d %d %d\n", a[0], a[1], a[2]);
			} else
				change (1, 1, n, l, r);
		}
		putchar ('\n');
	}

	return 0;
}
