#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int t;
int n;
int arr1[MAXN];
int arr2[MAXN];
int ans;

int main ()
{
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf ("%d", &n);
		int j, k, l;
		for (j = 0, k = 0, l = 0; j < n; j++) {
			// printf ("%d\n", j);
			scanf ("%d", &arr1[k++]);
			j++;
			if (j < n) scanf ("%d", &arr2[l++]);
		}
		arr1[k] = arr2[l] = 2e9;
		// TLE NA QUESTAO PORQUE ESQUECI DE TIRAR ESSE FOR DE DEBUG!!!!
		for (int i = 0; i < (n)/2; i++)
		sort (arr1, arr1+((n+1)/2));
		sort (arr2, arr2+(n/2));
		putchar ('|');
		n++;
		n/=2;
		ans = -1;
		for (j = 0; j < n; j++) {
			// printf ("%d %d %d\n", arr1[j], arr2[j], arr1[j+1]);
			if (arr1[j] > arr2[j]) {
				ans = j<<1;
				break;
			}
			if (arr2[j] > arr1[j+1]) {
				ans = (j<<1)+1;
				break;
			}

		}


		printf ("Case #%d: ", i);
		if (ans == -1)
			printf ("OK\n");
		else
			printf ("%d\n", ans);
	}

	return 0;
}
