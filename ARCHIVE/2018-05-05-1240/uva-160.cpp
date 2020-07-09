#include <bits/stdc++.h>
using namespace std;

const int MAXN = 120;

int n;
bool not_prime[MAXN];
vector<int> primes;
vector<int> ans[MAXN];
vector<int> arr;

int main ()
{
	// Sieve
	not_prime[0] = not_prime[1] = true;
	for (int i = 2; i*i < MAXN; i++) {
		if (!not_prime[i])
			for (int j = i*i; j < MAXN; j+=i)
				not_prime[j] = true;
	}
	for (int i = 2; i < MAXN; i++)
		if (!not_prime[i])
			primes.push_back (i);
	/*for (int z : primes)
		printf ("%d ", z);
	putchar ('\n');*/
	for (int i = 0; i <= 100; i++) arr.push_back (-1);
	for (int i = 2; i <= 100; i++) {
		int x = i;
		int j = 0;
		while (x > 1) {
			// printf ("%d %d\n", i, x);
			while (x%primes[j] == 0) {
				if (arr[j] == -1)
					arr[j] = 0;
				arr[j]++;
				x /= primes[j];
			}
			j++;
		}
		ans[i] = arr;
	}
	while (scanf ("%d", &n), n) {
		printf ("%3d! =", n);
		for (int j = 0; ans[n][j] != -1; j++) {
			if (j == 15)
				printf ("\n      ");
			printf ("%3d", ans[n][j]);
		}
		putchar ('\n');
	}

	return 0;
}
