#include <bits/stdc++.h>
using namespace std;

const int MOD = 1300031;

int t;
int st, en, n;
int fatores[21];

int modul (long long a)
{
	if (a < 0)
		return MOD+a;
	if (!a)
		return 0;
	if (a % MOD == 0)
		return MOD;
	return a % MOD;
}

int modul (int a)
{
	if (a < 0)
		return MOD+a;
	if (!a)
		return 0;
	if (a % MOD == 0)
		return MOD;
	return a % MOD;
}

int mdc(int a, int b) {
    if(b == 0) return a;
    return mdc(b, a%b);
}
long long mmc (int a, int b) { return ((long long)a*b) / mdc(a, b); }

int sum_multi ()
{
	int r = 0;
	int c = 0;
	int maxi = 1<<n;
	long long m = 1;
	long long in, fin;
	while (c++, c < maxi) {
		m = 1;
		for (int i = 0; fatores[i]; i++)
			if (c & 1 << i) {
				m = mmc (m, fatores[i]);
				if (m > en)
					break;
			}
		if (m > en)
			continue;

		in = (st-1)/m;
		fin = en/m;
		in = (in*(in+1))/2;
		fin = (fin*(fin+1))/2;

		fin -= in;
		fin *= m;
		fin %= MOD;

		if (__builtin_popcount (c) & 1)
			r += fin;
		else
			r -= fin;
	}

	return modul(r);
}

int main ()
{
	scanf ("%d", &t);
	for (int l = 0; l < t; l++) {
		scanf ("%d %d %d", &st, &en, &n);
		int i = 0;
		for (; i < n; i++)
			scanf ("%d", &fatores[i]);
		fatores[i] = 0;
		printf ("%d\n", sum_multi ());
		// printf ("____________________________\n");
	}

	return 0;
}
