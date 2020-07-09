#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

const int MAXN = 1e5+100, MAXQ = 1e3;

llu road[MAXN];
llu blocks[MAXQ][55]; //Position 0 are the monsters in binary
llu n, q, m, mod, monster, opt, x, y, aux;

int main ()
{
	scanf ("%llu %llu %llu", &n, &q, &m);
	mod = sqrt (n);
	for (int i = 0, blck_i = -1; i < n; i++) {
		scanf ("%llu", &monster);
		road[i] = monster;
		if ((i % mod) == 0)
			blck_i++;
		blocks[blck_i][monster]++;
		blocks[blck_i][0] |= 1LLU << monster;
	}
	for (int i = 0; i < q; i++) {
		scanf ("%llu %llu %llu", &opt, &x, &y);
		x--;
		if (opt == 2) {
			blocks[x/mod][road[x]]--;
			if (!blocks[x/mod][road[x]])
				blocks[x/mod][0] ^= 1LLU << road[x];
			road[x] = y;
			blocks[x/mod][road[x]]++;
			if (blocks[x/mod][road[x]] == 1)
				blocks[x/mod][0] |= 1LLU << road[x];
		}
		else {
			y--;
			aux = 0;
			while (x <= y && (x%mod) != 0)
				aux |= 1LLU << road[x++];
			while ((x+mod-1) <= y) {
				aux |= blocks[x/mod][0];
				x += mod;
			}
			while (x <= y)
				aux |= 1LLU << road[x++];
			printf ("%d\n", __builtin_popcountll(aux));
		}
		/*for (int j = 0; j < 5; j++)
			printf ("%llu ", road[j]);
		putchar('\n');
		for (int j = 0; j < mod; j++) {
			for (int k = 0; k < q; k++)
				printf ("%llu ", blocks[j][0] & (1LLU << k));
			putchar('\n');
		}*/
	}
	return 0;
}
