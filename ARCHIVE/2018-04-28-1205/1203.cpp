#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXK = 1e4+10;
int r, k;
int a, b;
int qnt[MAXN];
bool dp[MAXK];

int main ()
{
	while (scanf ("%d %d", &r, &k) != EOF) {

		for (int i = 0; i < k; i++) {
			scanf ("%d %d", &a, &b);
			qnt[a]++;
			qnt[b]++;
		}

		dp[0] = true;
		for (int i = 1; i <= k; i++) dp[i] = false;
		for (int i = 1; i <= r; i++) {
			for (int j = k; j-qnt[i] >= 0; j--)
				if (dp[j-qnt[i]]) dp[j] = true;
			/*for (int j = 0; j <= k; j++)
				printf ("%d ", dp[j]);
			putchar ('\n');*/
			qnt[i] = 0;
		}

		printf ("%c\n", dp[k] ? 'S' : 'N');
	}

	return 0;
}
