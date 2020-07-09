#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;
const int MAXN = 1e6+10;
const llu MOD = 1e9;

int i;
int n, aux;
llu ans;
int arr[MAXN];

int main ()
{
	ans = 1;
	arr[1] = 1;
	for (long long unsigned j = 2; j < MAXN; j++) {
		ans = ans * j;
		while (!(ans%10))
			ans /= 10;
		ans = ans%MOD;
		arr[j] = ans%10;
	}
	//for (i = 1; i < 300000; i++)
		//printf ("%d\n", arr[i]);
	while (scanf ("%d", &n) != EOF) {
		i++;
		printf ("Instancia %d\n", i);
		printf ("%d\n\n", arr[n]);
	}

	return 0;
}
