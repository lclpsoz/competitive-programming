#include<stdio.h>
#include<algorithm>
using namespace std;

const int V = 5e6 + 15, N = 5e4 + 15, LOGN = 16;

int n, m, nNow;
int bigPrime[V], a[N];
bool not_prime[V];
int sparse[LOGN][N];

void sieve () {
	bigPrime[1] = 1;
	for (int i = 2; i < V; i++)
		if (!not_prime[i])
			for (int j = i; j < V; j+=i) {
				not_prime[j] = true;
				bigPrime[j] = i;
			}
}

void buildSparse () {
	for (int i = 0; i < n; i++)
		sparse[0][i] = bigPrime[a[i]];
	for (int i = 1; i < LOGN; i++)
		for (int j = 0; j < n-((1<<i)-1); j++)
			sparse[i][j] = max (sparse[i-1][j], sparse[i-1][j+(1<<(i-1))]);
}

void fold () {
	if (nNow == 1) return;
	for (int i = 0; i < nNow/2; i++) {
		a[i] += a[nNow-1-i];
		a[nNow - 1 - i] = 0;
	}
	nNow = (nNow+1)/2;
// 	printf ("nNow: %d\n", nNow);
// 	for (int i = 0; i < nNow; i++)
// 		printf ("%d ", a[i]);
// 	putchar ('\n');
	buildSparse();
}

int qry (int l, int r) {
	int qnt = r - l + 1;
// 	printf ("%d\n", qnt);
	int p = 31 - __builtin_clz (qnt);
// 	printf ("%d %d\n", p, 1<<p);
	return max (sparse[p][l], sparse[p][l + (qnt - (1<<p))]);
}

int main () {
	sieve ();
	scanf ("%d %d", &n, &m);
	nNow = n;
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	buildSparse ();
	while (m--) {
		int opt, x, y;
		scanf ("%d", &opt);
		if (opt == 1)
			fold ();
		else {
			scanf ("%d %d", &x, &y);
			printf ("%d\n", qry (x-1, y-1));
		}
	}
	
	return 0;
}
