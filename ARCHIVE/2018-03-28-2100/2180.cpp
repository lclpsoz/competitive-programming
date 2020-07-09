#include <bits/stdc++.h>
using namespace std;

const int MAXN = 61000, DIST = 6e7;

int i, j;
int n, ans;
bool not_prime[MAXN];

int main ()
{
	for (i = 2; i*i < MAXN; i++)
		if (!not_prime[i])
			for (j = i+i; j < MAXN; j+=i)
				not_prime[j] = true;
	scanf ("%d", &n);
	i = 0;
	j = n;
	while (i < 10) {
		if (!not_prime[j]) {
			ans += j;
			i++;
		}
		j++;
	}
	printf ("%d km/h\n", ans);
	int hrs, days;
	hrs = DIST/ans;
	days = hrs/24;
	printf ("%d h / %d d\n", hrs, days);

	return 0;
}
