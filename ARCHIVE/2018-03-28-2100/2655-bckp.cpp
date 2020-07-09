#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
const int MAXN = 1e5+10, MAXQ = 1e3;


int arr[MAXN];
int sq[MAXQ][52];
std::set <int> aux;
int n, m, q;
int opt, x, y;
int i, j, k, mod, st, end_s;

int main ()
{
	scanf ("%d %d %d", &n, &q, &m);
	mod = sqrt (n);
	for (i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
		sq[i/mod][arr[i]]++;
	}
	for (k = 0; k < q; k++) {
		scanf ("%d %d %d", &opt, &x, &y);
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
				aux.insert (arr[i]);
			for (i = st; i <= end_s; i++)
				for (j = 1; j <= m; j++)
					if (sq[i][j])
						aux.insert (j);
			for (i = (end_s+1)*mod; i <= y; i++)
				aux.insert (arr[i]);
			printf ("%lu\n", aux.size ());
			aux.clear();
		}
		else {
			sq[x/mod][arr[x]]--;
			arr[x] = y;
			sq[x/mod][arr[x]]++;
		}
		/*for (i = 0; i < n; i++)
			printf ("%d ", arr[i]);
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
