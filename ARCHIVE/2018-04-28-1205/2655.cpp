// Adapted BIT for counting different numbers in range
// queries (update and amount of different numbers).
// URI 2655.
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n, q, m;
int mat[51][MAXN];
int arr[MAXN];

// Set number t in position
// k.
void add (int k, int t)
{
	for (; k <= n; k+=k&-k)
		mat[t][k]++;
}

// Change number in position
// k to t.
void upd (int k, int t)
{
	int ori = arr[k];
	arr[k] = t;
	for (; k <= n; k+=k&-k) {
		mat[ori][k]--;
		mat[t][k]++;
	}
}

// Get amount of each number
// in range [1, k]. Save it
// in array ar.
void get (int k, int *ar)
{
	for (; k>=1; k-=k&-k)
		for (int i = 1; i <= m; i++)
			ar[i] += mat[i][k];
}

int main ()
{
	int opt, x, y, s;
	int neg[55], pos[55];

	scanf ("%d %d %d", &n, &q, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &arr[i]);
		add (i, arr[i]);
	}

	while (q--) {
		scanf ("%d %d %d", &opt, &x, &y);
		if (opt == 1) {
			for (int i = 0; i <= m; i++)
				neg[i] = pos[i] = 0;
			s = 0;
			get (x-1, neg);
			get (y, pos);
			for (int i = 1; i <= m; i++)
				if (pos[i]-neg[i] > 0)
					s++;
			printf ("%d\n", s);
		}
		else
			upd (x, y);
	}

	return 0;
}
