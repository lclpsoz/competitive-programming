#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n, k;
int x;
int arr[MAXN];
bool awake[MAXN];
int ans;

int main ()
{
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		if (x) awake[i] = true;
		if (awake[i]) {
			ans+=arr[i];
			arr[i] = 0;
		}
	}
	int aux = 0;
	for (int i = 0; i < k; i++)
		aux += arr[i];
	int maxi = aux;
	for (int i = 1; i < (n-k+1); i++) {
		aux -= arr[i-1];
		aux += arr[k+i-1];
		maxi = max (aux, maxi);
	}
	ans += maxi;
	printf ("%d\n", ans);

	return 0;
}
