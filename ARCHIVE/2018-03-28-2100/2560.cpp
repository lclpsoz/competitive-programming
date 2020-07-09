#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1000;

long long n, b, ans, sum, mini, maxi, nova, velha;
long long i, j, k;
long long arr[MAXN], aux[110];

int main ()
{
	while (scanf ("%lld %lld", &n, &b) != EOF) {
		ans = sum = 0;
		maxi = 0;
		mini = 2000;
		for (i = 0; i < n; i++)
			scanf ("%lld", &arr[i]);
		for (i = 0; i < b; i++) {
			ans += arr[i];
			aux[arr[i]]++;
			maxi = max (maxi, arr[i]);
			mini = min (mini, arr[i]);
		}
		sum = ans;
		ans -= maxi+mini;
		//printf ("\nans: %lld\n", ans);
		for (i = 1; i <= n-b; i++) {
			//printf (" %lld\n", sum);
			velha = arr[i-1];
			nova = arr[i-1+b];
			sum -= velha;
			sum += nova;
			aux[velha]--;
			aux[nova]++;
			//printf (":::%lld %lld %lld %lld\n", arr[i-1+b], arr[i-1], aux[arr[i-1+b]], aux[arr[i-1]]);
			if (nova < mini)
				mini = nova;
			else if (mini == velha && !aux[velha])
				for (k = 0; k < 101 && mini == velha; k++)
					if (aux[k])
						mini = k;
			if (nova > maxi)
				maxi = nova;
			else if (maxi == velha && !aux[velha])
				for (k = 100; k > 0 && maxi == velha; k--)
					if (aux[k])
						maxi = k;
			//printf (">%lld %lld %lld\n", sum, maxi, mini);
			ans += sum-maxi-mini;
			//printf ("ans: %lld\n", ans);
		}
		printf ("%lld\n", ans);
		for (i = 0; i <= 101; i++)
			aux[i] = 0;
	}
	return 0;
}
