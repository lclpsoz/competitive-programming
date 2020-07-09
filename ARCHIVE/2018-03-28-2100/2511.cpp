#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+10;

int n;
bool qnt;
bool not_prime[MAXN];

int main ()
{
	not_prime[1] = true;
	for (int i = 2; i*i < MAXN; i++) {
	    if (!not_prime[i])
    		for (int j = i*i; j < MAXN; j+=i)
    			not_prime[j] = true;
	}

	int x;
	int i;
	while (scanf ("%d", &n) != EOF) {
		qnt = false;
		for (i = 0; i < n; i++) {
			scanf ("%d", &x);
			if (!not_prime[x]) {
				printf ("%d", x);
				qnt = true;
				break;
			}
		}
		i++;
		while (i < n) {
			scanf ("%d", &x);
			if (!not_prime[x])
				printf (" %d", x);
			i++;
		}

		if (!qnt)
			putchar ('*');
		putchar ('\n');
	}


	return 0;
}
