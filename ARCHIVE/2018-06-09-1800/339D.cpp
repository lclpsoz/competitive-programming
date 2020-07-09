#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = (1<<17) + 100;

int n, q;
int seg[4*MAXN];
int arr[MAXN];

void build (int p, int l, int r, int lvl) {
	if (l == r)
		seg[p] = arr[l];
	else {
		int mid = (l+r)/2;
		build (2*p, l, mid, lvl-1);
		build (2*p+1, mid+1, r, lvl-1);

		if (lvl&1)
			seg[p] = seg[2*p]|seg[2*p+1];
		else
			seg[p] = seg[2*p]^seg[2*p+1];
	}
}

int query (int i, int p, int l, int r, int lvl) {
	if (l == r)
		seg[p] = arr[l];
	else {
		int mid = (l+r)/2;
		if (i <= mid)
			query (i, 2*p, l, mid, lvl-1);
		else
			query (i, 2*p+1, mid+1, r, lvl-1);

		if (lvl&1)
			seg[p] = seg[2*p]|seg[2*p+1];
		else
			seg[p] = seg[2*p]^seg[2*p+1];
	}

	return seg[p];
}

int main ()
{
	scanf ("%d %d", &n, &q);

	for (int i = 0; i < (1<<n); i++)
		scanf ("%d", &arr[i]);

	build (1, 0, (1<<n)-1, n);
	int p, v;
	for (int i = 0; i < q; i++) {
		scanf ("%d %d", &p ,&v);
		p--;
		arr[p] = v;
		printf ("%d\n", query (p, 1, 0, (1<<n)-1, n));
	}

	return 0;
}
