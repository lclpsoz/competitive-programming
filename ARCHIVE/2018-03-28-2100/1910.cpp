#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3128; // (1e5+100)/32 //

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int st, en, n, k, d, p;
int v[MAXN];
priority_queue<piii, vector<piii>, greater<piii>> pq;

void set_vert (int x)
{
	v[x/32] |= 1<<(x%32);
}

bool vert (int x)
{
	return v[(x/32)] & 1<<(x%32);
}

int dist (int x, int y)
{
	return x;
}

void ins (int x, int y, int z)
{
	pq.push ({{y, x}, z});
	set_vert(z);
}

int main ()
{
	while (scanf ("%d %d %d", &st, &en, &k), st || en || k) {
		//printf (">>>>%d %d %d\n", st, en, k);
		for (int i = 0; i < k; i++) {
			scanf ("%d", &n);
			set_vert(n);
		}

		pq.push ({{0, 0}, st});
		while (!pq.empty() && pq.top().second != en) {
			n = pq.top().second;
			d = pq.top().first.first+1;
			pq.pop();
			// printf ("%d\t[%d|%d]\n", n, d-1, pq.top().first.second);
			if (n > 1 && !vert(n-1))
				ins (dist (d, n-1), d, n-1);
			if (n < 1e5 && !vert(n+1))
				ins (dist (d, n+1), d, n+1);
			if (!(n&1) && (n/2 > 0) && !vert(n/2))
				ins (dist (d, n/2), d, n/2);
			if ((2*n) <= 1e5 && !vert(2*n))
				ins (dist (d, 2*n), d, 2*n);
			if ((3*n) <= 1e5 && !vert(3*n))
				ins (dist (d, 3*n), d, 3*n);
		}
		if (!pq.empty ())
			printf ("%d\n", pq.top().first.first);
		else
			printf ("-1\n");
		while (!pq.empty())
			pq.pop();

		for (int i = 0; i < MAXN; i++)
			v[i] = 0;
	}

	return 0;
}
