#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
const int MAXN = 1e5+10, MAXQ = 1e3;


long long road[MAXN];
long long sq[MAXQ][52];
long long sq_b[MAXQ], aux;
long long n, m, q;
long long opt, x, y;
long long i, j, k, mod, st, end_s;

int main ()
{
	scanf ("%lld %lld %lld", &n, &q, &m);
	mod = sqrt (n);
	for (i = 0; i < n; i++) {
		scanf ("%lld", &road[i]);
		sq[i/mod][road[i]]++;
		sq_b[i/mod] |= 1LL << road[i];
	}
	for (k = 0; k < q; k++) {
		scanf ("%lld %lld %lld", &opt, &x, &y);
		x--;
		if (opt == 1) {
			y--;
			st = x/mod;
			if (x%mod)
				st++;
			end_s = y/mod;
			if ((y%mod) != (mod-1))
				end_s--;
			for (i = x; i < st*mod; i++)
				aux |= 1LL << road[i];
			for (i = st; i <= end_s; i++)
				aux |= sq_b[i];
			for (i = (end_s+1)*mod; i <= y; i++)
				aux |= 1LL << road[i];
			printf ("%d\n", __builtin_popcountll(aux));
			aux = 0;
		}
		else {
			sq[x/mod][road[x]]--;
			if (!sq[x/mod][road[x]])
				sq_b[x/mod] ^= 1LL << road[x];
			road[x] = y;
			if (!sq[x/mod][road[x]])
				sq_b[x/mod] |= 1LL << road[x];
			sq[x/mod][road[x]]++;
		}
		/*for (i = 0; i < n; i++)
			printf ("%d ", road[i]);
		putchar ('\n');
		for (i = 0; i < mod; i++) {
			for (j = 1; j <= m; j++)
				printf ("%d ", sq[i][j]);
			putchar ('|');
		}
		putchar ('\n');*/
	}
	return 0;
}
