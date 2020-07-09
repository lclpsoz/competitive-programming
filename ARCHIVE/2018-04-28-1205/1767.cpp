#include <bits/stdc++.h>
using namespace std;

const int MAXN = 60;

int t, n, a, b;
int dp[MAXN];
int qnt[MAXN];
int brinq, w;

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		dp[0] = 0;
		qnt[0] = 0;
		for (int i = 1; i < MAXN; i++) {
			dp[i] = -1;
			qnt[i] = 0;
		}
		for (int ii = 0; ii < n; ii++) {
			scanf ("%d %d", &a, &b);
			for (int i = 50; i-b >= 0; i--)
				if (dp[i-b] > -1 && dp[i-b]+a > dp[i]) {
					dp[i] = dp[i-b]+a;
					qnt[i] = qnt[i-b]+1;
				}
		}

		brinq = 0;
		for (int i = 0; i <= 50; i++) {
			if (dp[i] > brinq) {
				brinq = dp[i];
				w = i;
			}
		}

		printf ("%d brinquedos\n", brinq);
		printf ("Peso: %d kg\n", w);
		printf ("sobra(m) %d pacote(s)\n", n-qnt[w]);
		putchar ('\n');
	}

	return 0;
}
