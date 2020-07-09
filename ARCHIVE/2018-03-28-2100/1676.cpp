#include <bits/stdc++.h>
using namespace std;

const int MAXN = 34000;

bool not_prime[MAXN];
int ans[3010];

int main ()
{
	for (int i = 2; i < MAXN/2; i++)
		if (!not_prime[i]) {
			int j = i;
			int k = 0;
			while (j < MAXN) {
				while (k < i && j < MAXN) {
					if (!not_prime[j])
						k++;
					j++;
				}
				while (j < MAXN && not_prime[j])
					j++;
				if (j < MAXN)
					not_prime[j] = true;
				k = 1;
			}
		}
	int i = 1;
	for (int j = 2; j < MAXN && i < 3010; j++)
		if (!not_prime[j])
			ans[i++] = j;

	int x;
	while (scanf ("%d", &x), x)
		printf ("%d\n", ans[x]);

	return 0;
}
