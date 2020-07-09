#include <cstdio>
using namespace std;

const int MAXN = 3126; // (1e5+32)/32

int ali[MAXN], bet[MAXN];

void set_ali (int x)
{
	ali[x/32] |= 1<<(x%32);
}

void set_bet (int x)
{
	bet[x/32] |= 1<<(x%32);
}

int main ()
{
	int a, b;
	int x;
	while (scanf ("%d %d", &a, &b), a || b) {
		while (a--) {
			scanf ("%d", &x);
			set_ali (x);
		}
		while (b--) {
			scanf ("%d", &x);
			set_bet (x);
		}
		a = b = 0;
		int aux;
		for (int i = 0; i < MAXN; i++) {
			if (ali[i] || bet[i]) {
				aux = ali[i] ^ bet[i];
				a += __builtin_popcount (ali[i]&aux);
				b += __builtin_popcount (bet[i]&aux);
				bet[i] = ali[i] = 0;
			}
		}
		printf ("%d\n", a > b ? b : a);
	}

	return 0;
}
